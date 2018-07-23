#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	char*  username;
	char hostname[100];
	char cmd[200];
	username = getlogin();
	gethostname(hostname,80);
	while(1){
		printf("%s@%s:",username,hostname);
		scanf("%s",cmd);
	}
}
