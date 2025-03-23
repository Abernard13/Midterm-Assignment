#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstdlib>

// Program 3: Closing STDOUT in child process
void close_stdout() {
    pid_t pid = fork();
    if (pid == 0) {
        close(STDOUT_FILENO);
        printf("This won't be printed\n");
        exit(0);
    }
    wait(NULL);
}
