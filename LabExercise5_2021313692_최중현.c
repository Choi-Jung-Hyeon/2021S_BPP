#include<stdio.h>

int gcd(int m, int n); // Function Prototype
int lcm(int m, int n);

int main(void)
{
	int M, N, temp;
	
	printf("Enter two positive integers: ");
	scanf("%d%d", &M, &N);
	printf("M = %d, N = %d\n", M, N);
	
	if(M < N) // Sort
	{
		temp = M;
		M = N;
		N = temp;
	}
	
	printf("GCD = %d \n", gcd(M,N)); // Function Call
	printf("LCM = %d \n", lcm(M,N));
	return 0;
}

int gcd(int m, int n) // Function Definition
{
	if(n == 0)	return m; // Base Case
	else 		return gcd(n, m%n); // Recursive Case
}

int lcm(int m, int n)
{
	return m * n / gcd(m, n);
}

