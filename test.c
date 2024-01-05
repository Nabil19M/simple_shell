#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "lib.h"
#define BUFFER_SIZE 1024
extern char **environ;

int main(void) {
    char buffer[BUFFER_SIZE];
    char* envp[BUFFER_SIZE];
    char* argv[BUFFER_SIZE];
    const char sp[2] = " ";
    char *token;
    int i = 0;
    char **env = environ;

    //Infinite loop to keep the shell running until the user enters the "exit" command or error occurs    
    while(1){
        jump:
        //Print the shell prompt
        printf("#cisfun$ ");
        
        // Read user input from the command line
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("\n");
            break;
        }
        
        // Remove the newline character from the input
        buffer[strcspn(buffer, "\n")] = 0;

        // Check if the user entered "exit", and exit the loop if true
        if (strcmp(buffer, "exit") == 0){
            break;
        }

        //creates a child process so we have two processes
        //the parent process will wait the child to excut so we can keep the terminal working
        pid_t procid = fork();

        // Fork failed, print an error and exit
        if (procid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        
        // Child process code
        else if (procid == 0){
            int s;
            
            token = strtok(buffer, sp);
            argv[0] = token;
            
            //prints enviroment variabels
            if(strcmp(argv[0], "env") == 0){
                while (*env != NULL) {
                    envp[i] = *env;
                    env++;
                    i++;
                }
                i = 0;
                for (i = 0; envp[i] != NULL; i++){
                    printf("%s\n", envp[i]);
                }
                goto jump;
            }
            
            //devides the input into arguments
            i = 1;
            while( token != NULL ) {
                    token = strtok(NULL, sp);
                    argv[i] = token;
                    i++;
            }

            //excute the code saved in array buffer
                s = execve(f_ex_path(buffer), argv, envp);
                if(s == -1){
                    //if error in excution it prints the error
                    perror(buffer);
                }

        }

        // Parent process waits for the child to complete
        else{
            
            wait(NULL);
        }
    }
    return 0;
}