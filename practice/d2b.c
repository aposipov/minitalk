

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int number = 10;
	char bin[9] = {0};
	int i = 8;

	while(i != 0)
	{
		if(number % 2 == 0)
			bin[i] = '0';
		else
			bin[i] = '1';
		number /= 2;
		i--;
	}
	write(1, &bin, 9);
	write(1, "\n", 1);
	return(0);
}
