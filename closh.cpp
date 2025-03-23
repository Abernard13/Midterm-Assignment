#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>

void closh() {
    while (true) {
        std::string command, mode;
        int count;

        std::cout << "closh> ";
        std::cin >> command;
        std::cout << "count> ";
        std::cin >> count;
        std::cout << "[p]arallel or [s]equential> ";
        std::cin >> mode;

        for (int i = 0; i < count; i++) {
            pid_t pid = fork();
            if (pid == 0) {
                execlp(command.c_str(), command.c_str(), NULL);
                perror("execlp");
                exit(1);
            } else if (pid > 0 && mode == "s") {
                wait(NULL);
            }
        }
        if (mode == "p") {
            while (wait(NULL) > 0);
        }
    }
}

int main() {
    closh();
    return 0;
}




