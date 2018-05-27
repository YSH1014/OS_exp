#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argvs[]){
	int fd;
	int ret;
	char msg[1024];
	printf("%d %s,child\n",getpid(),argvs[1]);
	sscanf(argvs[1],"%d",&fd);
	sleep(3);
	ret = read(fd,msg,1024);
	msg[ret] = 0;
	printf("%s\n",msg);

	close(fd);
	return 0;
}
