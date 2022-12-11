#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Create some child processes
    for (int i = 0; i < 5; i++) {
        if (fork() == 0) {
            printf("Child %d started\n", i);
            sleep(1); // Do some work
            printf("Child %d finished\n", i);
            exit(0);
        }
    }

    // Wait for all child processes to finish
    while (wait(NULL) > 0) {}

    printf("All children finished.\n");
    return 0;
}
