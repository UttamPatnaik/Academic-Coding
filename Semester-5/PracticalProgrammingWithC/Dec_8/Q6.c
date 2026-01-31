//Write a C program that demonstrates inter-process synchronization using an unnamed semaphore shared via mmap().
//This is the teacher's version of Q5
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <stdlib.h>

#define N 5     // number of child processes

int main() {

    // Create shared unnamed semaphore using mmap()
    sem_t *sem = mmap(NULL, sizeof(sem_t),
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED | MAP_ANONYMOUS,
                      -1, 0);

    // Initialize binary semaphore (1 = unlocked)
    sem_init(sem, 1, 1);

    // Create N child processes
    for (int p = 0; p < N; p++) {

        if (fork() == 0) {     // Child process

            for (int i = 1; i <= 3; i++) {
                sem_wait(sem);  // enter critical section

                printf("Process %d (PID %d) in critical section (iteration %d)\n",
                       p, getpid(), i);

                sleep(1);       // simulate work

                sem_post(sem); // exit critical section

                sleep(1);      // outside critical section
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
Process 0 (PID 6654) in critical section (iteration 1)
Process 1 (PID 6655) in critical section (iteration 1)
Process 2 (PID 6656) in critical section (iteration 1)
Process 3 (PID 6657) in critical section (iteration 1)
Process 4 (PID 6658) in critical section (iteration 1)
Process 0 (PID 6654) in critical section (iteration 2)
Process 1 (PID 6655) in critical section (iteration 2)
Process 2 (PID 6656) in critical section (iteration 2)
Process 3 (PID 6657) in critical section (iteration 2)
Process 4 (PID 6658) in critical section (iteration 2)
Process 0 (PID 6654) in critical section (iteration 3)
Process 1 (PID 6655) in critical section (iteration 3)
Process 2 (PID 6656) in critical section (iteration 3)
Process 3 (PID 6657) in critical section (iteration 3)
Process 4 (PID 6658) in critical section (iteration 3)

All processes finished.
*/
