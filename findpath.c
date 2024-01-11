
#include "lib.h"

char* f_ex_path(const char* command, char *av[], int cnt) {
char* car;
    // Get the value of the PATH environment variable
    char* pth_env = get_pth("PATH");

    // If PATH is not set, return NULL
    if (pth_env == NULL) {
        return NULL;
    }

    // Duplicate the PATH string to avoid modifying the original string
    char* pth_cpy = _strdup(pth_env);

    // Check for memory allocation failure
    if (pth_cpy == NULL) {
        perror("strdup");
        return NULL;
    }

    // Tokenize the duplicated PATH string using ":" as the delimiter
    char* dir = strtok(pth_cpy, ":");


    while (dir != NULL) {

        // Create a buffer to store the full path by concatenating the directory and command
        char exec_path[MX_PTH_LNTH];
        int path_len = strlen(dir) + 1 + strlen(command) + 1;
        // The snprintf function is used to safely construct the path by preventing buffer overflow.
        // Parameters:
        //   - exec_path:   Buffer to store the resulting full path.
        //   - sizeof(exec_path):   Size of the buffer to prevent overflows.
        //   - dir:         Current directory from the PATH environment variable.
        //   - command:     The command for which to find the executable path.
        //snprintf(exec_path, sizeof(exec_path), "%s/%s", dir, command);
        int offset = 0;
        strcpy(exec_path + 0, dir);
        offset += _strlen(dir);
        exec_path[offset++] = '/';
        strcpy(exec_path + offset, command);
        // Check if the concatenated path is executable
        if (access(exec_path, X_OK) == 0) {
            // If executable, duplicate the path and return it
            char* result = _strdup(exec_path);
            free(pth_cpy);// Free the duplicated PATH string before returning
            return result;
        }

        
        char* car = exec_path;

        // Move to the next directory in PATH
        dir = strtok(NULL, ":");
    }
    	if (stat(car, &buf) == -1){
		    handle_errors((char**)&command, av, cnt, 127);
            return "127";
	    }
   
        if (access(car, X_OK) == -1) {
            handle_errors((char**)&command, av, cnt, 126);
            return "126";
        }
        
        
        
    

    // Free the duplicated PATH string if no executable path is found
    free(pth_cpy);
    return NULL;
}