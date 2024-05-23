#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1024 * 1024 * 100  // 100MB

int main() {
    char *buffer;

    // 分配内存
    buffer = (char *)malloc(SIZE);
    if (!buffer) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Memory allocated. Sleeping...\n");

    // 暂停一段时间
    sleep(10);

    // 释放内存
    free(buffer);

    printf("Memory freed. Exiting...\n");

    return 0;
}