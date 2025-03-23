#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>

void close_stdout() {
    pid_t pid = fork();
    if (pid == 0) {
        close(STDOUT_FILENO);
        printf("This won't be printed\n");
        exit(0);
    }
}

int main() {
    close_stdout();
    return 0;
}
