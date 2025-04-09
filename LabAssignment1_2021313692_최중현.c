#include <stdio.h>

int main(void)
{
	int John_score, Mary_score, Peter_score, Jane_score;
	
	printf("Input John's score : ");
	scanf("%d", &John_score);
	printf("Input Mary's score : ");
	scanf("%d", &Mary_score);
	printf("Input Peter's score : ");
	scanf("%d", &Peter_score);
	printf("Input Jane's score : ");
	scanf("%d", &Jane_score);	
	
	float Avg;
	Avg = (John_score + Mary_score + Peter_score + Jane_score) / 4.0;
	printf("Average : %.2f", Avg);
	
	return 0;
}
