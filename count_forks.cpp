#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstdlib>

// Program 4: Forking twice and counting child processes
void count_forks() {
    fork();
    fork();
    exit(0);
}
// This creates **3 child processes** (total 4 processes including the parent).
