#include <iostream>
#include <unistd.h>
#include <cstdlib>

void count_forks() {
    fork();
    fork();
    exit(0);
}

int main() {
    count_forks();
    return 0;
}
