//Write a C program using an unnamed semaphore to safely increment a shared counter using two child processes.
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/wait.h>

int main() {
    int *counter = mmap(NULL, sizeof(int),
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS,
                        -1, 0);

    sem_t *sem = mmap(NULL, sizeof(sem_t),
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED | MAP_ANONYMOUS,
                      -1, 0);

    *counter = 0;
    sem_init(sem, 1, 1);

    for (int p = 0; p < 2; p++) {
        if (fork() == 0) {
            for (int i = 0; i < 10; i++) {
                sem_wait(sem);
                (*counter)++;
                printf("Process %d incremented counter to %d\n",
                       p + 1, *counter);
                sem_post(sem);
                usleep(100000);
            }
            return 0;
        }
    }

    while (wait(NULL) > 0);
    printf("Final Counter = %d\n", *counter);

    return 0;
}
//Terminal Section
/*
Execution Commands:
gcc Q2.c -o Q2 -pthread
./Q2
Output:
Process 1 incremented counter to 1
Process 2 incremented counter to 2
Process 1 incremented counter to 3
Process 2 incremented counter to 4
Process 1 incremented counter to 5
Process 2 incremented counter to 6
Process 1 incremented counter to 7
Process 2 incremented counter to 8
Process 1 incremented counter to 9
Process 2 incremented counter to 10
Process 1 incremented counter to 11
Process 2 incremented counter to 12
Process 1 incremented counter to 13
Process 2 incremented counter to 14
Process 1 incremented counter to 15
Process 2 incremented counter to 16
Process 1 incremented counter to 17
Process 2 incremented counter to 18
Process 1 incremented counter to 19
Process 2 incremented counter to 20
Final Counter = 20
*/
