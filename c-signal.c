#include<signal.h>

#include<unistd.h>

#include<stdio.h>

#include<errno.h>

//#include <sys/types.h>

void handler1(int sig) {

 printf("Phantom");

 exit(0);

}

int main()

{

   pid_t pid1;

   signal(SIGUSR1, handler1); //installing signal handler

   if((pid1 = fork()) == 0) { //forking

       printf("Ghost");

       exit(0);

   }

   kill(pid1, SIGUSR1);

   printf("Ninja");

   return 0;

}
