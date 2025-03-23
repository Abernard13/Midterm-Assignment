#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

using namespace std;

int main() {
    string command;
    int count;
    char mode;

    while (true) {
        cout << "closh> ";
        cin >> command;
        cout << "count> ";
        cin >> count;
        cout << "[p]arallel or [s]equential> ";
        cin >> mode;

        vector<pid_t> pids;

        for (int i = 0; i < count; i++) {
            pid_t pid = fork();
            if (pid == 0) {
                execl(command.c_str(), command.c_str(), NULL);
                perror("execl");  // If execl fails
                exit(1);
            } else if (pid > 0) {
                pids.push_back(pid);
                if (mode == 's') waitpid(pid, NULL, 0);
            }
        }

        if (mode == 'p') {
            for (pid_t pid : pids) waitpid(pid, NULL, 0);
        }
    }

    return 0;
}
