#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL)); // generate random seed
	
	int randomNumber1 = rand() % 6 + 1; // random number range [1,6]
	int randomNumber2 = rand() % 6 + 1;
	int randomNumber3 = rand() % 6 + 1;
	
	printf("Result: %d %d %d\n", randomNumber1, randomNumber2, randomNumber3);
	
	int sum;
	sum = randomNumber1 + randomNumber2 + randomNumber3;

	if(randomNumber1 == randomNumber2 && randomNumber2 == randomNumber3) // Sic Bo Game
		printf("TRIPLE!");	
	else if(sum >= 3 && sum <= 10)
		printf("SMALL!");
	else if(sum >= 11 && sum <= 17) 
		printf("BIG!");
	
	return 0;
}


