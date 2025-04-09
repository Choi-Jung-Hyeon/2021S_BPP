#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StuInfo
{
	char Name[10];
	int IDNo;
	int Exam[2];
	int Sum;
	float Average;
	StuInfo *NextPtr;
};

void PrintAllName(StuInfo Node);
float AverageScore(StuInfo Node);
StuInfo *BestStudent(StuInfo Node);

int main(void)
{
	StuInfo Head;
	Head.NextPtr = NULL;
	char StuName[10];
	int StuNo, Exam1, Exam2;
	
	// Open and read a file.
	FILE *fPtr;
	fPtr = fopen("lab12_datafile.txt", "r");
	while(!feof(fPtr))
    {
       // Make a new node.
       StuInfo *NewNode;
	   NewNode = (StuInfo *)malloc(sizeof(StuInfo));   
       NewNode->NextPtr = Head.NextPtr;
       Head.NextPtr = NewNode;
       
       // Set struct data.
	   fscanf(fPtr, "%s %d %d %d", &StuName, &StuNo, &Exam1, &Exam2);
       strcpy(NewNode->Name, StuName);
       NewNode->IDNo = StuNo;
       NewNode->Exam[0] = Exam1;
       NewNode->Exam[1] = Exam2;
       NewNode->Sum = NewNode->Exam[0] + NewNode->Exam[1];
       NewNode->Average = NewNode->Sum / 2.0;
    }
	fclose(fPtr);

	// Implement three functions.
	PrintAllName(Head);	
	printf("Average Score: %f\n\n", AverageScore(Head));
	
	StuInfo *Best;
	Best = BestStudent(Head);	
	printf("Best Student\n");
	printf("Name: %s, ", Best->Name);
	printf("Stu#: %d, ", Best->IDNo);
	printf("Exam1: %d, ", Best->Exam[0]);
	printf("Exam2: %d\n\n", Best->Exam[1]);
	free(Best);
	
	printf("<End of Program>");
	return 0;
}

// Display the name of all students.
void PrintAllName(StuInfo Node)
{
	StuInfo *ThisPtr = &Node;
	
	while(ThisPtr->NextPtr != NULL)
	{
		ThisPtr = ThisPtr->NextPtr;
		printf("Name: %s\n", ThisPtr->Name);
	}
	printf("\n");
	free(ThisPtr);
}

// Display the average score of all students.
float AverageScore(StuInfo Node)
{
	StuInfo *ThisPtr = &Node;
	int TotalSum = 0, Count = 0;
	float Avg;
	
	while(ThisPtr->NextPtr != NULL)
	{
		ThisPtr = ThisPtr->NextPtr;
		TotalSum += ThisPtr->Sum;
		Count++;
	}
	Avg = (float)TotalSum / (Count * 2);
	return Avg;
	free(ThisPtr);
}

// Display the name, student ID and the two scores of the best student.
StuInfo *BestStudent(StuInfo Node)
{
	StuInfo *ThisPtr = &Node;
	StuInfo *BestPtr;
	float Max = ThisPtr->Average;
	
	while(ThisPtr->NextPtr != NULL)
	{
		ThisPtr = ThisPtr->NextPtr;
		if(Max < ThisPtr->Average)
		{
			Max = ThisPtr->Average;
			BestPtr = ThisPtr;
		}
	}
	return BestPtr;
	free(ThisPtr);
	free(BestPtr);
}
