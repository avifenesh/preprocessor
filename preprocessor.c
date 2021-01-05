/*
Avi Fenesh
1/4/2021
v1.0
This project is a semy preprocessor who clean the file from cmments, and include the local "include" files
This file is the main file
*/

#include "preprocessor.h"

int main(){
	char add = '1';
	char file[20];
	char file1[20];

	printf("please enter the name of file you want to preprocess\n");
	scanf("%s", file);

	if ((file[(strlen(file)-1)])!='c')
	{
		printf("The file you gave is not a C file, please try with correct file\n");
		return 0;
	}

	strcpy(file1, file);
	strncat(file1, &add, 1);

	if(cleanComment(file)==0){
		includeFiles(file1);
		printf("procces done, you wellcome!\n");}

	return 0;
}