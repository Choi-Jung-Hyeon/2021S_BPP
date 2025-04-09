#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int numbers[45];
	for(int i = 0; i < 45; i++)
		numbers[i] = i + 1;
	int *pick[6] = {0};
	
	// Put random number in index.
	int index[6];
	for(int i = 0; i < 6; i++)
		index[i] = rand() % 45;
	
	// Put number in pick randomly.
	for(int i = 0; i < 6; i++)
		pick[i] = &numbers[index[i]];
	
	printf("%d %d %d %d %d %d", *pick[0], *pick[1], *pick[2], *pick[3], *pick[4], *pick[5]);
	return 0;
}


