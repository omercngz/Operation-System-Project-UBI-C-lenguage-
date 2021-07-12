#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define MAXCHAR 18
int pointer = 0;
char str[MAXCHAR];
char result [MAXCHAR+2];
int counter = 0;
FILE *writeToFile;
char barran[]="\n";

void iStart(char iS)
{
	int x = iS -'0';
	pointer = x;
}

void nPlus(char numA)
{
	int y = numA -'0';
	pointer = pointer+y;
}

void nMenus(char numL)
{
	int z = numL-'0';
	pointer = pointer-z;
}

void fFinal(char iF, int last)
{
	int w = iF-'0';
	pointer=last - w;
}

void readWord (char numRead)
{
	int a = numRead-'0';
	for (int i = 0; i< a;i++) {
		result [counter] = str[pointer];
		counter++;
		pointer ++;
	}
}

void lClear(char numClear)
{
	int c = numClear-'0';
	if(c == 0) {
		memset(result, 0, sizeof(result));
	}		
}

void write(char STDOUT_FILENO[],char barran[],int number){
	if(number == 1) {
		writeToFile = fopen(STDOUT_FILENO,"w");
		fputs(result,writeToFile);
		fputs(barran,writeToFile);
		fputs(barran,writeToFile);
		
	}
}

void stop(char numZero)
{
    char STDOUT_FILENO[]="out.txt";
	int z = numZero-'0';
	if(z == 0) {
		write(STDOUT_FILENO,barran,1);
		exit(0);
	}
}

int main(int argc, char* argv[]) {
	char fileName[8];
	for(int i = 0; i< 8;i++) {
		fileName[i] = argv[1][i];
	}
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
	    exit(0);
	    return 0;
	}
	while (fgets(str, MAXCHAR + 1, fp) != NULL) {
		fclose(fp);
	}
	for(int i = 2; i<= 50;i=i+2) {
		switch (argv[i][0]){
			case 'i': iStart(argv[i+1][0]); break;
			case '+': nPlus(argv[i+1][0]); break;
			case '-': nMenus(argv[i+1][0]); break;
			case 'f': fFinal(argv[i+1][0],sizeof(str)); break;
			case 'l': lClear(argv[i+1][0]); break;
			case 's': stop(argv[i+1][0]); break;
			case 'r': readWord(argv[i+1][0]); break;	
		}
	}
	return 0;
}
