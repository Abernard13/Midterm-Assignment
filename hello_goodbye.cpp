#include <iostream>
#include <unistd.h>

int main() {
    if (fork() == 0) {  // Child process
        printf("hello\n");
    } else {  // Parent process
        sleep(1);  // Small delay to ensure child prints first
        printf("goodbye\n");
    }
    return 0;
}
