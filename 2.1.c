#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	pid_t pid;
	pid = fork();
	if( pid == 0) {  //child1
		printf("I'm a child ,My pid is %d,My parent pid is %d\n",getpid(),getppid());
	}
	else {
		pid = fork();
		if( pid == 0) printf("I'm second child\n");
		else {
			int DiedChild;
			while( (DiedChild = wait(NULL)) != -1) printf("child %d died\n",DiedChild);
		}
	}
	return 0;
}
