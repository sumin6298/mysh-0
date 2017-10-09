#include "utils.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char* command_clone;
	char* word;
	int WordNum = 0;
	int i = 0;
	command_clone = (char*)malloc(sizeof(char)*(strlen(command)+1));
	strcpy(command_clone, command);

	word = strtok(command_clone, " \t\n");

	while(word != NULL){
		WordNum++;
		*argv = (char**)realloc(*argv, sizeof(char*)*(WordNum+1));
		(*argv)[i] = (char*)malloc(sizeof(char)*(strlen(word)+1));
		strcpy((*argv)[i], word);
		word = strtok(NULL, " \t\n");
		i++;
	}
	
	
	if(WordNum == 0){
		WordNum++;
		*argv = (char**)malloc(sizeof(char*)*(WordNum+1));
		(*argv)[i] = (char*)malloc(sizeof(char)*2);
		strcpy((*argv)[0], "");
	}
	*argc = WordNum;
	
}
