#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* create_simple(void* args);
int shdata  = 0;
int main(){
	pthread_t tid;
	int statu;
		
	statu = pthread_create(&tid,NULL,create_simple,NULL);
	if( statu != 0) printf(" thread create error\n");
	else {
		sleep(5);
		printf("shdata = %d in main\n",shdata);
		printf("phthread%ld created\n",tid);
	}

	return 0;
}

void* create_simple(void* args){
	for(int i = 0;i<10;i++){
		shdata ++;
		printf("shdata = %d\n",shdata);
		sleep(1);
	}
	printf("Now in thread\n");
	return (void*)0;
}
