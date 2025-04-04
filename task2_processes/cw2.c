#include "header_2.h"


int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("Incorrect program argument input\n The program should be run in the format -> ./[executable_file_name_cw2] [executable_file_name_cw2a]\n");
        exit(EXIT_FAILURE);
    }
    
    char *sub_program = argv[1]; 

    printf("I'm the main process:\n");
    int parent_pid = getpid(); 
    int parent_uid = getuid(); 
    int parent_gid = getgid(); 
    int parent_ppid = getppid();
    int parent_pgid = getpgid(parent_pid);
    
    printf("PID: %d\t UID: %d\t GID: %d\t PPID: %d\t PGID: %d\n", parent_pid, parent_uid, parent_gid, parent_ppid, parent_pgid);

    for (int i = 0; i < 3; i++)
    {
        switch (fork())
        {
            case -1:
                perror("fork() failed");
                exit(EXIT_FAILURE);
            
            case 0:
                if (execlp(sub_program, sub_program, NULL) == (-1)) //using execlp() to open subprogram
                {
                    perror("execlp() failed");
                    exit(EXIT_FAILURE);
                }     
                break;
                
            default:
                if (wait(NULL) == (-1))
                {
                    perror("wait() failed");
                    exit(EXIT_FAILURE);
                }
                break;
        }
    }
    
    return 0;
}
