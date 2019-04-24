#include <stdio.h>


int OBEB(int x, int y)
{
	if (y == 0) return x;
	return OBEB(y, x % y);
}

int main()
{
	int num1, num2;
	printf("Sayi1> ");
	scanf("%d", &num1);
	printf("Sayi2> ");
	scanf("%d", &num2);
	
	printf("Sonuc(OBEB): %d", OBEB(num1, num2));
}
