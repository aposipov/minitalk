
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


void handler(int sig)
{
	printf("stop not allowed\n");
}

void handler_c(int sig)
{
	printf("input number any again: ");
	fflush(stdout);
}

int main(int argc, char **argv)
{
	struct sigaction sa;
	sa.sa_handler = &handler_c;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);
	
	//signal(SIGTSTP, &handler);

	int x;
	printf("input number: ");
	scanf("%d", &x);
	printf("result %d * 5 = %d\n", x, x * 5);
	return (0);
}
