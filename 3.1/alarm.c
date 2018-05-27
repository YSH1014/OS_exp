#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void Alarm_Handle(int sig){
	printf("receive a alarm signal");
}
int main(){
	signal(SIGALRM,Alarm_Handle);
	while(1){
		int t;
		t = alarm(3);
		printf("%d\n",t);
	//	pause();
	}
	return 0;
}
