// Devlope a C program to implement system calls in Linux as follows:

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid = fork(); // Create a new process
    if(pid<0){
        printf("Fork FAiled\n");
        return -1;

    }elseif(pid==0){
        //child process
        printf("Child Process\n");
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
        printf("Child Process ID: %d\n", pid);
        printf("Child: Executing ls command using execlp()\n");

        execlp("/bin/ls","ls",NULL); // Execute ls command

        // If execlp fails
        perror("execlp failed");
        exit(1);

    }else{
        // parent process
        printf("Parent: Waiting for child to complete\n");
        wait(NULL); // parent will wait for the child to complete

        printf("Parent: Child Complete\n");
        printf("Parent: pid value = %d\n", pid);
        printf("Parent: Process id = %d\n", getpid());
        printf("Parent: Child-Process id = %d\n", pid);
    }
    return 0;
}