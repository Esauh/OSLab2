#include  <stdio.h>
#include  <sys/types.h>
#include  <stdlib.h>
#include <time.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
    
    
     int i;
     for(i=0; i< 2; i++)
     {
       pid = fork();
       if (pid == 0)
         {
           ChildProcess(i);
         } 
       else 
       if (pid < 0)
         {
           printf("Error in Fork\n");
         }
     }
     ParentProcess();      
          
}

void  ChildProcess(int kidId)
{
     int random_num, random_num2;
     int i;
     srand(getpid());
     random_num = (rand()%30) +1;
     for(i = 0; i <random_num ; i++)
     {
       printf("Child Pid: %d is going to sleep!\n",getpid());
       random_num2 = rand() % 10;
       //printf("Our Random # is: %d\n",random_num);
       sleep(random_num2 + 1);
       printf("Child Pid: is awake!\nWhere is My Parent %d ?\n",getppid());
     }
     exit(0);
}


void  ParentProcess(void)
{
     int  i, pid, status;
     
     for (i = 0; i < 2; i++)
     {
       pid = wait(&status);
       printf("Child Pid: %d has completed\n", pid);
     }       

}