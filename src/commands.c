#include <string.h>
#include<unistd.h>
#include "commands.h"
#include<stdio.h>

int do_cd(int argc, char** argv) {
 	
  if (!validate_cd_argv(argc, argv))
    return -1;

  chdir(argv[1]);
 		
  return 0;
}

int do_pwd(int argc, char** argv) {

  if (!validate_pwd_argv(argc, argv))
    return -1;

 char buf[100];
  if(NULL!=getcwd(buf, 100)){
	printf("dir: %s\n",buf);
  }


  return 0;
}

int validate_cd_argv(int argc, char** argv) {
	if(argc == 2) {
		if(strcmp(argv[0], "cd") == 0)
			return 1;
		else 
			return 0;
	}
	else return 0;
	
}

int validate_pwd_argv(int argc, char** argv) {
	if(argc ==1){
		if(strcmp(argv[0], "pwd") == 0 ) return 1;
		else return 0;
	}

	else return 0;
}
	
	

