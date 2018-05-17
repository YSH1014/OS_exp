#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* create_complex(void* args);
int add(int a,int b);
int shdata  = 0;
int main(){
	pthread_t tid;
	int statu;
	int args[]={4,2};
	statu = pthread_create(&tid,NULL,create_complex,args);
	if( statu != 0) printf(" thread create error\n");
	else {
		sleep(5);
		printf("shdata = %d in main\n",shdata);
		printf("phthread%ld created\n",tid);
	}

	return 0;
}

void* create_complex(void* args){
	int sum = add(((int*)args)[0],((int*)args)[1]);
	printf("%d\n",sum);
	return (void*)0;

}
int add(int a,int b){
	return a+b;
}
