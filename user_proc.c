/*
 *Jared Migneco
 *Project 5 user_proc class

 *04/21/2022
 */
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/sem.h>


//used for semaphore in critical region
union semun
{
        int val;                /* value for SETVAL */
        struct semid_ds *buf;   /* buffer for IPC_STAT & IPC_SET */
        unsigned short *array;  /* array for GETALL & SETALL */
        struct seminfo *__buf;  /* buffer for IPC_INFO */
};


int main (const int argc, char** argv)
{
        int shmid, i;

        //necessary semaphore variables for CR
        key_t key;
        int semid;
        union semun arg;
        struct sembuf sb = {0, -1, 0};



        //matching the shared mem ID to be the same as in the OSS class
        shmid = shmget(0x080698, sizeof(int), 0666 | IPC_CREAT);
        int *shm = (int*)shmat(shmid, NULL, 0);

        //checks if shared memory is set to 0
        if (*shm == 0)
        {
                printf("User_proc: shared memory is set to 0");
        }
        else
        {
                //user process class has an error and exits if shared memory is not 0
                printf("User_proc: ERROR: shared memory not set to 0");
                exit(EXIT_FAILURE);
        }

        //unfinished so left at 0 so program can compile
        *shm = 0;

        FILE *fp;
        fp = fopen ("logfile.%d", xx, "w");

        //waits for shared memory to reach 0
        while(*shm != 0)
        {
                sleep(1);                                                                                                                                    
        }
        printf("User_proc: Shared memory reset to 0");

        return(EXIT_FAILURE);
}
