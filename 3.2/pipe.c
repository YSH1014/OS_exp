#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<wait.h>

int main(){
	int Mypipe[2];
	int statu_pipe;
	int wait_statu;
	char* msg = "wwwwwwwww";
	statu_pipe = pipe(Mypipe);
	if( statu_pipe == 0) {
		pid_t pid;
		pid = fork();
		if( pid == 0) {
			char arg1[100];
			sprintf(arg1,"%d",Mypipe[0]);
			execlp("./child","child",arg1,NULL);
		}
		else if( pid > 0) {
			int l;
			//scanf("%s",msg);
			write(Mypipe[1],msg,strlen(msg));
			close(Mypipe[1]);
		}
		else printf("fork error\n");
		pid = wait(&wait_statu);
		printf("%d exit\n",pid);
	}
	else printf("pipe error\n");
	return 0;
}
