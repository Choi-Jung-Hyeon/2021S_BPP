#include <stdio.h>
#include <ctype.h>
#include <string.h>

int WordCount(char *input, int size);
int PunctuationCount(char *input, int size);

int main(void)
{
	// given 3 testing strings.
	char test1[] = "Hello, World!";
	char test2[] = "She sell sea shell on a sea shore. The shells she sells are sea-shells. I'm sure? For if she sells sea-shells on the sea-shore, then I'm sure she sells sea-shore shells!";
	char test3[] = "VISION 2020 embodies every SKKU student's dream, will, and destiny to make SKKU a global leading university. To successfully establish VISION 2020, SKKU will pursue 'The 5 Core Strategies' and '5 Divisional Strategies'. The Strategic Tasks for 5 Major Areas are the general tasks that influence SKKU's competitivenes.";
	
	printf("test1 has %d punctuations, %d words.\n", PunctuationCount(test1, sizeof(test1) / sizeof(char)), WordCount(test1, sizeof(test1) / sizeof(char)));
	printf("test2 has %d punctuations, %d words.\n", PunctuationCount(test2, sizeof(test2) / sizeof(char)), WordCount(test2, sizeof(test2) / sizeof(char)));
	printf("test3 has %d punctuations, %d words.\n", PunctuationCount(test3, sizeof(test3) / sizeof(char)), WordCount(test3, sizeof(test3) / sizeof(char)));
	return 0;
}

// The number of words in the string.
int WordCount(char *input, int size)
{
	int count_space = 0, count_word = 0;
	for(int i = 0; i < size; i++)
	{
		if(isspace(input[i]) != 0)
			count_space++;
	}
	count_word = count_space + 1;
	return count_word;
}

// The number of punctuations in the string.
int PunctuationCount(char *input, int size)
{
	int count_punct = 0;
	for(int i = 0; i < size; i++)
	{
		if(ispunct(input[i]) != 0)
			count_punct++;
	}
	return count_punct;
}
