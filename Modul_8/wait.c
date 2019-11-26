#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	int i, status;
	pid_t pid;
	pid = fork();
	if(pid < 0){
		printf("\nPembuatan proses gagal\n");
		exit(-1);
	}	
	else if (pid > 0)
	{
		wait(NULL);
		printf("\nParent starts\nNomor genap:");
		for (i=2; i<=10;i+=2)
			printf("%3d", i);
		printf("\nParent ends\n");
	}
	else if(pid == 0)
	{
		printf("Child start\nNomor ganjil:");
		for(i=1;i<10;i+=2)
			printf("%3d", i);
		printf("\nChild ends\n");
	}
}
