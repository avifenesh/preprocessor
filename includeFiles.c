/*
Avi Fenesh
1/4/2021
v1.0
This project is a semy preprocessor who clean the file from cmments, and include the local "include" files
This file is chrage of including the files asked in the program
*/


#include <stdio.h>
#include <string.h>

enum status {OUT,INCLUDEING,LEFT_QUOTES,IN_FILE}; /*for navigate between the optional status*/

int includeFiles(char file1[]){
	FILE *fw;
	FILE *fr;
	FILE *fi;
	char ch;
	char ci;
	int state = OUT;
	/*making another name of file, same as the input file but with 1 after the .c*/
	char file2[20];
	char add = '2';
	strcpy(file2, file1);
	file2[(strlen(file2)-1)]=add;
	char fileInclude[20];
	char chekInclude[20];
	char check[] = "include";

	/*open the files for read and write, with error handelling*/
	if (!(fr = fopen(file1, "r")))
	{
		fprintf(stderr, "cannot open file\n");
		return 0;
	}/*if*/

	if (!(fw = fopen(file2, "w")))
	{
		fprintf(stderr, "cannot open file\n");
		return 0;
	}/*if*/

		/*main loop of redding and wrting*/
	while(!feof(fr)){

		ch = fgetc(fr);
		if(feof(fr))/*check if its end of file sign*/
			break;

		switch(state){/*switch between the optional states*/

			case OUT:/*regular state, coppy to file2, check if starting include*/
				if(ch == '#'){/*maybe starting include*/
					fgets(chekInclude, 8, fr);/*for checking if include or something like def or indef*/
					if ((strcmp(check, chekInclude)==0))
					{
						state=INCLUDEING;
						strcpy(fileInclude, "\0");/*make sure that the string empty*/
					}/*if*/
				else {
					fputc(ch, fw);
					fputs(chekInclude, fw);
					strcmp(chekInclude, "\0");/*clean the string for next use*/
				}/*else*/
				}/*if*/
				else fputc(ch, fw);
				break;

			case INCLUDEING:/*check if name of file start, otherwise continue*/
				if (ch == '\"')
					state=LEFT_QUOTES;
				break;

			case LEFT_QUOTES:/*coppy the name of file till another " sign*/
				if (ch == '\"'){
					state = IN_FILE;/*for coppying the file asked for*/
					/*open the file that we want to include, with error handelling*/
					if (!(fi = fopen(fileInclude, "r")))
					{
						fprintf(stderr, "cannot open including file\n");
						return 0;
					}/*if*/
					}/*if*/
					else strncat(fileInclude, &ch, 1);/*coppying the name of file*/
					break;

				case IN_FILE:/*coppyng the file included to file2*/
					while(!feof(fi)){
						ci = fgetc(fi);
						if(feof(fi))/*check if its end of file sign*/
							break;
						fputc(ci, fw);
						} /*while*/
					fclose(fi);
					state = OUT;
					break;

			}/*switch*/

		}/*while*/

	fclose(fw);
	fclose(fr);
	return 0;

}/*methode*/