#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t p=fork();
    if(p==0)
    {
        printf("C1 PID: %d, PPID: %d\n",getpid(),getppid());
        pid_t c1=fork();
        if(c1==0)
        {
            printf("C11 PID: %d, PPID: %d\n",getpid(),getppid());
            pid_t c11=fork();
            if(c11==0)
            {
                printf("C11 PID: %d, PPID: %d\n",getpid(),getppid());
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        wait(NULL);
        printf("P PID: %d, PPID: %d\n",getpid(),getppid());
    }
    return 0;
}
