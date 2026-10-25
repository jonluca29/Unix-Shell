#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LENGTH 1024 

void pwdCommand(){
    char pwd[MAX_LENGTH];
    getcwd(pwd, sizeof(pwd)); 
    printf("%s\n", pwd);
}

