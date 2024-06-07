#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void printigInfo()
{
    int my_pid = getpid(); 
    int my_uid = getuid(); 
    int my_gid = getgid(); 
    int my_ppid = getppid();
    int my_pgid = getpgid(my_pid);
    
    printf("PID: %d\t UID: %d\t GID: %d\t PPID: %d\t PGID: %d\n", my_pid, my_uid, my_gid, my_ppid, my_pgid);
}

int forkingWithWait()
{
    
    for(int i = 0; i < 3; i++)
    {
    
        switch(fork())
        {
            case -1:
                perror("error with fork()");
                exit(EXIT_FAILURE);
        
            case 0:
            
                printingInfo();
                break;

            default:
                if (wait(NULL) == (-1)) // parent process waits for all child processes
                {   
                    perror("error with wait()");
                    exit(EXIT_FAILURE);
                }
                break;

        }
    }

    return 0;
}

int main()
{

    printigInfo(); // will print information about parent process
    forkingWithWait(); // will fork and print information about child processes

    exit(EXIT_SUCCESS);
}

