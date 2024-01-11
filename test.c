#include "lib.h"

int main(int ac __attribute__((unused)), char *av[]) {
    char buffer[BUFFER_SIZE];
    char* envp[BUFFER_SIZE];
    char* ar_gv[BUFFER_SIZE];
    const char sp[2] = " ";
    char *token;
    int i = 0;
    char **env = environ;
    int cnt = 1;
    int r = EXIT_SUCCESS;
    char* g;

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
 //---------------------------------------------------------------------------------------------       
        // Remove the newline character from the input
        buffer[_strcspn(buffer, "\n")] = 0;

        // Check if the user entered "exit", and exit the loop if true
        if (_strcmp(buffer, "exit") == 0){
            break;
        }
 //---------------------------------------------------------------------------------------------       



 //---------------------------------------------------------------------------------------------       
        //creates a child process so we have two processes
        //the parent process will wait the child to excut so we can keep the terminal working
        pid_t procid = fork();

        // Fork failed, print an error and exit
        if (procid == -1) {
            exit(EXIT_FAILURE);
        }
 //---------------------------------------------------------------------------------------------       


 //---------------------------------------------------------------------------------------------       
        // Child process code
        else if (procid == 0){
            int s;
            token = strtok(buffer, sp);
            ar_gv[0] = token;


//---------------------------------------------------------------------------------------------
            //prints enviroment variabels
        
            if(_strcmp(ar_gv[0], "env") == 0){
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
 //---------------------------------------------------------------------------------------------





            
 //---------------------------------------------------------------------------------------------       
            //devides the input into arguments
            i = 1;
            while( token != NULL ) {
                    token = strtok(NULL, sp);
                    ar_gv[i] = token;
                    i++;
            }
//---------------------------------------------------------------------------------------------       
            if(_chpath(ar_gv[0])){
                s = execve(ar_gv[0], ar_gv, envp);
            }

//---------------------------------------------------------------------------------------------       
            else{
                //excute the code saved in array buffer
                g = f_ex_path(ar_gv[0], av, cnt);
                r = atoi(g);
                s = execve(g, ar_gv, envp);
                //fflush(stdin);
            
                if(s == -1){
                    //if error in excution it prints the error
                }
            }
        }
 //---------------------------------------------------------------------------------------------       


 //---------------------------------------------------------------------------------------------       
        // Parent process waits for the child to complete
        else{
            
            wait(NULL);
        }
        cnt++;
    }
 //---------------------------------------------------------------------------------------------       

    return r;
}