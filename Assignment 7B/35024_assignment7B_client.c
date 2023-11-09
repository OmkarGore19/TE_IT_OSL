/* Assignment No. 7B
Name: Omkar Arun Gore
Roll No: 35024
Batch:B
Title: Inter-process Communication using Shared Memory using System V : Client and Server Programs
Problem Statement: Inter-process Communication using Shared Memory using System V. 
Application to demonstrate: Client and Server Programs in which server process creates a shared memory segment and writes the message to the shared memory segment. Client process reads the message from the shared memory segment and displays it to the screen.
*/


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE     27
 
void die(char *s)
{
    perror(s);
    exit(1);
}
 
int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
 
    key = 5679;
 
    if ((shmid = shmget(key, MAXSIZE, 0666)) < 0)
        die("shmget");
 
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        die("shmat");
    
    printf("\n\nClient started reading\n\n");

    for (s = shm; *s != '\0'; s++)
    {
        putchar(*s);
	printf("\t");
    }
    putchar('\n');
 
    *shm = '*';
    
    printf("\n\nClient Terminated!!!\n\n");

    exit(0);
}


