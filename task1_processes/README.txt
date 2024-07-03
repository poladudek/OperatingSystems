
EXERCISE 1
------------
Author: Pola Dudek
Krakow 2024
------------

Programs perform various tasks on processes using the fork() function and include error handling for selected functions.

----------- Description of the programs:


cw1a --- The program displays the identifiers UID, PID, GID, PPID, GPID for a given process.

cw1b --- The program displays the identifiers UID, PID, GID, PPID, GPID for the parent process and all child processes. The parent process waits for all child processes to finish using the wait() function.

cw1c --- The program displays the identifiers UID, PID, GID, PPID, GPID for the parent process and all child processes, with the child processes being adopted by the init process or its equivalent using the sleep() function.

cw1d --- The program groups processes by generations from oldest to youngest and displays the identifiers UID, PID, GID, PPID, GPID for the parent process and all child processes. Generations are grouped using the sleep() function; generations are separated by new lines. The parent process terminates only after all child processes have finished, achieved solely using the sleep() function. The results of an example program run, saved as a process family tree, can be found in the file tree_of_processes.

cw1e --- The program displays the identifiers UID, PID, GID, PPID, GPID for the parent process and all child processes, with each child process being the leader of its group. The setpgid() function is used to accomplish this task.


---------- Running the programs:


To compile and run the programs, use the Makefile. The individual procedures in the Makefile are described in the make help procedure, which should be called from the shell in the directory containing the Makefile.

To compile all files, use the command make all, and to run (with prior compilation) use the command make run-cw1x, where x is any letter representing the task subpoint entered by the user.

It is also possible to compile and run the programs directly from the shell using the gcc compiler.
