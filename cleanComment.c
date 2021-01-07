/*
Avi Fenesh
1/4/2021
v1.0
This project is a semy preprocessor who clean the file from cmments, and include the local "include" files
This file is chrage of clening the givven file from comments
*/

#include <stdio.h>
#include <string.h>

enum status {OUT,IN_STRING,LEFT_SLASH,IN_COMMENT,RIGHT_STAR}; /*for handeleing the states and navigate between them*/

int cleanComment(char file[]){
	FILE *fw;
	FILE *fr;
	char ch;
	int state = OUT;
	/*making another name of file, same as the input file but with 1 after the .c*/
	char file1[20];
	char add = '1';
	strcpy(file1, file);
	strncat(file1, &add, 1);

	/*open the files for read and write, with error handelling*/
	if (!(fr = fopen(file, "r")))
	{
		fprintf(stderr, "cannot open file\n");
		return 1;
	}

	if (!(fw = fopen(file1, "w")))
	{
		fprintf(stderr, "cannot open file\n");
		return 1;
	}

	/*main loop of redding and wrting*/
	while(!feof(fr)){

		ch = fgetc(fr);
		if(feof(fr))/*check if its end of file sign*/
			break;

		switch(state){/*switch between the optional states*/
			case OUT:/*regular state, coppy to the file1, check if starting string or comment*/
				if(ch == '/')/*maybe starting comment*/
					state=LEFT_SLASH;
				else {
					fputc(ch, fw);
					if (ch=='\"')/*starting string*/
						state=IN_STRING;
				}/*else*/
				break;
			
			case LEFT_SLASH:
				if(ch == '*')/*check if comment*/
					state = IN_COMMENT;
				else{
					fputc(ch, fw);
					state = OUT;
				}/*else*/
				break;

			case IN_COMMENT:/*check maybe comment will end, otherwise skip the char*/
				if(ch == '*')
				state = RIGHT_STAR;
 				break;

	 		case RIGHT_STAR:/*check if comments end, otherwise skip and return to in_comment state*/
				if(ch == '/')
					state = OUT;
				else if(ch != '*')
					state = IN_COMMENT;
				break;

			case IN_STRING:/*check if string end, else oblivious slashs*/
				if (ch == '\"')
	 				state = OUT;
	 			fputc(ch, fw);
 				break;
		}/*switch*/

	}/*while*/

 	/*close files and return*/
	if(fclose(fw)!=0){
		printf("there is a problem with closing the file! we must stop the program, sorry.\n");
		return 0;
	}/*if*/
	if(fclose(fr)!=0){
		printf("there is a problem with closing the file! we must stop the program, sorry.\n");
		return 0;
	}/*if*/

 	return 0;
}/*methode*/