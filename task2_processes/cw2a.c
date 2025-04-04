#include "header_2a.h"


void print_info()
{   
    printf("I'm a child process:\n");
    int my_pid = getpid(); 
    int my_uid = getuid(); 
    int my_gid = getgid(); 
    int my_ppid = getppid();
    int my_pgid = getpgid(my_pid);
    
    printf("PID: %d\t UID: %d\t GID: %d\t PPID: %d\t PGID: %d\n", my_pid, my_uid, my_gid, my_ppid, my_pgid);
}

int main(void)
{
    print_info(); 
    return 0;
}
