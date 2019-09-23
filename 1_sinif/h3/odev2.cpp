#include <stdio.h>

int sum(int x)
{
	if (x <= 1) return 1;
	return x + sum (x - 1);
}

int main()
{
	int num;
	printf("Sayi> ");
	scanf("%d", &num);
	printf("Sonuc: %d", sum(num));
}
