#include <stdio.h>
#include <limits.h>

int lrs(int, int);
void printbin(int);
int len(int);

int main(){
	/*int i, shift;
	printf("MAX_INT ile denendi\n");
	printf("Sayi> ");
	scanf("%d", &i);
	printf("Shift> ");
	scanf("%d", &shift);
	

	int proc = lrs(i, shift);
	printf("Sayi: %d\nBinary: ", proc);	
	printbin(proc);*/
	printbin(lrs(16, 2));
	
}

void printbin(int x)
{
      int i = sizeof(int) * 8 - 1;
      for (; i >= 0; --i) 
      {
	    if (x >> i & 1)
	        putchar('1');
	    else
	    	putchar('0');
	    if (i%4==0) putchar(' ');
      }
      printf("\n");
}


int len(int x)
{
	int i = sizeof(int) * 8 - 1;
	for (; i >= 0; --i) 
	{
		if (x >> i & 1)
			return i + 1;
	}
	printf("\n");	
}
int lrs(int data, int shift)
{	
	if ((shift &= 31 ) == 0)
      return data;
    return (data << shift) | (data >> (len(data)- shift));	
}
