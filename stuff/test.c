#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char program[200];
    char input[200];
    char output[200];
    strcpy(program, "D:\\Programs\\Tesseract\\tesseract.exe");
    strcpy(input, " C:\\Users\\simplex\\Desktop\\test.png");
    strcpy(output, " C:\\Users\\simplex\\Desktop\\o");

    strcat(program, input);
    strcat(program, output);

    printf("%s", program);

    system(program);
    system("PAUSE");
}