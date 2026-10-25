#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define DELIM " "

char **parse(char *command){
    char **cmdAndArgs = malloc((MAX_ARGS + 1) * sizeof(char*)); 
    char *token; 
    char *lasts;
    int index = 1;

    // tokenize the command itself
    cmdAndArgs[0] = strtok_r(command, DELIM, &lasts);
    
    // tokenize the arguments
    while((token = strtok_r(NULL, DELIM, &lasts))){
        cmdAndArgs[index++] = token;
    }
    cmdAndArgs[index] = NULL;

    return cmdAndArgs;
}

int main(){
    char command[MAX_INPUT];

    while (1){
        printf("$ > ");
        if (fgets(command, MAX_INPUT, stdin) == NULL){ // if user enters ctrl + D
            printf("\nExiting shell...\n");
            exit(0);
        }
 
        // parse input
        char **tokens = parse(command);
        

        free(*tokens);
    }
    

    return 0;
}
