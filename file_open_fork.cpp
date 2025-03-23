#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <cstdlib>

void file_open_fork() {
    int fd = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        write(fd, "Child process writing.\n", 23);
        close(fd);
    } else {
        write(fd, "Parent process writing.\n", 24);
        close(fd);
    }
}

int main() {
    file_open_fork();
    return 0;
}
