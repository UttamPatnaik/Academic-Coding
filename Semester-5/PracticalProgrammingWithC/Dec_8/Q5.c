//Write a C program that demonstrates inter-process synchronization using an unnamed semaphore shared via mmap().
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int N = 5;   // number of child processes
    int loops = 3; // number of times each process enters CS

    // Create shared unnamed semaphore using mmap()
    sem_t *sem = mmap(NULL, sizeof(sem_t),
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED | MAP_ANONYMOUS,
                      -1, 0);

    if (sem == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    // Initialize binary semaphore (1 = unlocked)
    sem_init(sem, 1, 1);

    // Create N child processes
    for (int p = 0; p < N; p++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process

            for (int i = 0; i < loops; i++) {
                sem_wait(sem);  // enter critical section

                printf("Process %d (PID %d) in critical section (iteration %d)\n",
                       p + 1, getpid(), i + 1);

                usleep(200000); // simulate work (0.2 sec)

                sem_post(sem);  // exit critical section

                usleep(100000); // outside critical section
            }

            return 0; // child exits
        }
    }

    // Parent waits for all children
    while (wait(NULL) > 0);

    printf("\nAll processes finished.\n");

    return 0;
}
//Terminal Section
/*
Execution Commands:
gcc Q5.c -o Q5 -pthread
./Q5
Output:
Process 1 (PID 6475) in critical section (iteration 1)
Process 2 (PID 6476) in critical section (iteration 1)
Process 3 (PID 6477) in critical section (iteration 1)
Process 4 (PID 6478) in critical section (iteration 1)
Process 5 (PID 6479) in critical section (iteration 1)
Process 1 (PID 6475) in critical section (iteration 2)
Process 2 (PID 6476) in critical section (iteration 2)
Process 3 (PID 6477) in critical section (iteration 2)
Process 4 (PID 6478) in critical section (iteration 2)
Process 5 (PID 6479) in critical section (iteration 2)
Process 1 (PID 6475) in critical section (iteration 3)
Process 2 (PID 6476) in critical section (iteration 3)
Process 3 (PID 6477) in critical section (iteration 3)
Process 4 (PID 6478) in critical section (iteration 3)
Process 5 (PID 6479) in critical section (iteration 3)

All processes finished.
*/
