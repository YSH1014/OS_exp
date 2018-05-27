#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<wait.h>

void SigChldHandle(int sig){
	pid_t pid;
	int status;
	while( (pid = waitpid(-1,&status,WNOHANG)) > 0) {
			printf("pid %d died with status %d\n",pid,status);
	}
	return;
}

int main(){
	pid_t pid;
	signal(SIGCHLD,SigChldHandle);
	pid = fork();
	if( pid > 0) {
		pause();
	}
	else if( pid == 0) {
		sleep(5);
		exit(1);
	}
	else {//faild
		exit(1);
	}
	return 0;
}
