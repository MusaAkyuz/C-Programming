#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	pid_t mpid, ppid;
	int x;
	mpid = getpid();
	ppid = getppid();
	printf("mpid : %d\n", mpid);
	printf("ppid : %d\n", ppid);
	fork();
	mpid = getpid();
	ppid = getppid();
	printf("*mpid : %d\n", mpid);
	printf("*ppid : %d\n", ppid);
	
	return 0;
}
