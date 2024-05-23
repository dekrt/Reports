// Included necessary headers
#include <linux/miscdevice.h>
#include <linux/kfifo.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/mutex.h>
#include <linux/module.h>

#define DEV_NAME "my_dev" // Device name
#define BUFFER_SIZE 32    // Size of the FIFO buffer

// Define a kernel FIFO and a mutex for synchronization
DEFINE_KFIFO(FIFOBuffer, char, BUFFER_SIZE);
struct mutex Mutex;

// Device related variables
static struct device *my_miscdevice;
wait_queue_head_t read_queue;  // For blocking reads when FIFO is empty
wait_queue_head_t write_queue; // For blocking writes when FIFO is full

void print_fifo(void)
{
    char buf[BUFFER_SIZE];
    unsigned int copied;

    mutex_lock(&Mutex);
    copied = kfifo_out_peek(&FIFOBuffer, buf, BUFFER_SIZE);
    mutex_unlock(&Mutex);

    buf[copied] = '\0'; // Null-terminate the string
    printk(KERN_INFO "my_dev: KFIFO content: %s\n", buf);
}

// Device open function
static int my_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "my_dev: Device opened\n");
    print_fifo();
    return 0;
}

// Device release function
static int my_release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "my_dev: Device released\n");
    return 0;
}

// Device read function
static ssize_t my_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    int read = 0, ret = 0;

    // If FIFO is empty, block the read process until there's data
    if (kfifo_is_empty(&FIFOBuffer))
    {
        if (file->f_flags & O_NONBLOCK)
            return 0;
        printk(KERN_INFO "my_dev: Read process is blocked, needs space: %zu, available space: %u\n", 
               count, kfifo_len(&FIFOBuffer));
        wait_event_interruptible(read_queue, !kfifo_is_empty(&FIFOBuffer));
    }

    // Lock the FIFO, read from it and then unlock
    mutex_lock(&Mutex);
    ret = kfifo_to_user(&FIFOBuffer, buf, count, &read);
    mutex_unlock(&Mutex);

    // If FIFO is not full, wake up any blocked write process
    if (!kfifo_is_full(&FIFOBuffer))
    {
        printk(KERN_INFO "my_dev: Wake up write process\n");
        wake_up_interruptible(&write_queue);
    }

    print_fifo();

    return read;
}

// Device write function
static ssize_t my_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    int write = 0, ret = 0;

    // If FIFO is full, block the write process until there's space
    if (kfifo_is_full(&FIFOBuffer))
    {
        if (file->f_flags & O_NONBLOCK)
            return 0;
                printk(KERN_INFO "my_dev: Write process is blocked, needs space: %zu, available space: %u\n", 
               count, BUFFER_SIZE - kfifo_len(&FIFOBuffer));
        wait_event_interruptible(write_queue, !kfifo_is_full(&FIFOBuffer));
    }

    // Lock the FIFO, write to it and then unlock
    mutex_lock(&Mutex);
    ret = kfifo_from_user(&FIFOBuffer, buf, count, &write);
    mutex_unlock(&Mutex);

    // If FIFO is not empty, wake up any blocked read process
    if (!kfifo_is_empty(&FIFOBuffer))
    {
        printk(KERN_INFO "my_dev: Wake up read process\n");
        wake_up_interruptible(&read_queue);
    }

    print_fifo();

    return write;
}

// File operations structure
static const struct file_operations DevFops = {
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
    .read = my_read,
    .write = my_write,
};

// Misc device structure
static struct miscdevice miscDeviceFIFOBlock = {
    .minor = MISC_DYNAMIC_MINOR, // Dynamic minor number
    .name = DEV_NAME,            // Device name
    .fops = &DevFops,            // File operations structure
};

// Module initialization function
static int __init DevInit(void)
{
    // Register the misc device
    int ret = misc_register(&miscDeviceFIFOBlock);
    if (ret < 0)
    {
        printk(KERN_ERR "my_dev: Failed to init\n");
        return ret;
    }

    // Initialize the mutex
    mutex_init(&Mutex);

    // Set the device
    my_miscdevice = miscDeviceFIFOBlock.this_device;

    // Initialize the wait queues for read and write
    init_waitqueue_head(&read_queue);
    init_waitqueue_head(&write_queue);

    printk(KERN_INFO "my_dev: Init successfully\n");
    return ret;
}

// Module exit function
static void __exit DevExit(void)
{
    // Unregister the misc device
    misc_deregister(&miscDeviceFIFOBlock);
    printk(KERN_INFO "my_dev: Exited\n");
}

// Specify the init and exit functions
module_init(DevInit);
module_exit(DevExit);

// Module metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("dekrt");
MODULE_DESCRIPTION("A simple driver for testing KFIFO");

