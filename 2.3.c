#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* wc(void* path);
int counter;
int comp;
int main(int argc,char* argv[]){

	comp = 0;
	counter = 0;
	pthread_t tid1,tid2;
	int sta1,sta2;
	sta1 = pthread_create(&tid1,NULL,wc,argv[1]);
	if( sta1) printf("pthread1 create error%d\n",sta1);
	sta2 = pthread_create(&tid2,NULL,wc,argv[2]);
	if( sta2) printf("pthread2 create error%d\n",sta2);
	while( comp <2) sleep(1);
	printf("%d\n",counter);
}
void* wc(void* path){
	FILE* fp = fopen((char*)path,"r");
	char c;
	int Inword = 0;
	while( (c=fgetc(fp)) != EOF){
		if( ( c>='A' && c<='Z') || (c>='a' && c<='z')) Inword = 1;
		else {
			if( Inword ) counter++;
			Inword = 0;
		}
	}
	comp++;
}

