#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void printingInfo()
{
    int my_pid = getpid(); 
    int my_uid = getuid(); 
    int my_gid = getgid(); 
    int my_ppid = getppid();
    int my_pgid = getpgid(my_pid);
    
    printf("PID: %d\t UID: %d\t GID: %d\t PPID: %d\t PGID: %d\n", my_pid, my_uid, my_gid, my_ppid, my_pgid);

}

int main()
{

    printingInfo();
   
    exit(EXIT_SUCCESS);
}

