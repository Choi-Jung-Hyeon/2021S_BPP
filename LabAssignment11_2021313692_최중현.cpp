#include<stdio.h>

int main(void)
{
	int option, score[20];
	FILE *fPtr;
	fPtr = fopen("score.dat", "rb");
	fread(&score, sizeof(int), 20, fPtr);
	
	do{
		// Display options.
		printf("1. Read and display all data from \"score.dat\"\n");
		printf("2. Multiply all the numbers in \"score.dat\" by 2.\n");
		printf("3. Quit.\n");
		printf("Enter your option: ");
		scanf("%d", &option);
		
		// Read and display all data from "score.dat." 
		if(option == 1)
		{
			for(int i = 0; i < 20; i++)
				printf("%d ", score[i]);
			printf("\n");
		}
		
		// Multiply all the numbers in "score.dat" by 2.
		if(option == 2)
		{
			for(int i = 0; i < 20; i++)
				score[i] *= 2;
			fPtr = fopen("score.dat", "wb");
			fwrite(&score, sizeof(int), 20, fPtr);
		}
		
		rewind(fPtr);
		fclose(fPtr);
		printf("\n");
	}while(option != 3);
	
	printf("<End of Program>");
	return 0; 
}


