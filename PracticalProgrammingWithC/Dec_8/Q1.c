// Unnamed Semaphore with fork()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>

int main()
{
    sem_t *sem = mmap(NULL, sizeof(sem_t),
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED | MAP_ANONYMOUS,
                      -1, 0);

    sem_init(sem, 1, 1); // binary semaphore

    pid_t pid = fork();

    if (pid == 0) {
        // Child
        for (int i = 0; i < 5; i++) {
            sem_wait(sem);
            printf("Child in critical section: %d\n", i);
            sleep(1);
            sem_post(sem);
            sleep(1);
        }
    } else {
        // Parent
        for (int i = 0; i < 5; i++) {
            sem_wait(sem);
            printf("Parent in critical section: %d\n", i);
            sleep(1);
            sem_post(sem);
            sleep(1);
        }
    }

    return 0;
}

//Terminal Section
/*
Execution Commands:
gcc Q1.c -o Q1 -pthread
./Q1
Output:
Parent in critical section: 0
Child in critical section: 0
Parent in critical section: 1
Child in critical section: 1
Parent in critical section: 2
Child in critical section: 2
Parent in critical section: 3
Child in critical section: 3
Parent in critical section: 4
Child in critical section: 4
*/
