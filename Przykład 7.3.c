#include <stdio.h>
#include <stdlib.h>

void parametry(int a, int b)
{
	static int i=1;
	a=a+1;
	b=b+3;
	printf("\nWEWNATRZ FUNCKJI wywolanie %d\n", i) ;
	printf("a=%d b=%d",a,b);
	i++;
}

int main() {
	int a=3,b=5;
	printf("\nPRZED WYWOLAIEM\n") ;
	printf("a=%d b=%d",a,b);
	
	parametry(a,b);
	
	printf("\nPO WYWOLANIU 1\n") ;
	printf("a=%d b=%d",a,b);
	
	parametry(a,b);
	
	printf("\nPO WYWOLANIU 2\n") ;
	printf("a=%d b=%d",a,b);
	return 0;
}

