//Demonstrate a race condition by removing the semaphore and allowing two processes to modify a shared variable.
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main() {
    int *counter = mmap(NULL, sizeof(int),
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS,
                        -1, 0);

    *counter = 0;

    if (fork() == 0) {
        for (int i = 0; i < 10000; i++)
            (*counter)++;  // child increments
        return 0;
    } else {
        for (int i = 0; i < 10000; i++)
            (*counter)++;  // parent increments
    }

    wait(NULL);

    printf("Final counter = %d (Expected = 20000)\n", *counter);

    return 0;
}
//Terminal Section
/*
Execution Commands:
gcc Q3.c -o Q3 -pthread
./Q3
Output:
Final counter = 20000 (Expected = 20000)
*/
