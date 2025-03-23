#include <iostream>
#include <unistd.h>

void hello_goodbye() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        std::cout << "hello\n";
        exit(0);
    } else {
        usleep(10000); // Small delay to ensure child executes first
        std::cout << "goodbye\n";
    }
}

int main() {
    hello_goodbye();
    return 0;
}
