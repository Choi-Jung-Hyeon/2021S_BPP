#include <stdio.h>

int main(void)
{
	// Declare a file pointer and open file stream. (write binary only)
	FILE *fPtr;
	fPtr = fopen("score.dat", "wb");
	int score[20], student;
	
	// Access the file stream. (writing a file)
	for(student = 0; student < 20; student++)
	{
		printf("Enter the score for student %2d: ", student + 1);
		scanf("%d", &score[student]);
	}
	
	fwrite(&score, sizeof(int), 20, fPtr);	
	// Close the file stream.
	fclose(fPtr);
	return 0;
}



