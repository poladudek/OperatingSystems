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

int groupGenerations()
{
    int counting_children = 0; 
    for (int i = 0; i < 3; i++) 
    {
        switch (fork())
        {
            case -1:
                perror("error with fork()");
                exit(EXIT_FAILURE);
            
            case 0:
                printingInfo(); 
                sleep(1); 
                printf("\n");
                break;
            
            default:
                counting_children++;
                break;
        }
    }

    while (counting_children > 0) // makes sure parent process won't end before all its' children while using only sleep() function.
    {
        sleep(2);
        counting_children--;
    }
    
    return 0;
}

int main()
{
    printingInfo();
    sleep(1); // will separate each generation
    printf("\n");
    groupGenerations();
    
    exit(EXIT_SUCCESS);
}
