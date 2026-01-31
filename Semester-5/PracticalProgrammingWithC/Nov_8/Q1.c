#include <stdio.h>
#include <unistd.h>
int main(void)
{
pid_t p=fork();
if(p==0){
printf("C1 PID %d : PPID %d \n",getpid(),getppid());
pid_t c11=fork();
if(c11==0)
{
printf("C11 PID %d : PPID %d \n",getpid(),getppid());
}
else{ 
    wait(NULL);
}
}
else{
pid_t c2=fork();
if(c2==0){
printf("C2 PID %d : PPID %d \n",getpid(),getppid());
pid_t c21=fork();
if(c21==0)
{
printf("C21 PID %d : PPID %d \n",getpid(),getppid());
}
else{ 
    wait(NULL);
}
pid_t c22=fork();
if(c22==0)
{
   printf("C22 PID %d : PPID %d \n",getpid(),getppid()); 
}
else{ 
    wait(NULL);
}
}
printf("P PID %d : PPID %d \n",getpid(),getppid());
wait(NULL);
}
return 0;
}
/*
p>c1,p>c2
c1>c11,c2>c21,c2>c22
*/
