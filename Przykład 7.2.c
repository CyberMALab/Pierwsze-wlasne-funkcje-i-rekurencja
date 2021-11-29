#include <stdio.h>
#include <stdlib.h>

double kwadrat_liczby(double);
int max(int,int);

int main()
{
	double a = kwadrat_liczby(4);
	double b = a + kwadrat_liczby(5);
	int c = max(23,10);
	printf("a=%4.0lf \nb=%4.0lf \nc=%4d",a,b,c);
	return 0;
}

double kwadrat_liczby(double liczba)
{
	return liczba*liczba;
}

int max(int a, int b)
{
	return (a>b)? a : b;
}

