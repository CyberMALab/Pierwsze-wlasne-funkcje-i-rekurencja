#include <stdio.h>
#include <stdlib.h>

unsigned silnia (unsigned);

int main() 
{
	printf("%d", silnia(3));
	return 0;
}

unsigned silnia (unsigned n)
{
/* obsłużenie wyjątku n=0 */
	if(n==0)
		return 0;
/* warunek stopu ------ 1 dla n=1 */
	if(n==1)
		return 1;
/* warunek ogólny ------ n*f(n-1)  */
	return n*silnia(n-1);
}

