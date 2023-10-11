#include <stdio.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

int main()
{
    int nRet;
    nRet = syscall(548, 20, 18);
    printf("%d\n", nRet);
    nRet = syscall(549, 20, 18, 4);
    printf("%d\n", nRet);
    return 0;
}
