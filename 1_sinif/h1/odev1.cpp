#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int);

int main(){
	const char *FILEPATH = "sayilar.txt";
	FILE *fpw;
	
	if ((fpw = fopen(FILEPATH, "w")) == NULL){
		printf("Err writing file");
		return 1;
	}

	srand(time(NULL)); 
	int i;
	for (i = 0; i < 100; i++){
		fprintf(fpw, "%d-", rand()%1000);
	}
	
	fclose(fpw);
	

	
}


