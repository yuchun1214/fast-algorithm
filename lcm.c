#include <stdio.h>

unsigned long lcm_not_zero(unsigned long a, unsigned long b)
{
	unsigned long l = 0;

	if (l)
		return l;

	return (b ? : a);
}

int main(){
	int a = 4, b = 0;
    printf("%d\n", b ? : a);	
}
