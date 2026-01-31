//Use two unnamed semaphores to enforce alternation between parent and child for 10 iterations.
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/wait.h>

int main() {
    sem_t *sem_parent = mmap(NULL, sizeof(sem_t),
                             PROT_READ | PROT_WRITE,
                             MAP_SHARED | MAP_ANONYMOUS,
                             -1, 0);

    sem_t *sem_child = mmap(NULL, sizeof(sem_t),
                            PROT_READ | PROT_WRITE,
                            MAP_SHARED | MAP_ANONYMOUS,
                            -1, 0);

    sem_init(sem_parent, 1, 1);  // Parent starts first
    sem_init(sem_child, 1, 0);   // Child waits initially

    if (fork() == 0) {
        // Child process
        for (int i = 1; i <= 10; i++) {
            sem_wait(sem_child);
            printf("Child: %d\n", i);
            sem_post(sem_parent);
        }
        return 0;
    }

    // Parent process
    for (int i = 1; i <= 10; i++) {
        sem_wait(sem_parent);
        printf("Parent: %d\n", i);
        sem_post(sem_child);
    }

    wait(NULL);
    return 0;
}
//Terminal Section
/*
Execution Commands:
gcc Q4.c -o Q4 -pthread
./Q4
Output:
Parent: 1
Child: 1
Parent: 2
Child: 2
Parent: 3
Child: 3
Parent: 4
Child: 4
Parent: 5
Child: 5
Parent: 6
Child: 6
Parent: 7
Child: 7
Parent: 8
Child: 8
Parent: 9
Child: 9
Parent: 10
Child: 10
*/
