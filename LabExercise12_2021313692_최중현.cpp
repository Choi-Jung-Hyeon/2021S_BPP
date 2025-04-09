#include <stdio.h>
#include <string.h>

struct StuInfo
{
	char Name[10];
	int IDNo;
	int Exam[2];
};

int main(void)
{
	StuInfo StudentExam[10000];
	char StuName[10];
	int StuNo, Exam1, Exam2;
	
	// Read a file and set struct data.
	FILE *fPtr;
	fPtr = fopen("lab12_datafile.txt", "r");
	for(int i = 0; i < 10000; i++)
	{
		if(feof(fPtr))
			break; // Repeat until the file ends.
		
		fscanf(fPtr, "%s %d %d %d", &StuName, &StuNo, &Exam1, &Exam2);
		strcpy(StudentExam[i].Name, StuName);
		StudentExam[i].IDNo = StuNo;
		StudentExam[i].Exam[0] = Exam1;
		StudentExam[i].Exam[1] = Exam2;
	}
	fclose(fPtr);
	
	// Print the student's information.
	int StuNo_User, N;
	while(1)
	{
		printf("Enter a student no (-1 to quit): ");
		scanf("%d", &StuNo_User);
		N = StuNo_User - 1;
		
		if(StuNo_User == -1)
			break; // -1 to quit.
	
		printf("Name: %s, ", StudentExam[N].Name);
		printf("Stu#: %d, ", StudentExam[N].IDNo);
		printf("Exam1: %d, ", StudentExam[N].Exam[0]);
		printf("Exam2: %d\n\n", StudentExam[N].Exam[1]);
	}
	
	printf("\n<End of Programming>");
	return 0;
}
