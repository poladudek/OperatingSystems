#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void printingInfo()
{ 
    int my_pid = getpid();
    int my_uid = getuid();
    int my_gid = getgid();
    int my_ppid = getppid();
    int my_pgid = getpgid(my_pid);
    
    printf("PID: %d\t UID: %d\t GID: %d\t PPID: %d\t PGID: %d\n", my_pid, my_uid, my_gid, my_ppid, my_pgid);
}

int creatingOrphans()
{ 
    int counting_generations = 0;
    for (int i = 0; i < 3; i++)
    {
        switch(fork())
        {
            case -1:
                perror("error with fork()");
                exit(EXIT_FAILURE);
            
            case 0:
                sleep(2); // child process sleeps for 2 seconds
                printingInfo();
                counting_generations++;
                break;
            
            default:
                sleep(0); // parent process sleeps for only smallest CPU unit
                break;
                
        }
    }

    if (counting_generations == 3) // after reaching 3 generations information will be printed
    {
        printf("All child processes have been taken over by init or a related process.\n");

        // Important: This information is meant to signal the end of the program because the shell name will be
        // written at the moment of the parent's death (at the very beginning) and will not properly indicate "the end."

    }
    
    return 0;
}

int main() 
{   

    printingInfo(); 
    creatingOrphans();
    
    exit(EXIT_SUCCESS);
}


