#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printbin(int);
int replacebit(int, int, unsigned int);


int main()
{
	FILE *fp1, *fp2;
	srand(time(NULL));
	int i;
	fp1 = fopen("sayilar0.txt", "w");
	fp2 = fopen("sayilar1.txt", "w");
	if (fp1 == NULL || fp2 == NULL){
		printf("ERR");
		exit(1);
	}
	for (i = 0; i < 100; i++)
	{
		int r = rand()%100;
		if (r >> 4 == 0){
			int replaced = replacebit(r, 4, 1);
			fprintf(fp1, "5. biti 0 olan sayinin 4. biti 1 yapýldý: %d\n", replaced);
		}
		else if (r >> 4 == 1) {
			int replaced = replacebit(r, 3, 0);
			fprintf(fp2, "5. biti 1 olan sayinin 3. biti 0 yapýldý: %d\n", replaced);
		}
	}
}

int replacebit(int data, int index, unsigned int type)
{
	if (type) return data | 1 << index - 1;
	else return data & ~(1 << index - 1);
}

void printbin(int x)
{
	int i = sizeof(int) * 8 - 1;
	
	for(; i >= 0; i--)
	{
		if (x >> i & 1){
			putchar('1');
		}else {
			putchar('0');
		}
		if (i % 4 == 0) putchar(' ');
	}
	printf("\n");
}
