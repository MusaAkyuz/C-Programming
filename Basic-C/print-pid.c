#include <stdio.h>
#include <unistd.h>

int main() {
	printf("%d", getpid());
	printf("%d", getppid());
}
