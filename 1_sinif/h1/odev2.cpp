#include <stdio.h>

int is_prime(int);

int main(){
	const char *FILEPATH ="sayilar.txt";
	const char *FILEPATH_2 = "sayilar2.txt";
	FILE *fpr, *fpw;
	int readnum;
	
	fpr = fopen(FILEPATH, "r");
	fpw = fopen(FILEPATH_2, "w");
	if (fpr == NULL || fpw == NULL){
		printf("ERR");
		return 1;
	}
	do{
		fscanf(fpr,"%d-", &readnum);
		if (is_prime(readnum)){
			fprintf(fpw, "ASAL: %d\n", readnum);
		}
	}while(!(feof(fpr)));
	fclose(fpr);
	fclose(fpw);
}

int is_prime(int num){
	if (num < 2) return 0;
	int i;
	for (i = 2;  i < num; i++){
		if (num % i == 0){
			return 0;
		}
	}
	return 1;
}
