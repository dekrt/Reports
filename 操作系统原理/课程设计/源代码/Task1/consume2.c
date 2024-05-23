// Include necessary libraries
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

// Define a buffer with size 64
char buffer[64];

// Define the path to the device
#define DEV_PATH "/dev/my_dev"

// Main function
int main()
{
    // Open the device with read and write permissions
    int fd = open(DEV_PATH, O_RDWR);

    // If the device fails to open, print an error message and return -1
    if (fd < 0)
    {
        printf("open %s failded\n", DEV_PATH);
        return -1;
    }

    // Get the process ID
    pid_t pid = getpid();

    // Infinite loop
    while (1)
    {
        // Generate a random number between 5 and 12
        int Num = rand() % 8 + 5;

        // Print the process ID, the number of characters requested to read, and the actual number of characters read
        printf("consume2 pid = %d 申请读出%d字符, 实际读出%ld字符\n", pid, Num, read(fd, buffer, Num));

        // Sleep for 1 second
        sleep(1);
    }

    // Close the device
    close(fd);

    // Return 0 to indicate successful execution
    return 0;
}
