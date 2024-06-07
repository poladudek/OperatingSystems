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

int switchingLeaders()
{
    
    for (int i = 0; i< 3; i++)
    {
        switch(fork())
        {
            case -1:
                perror("error with fork()");
                exit(EXIT_FAILURE);
            
            case 0:
                
                if (setpgid(0, 0) == (-1)) // current process will become the leader of its group
                {
                    perror("error with setpgid()");
                    exit(EXIT_FAILURE);
                }
                printingInfo();
                break;
            
            default:
                if (wait(NULL) == (-1))
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
    
    printingInfo();
    switchingLeaders();

    exit(EXIT_SUCCESS);
}
