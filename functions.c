size_t _strcspn(const char *str, const char *r) {
    size_t i;
    for (i = 0; str[i] != '\0'; ++i) {
        for (size_t j = 0; r[j] != NULL; ++j) {
            if (str[i] == r[j]) {
                return i;
            }
        }
    }
    return i;
}

int _strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }
    
    return (*str1 - *str2);
}

char *_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    size_t l = 0;
    for (l = 0; str[l] != '\0'; l++) {
    }
    char *dup = (char *)malloc(l + 1);
    if (dup != NULL) {
        for (size_t i = 0; i < l; i++) {
            dup[i] = str[i];
        }
        dup[l] = '\0';
    }
    return dup;
}

int isSubstring(const char *str, const char *sub) {
    while (*str != '\0') {
        const char *strPtr = str;
        const char *subPtr = sub;

        while (*subPtr != '\0' && *strPtr == *subPtr) {
            strPtr++;
            subPtr++;
        }

        if (*subPtr == '\0') {
            return 1; // Found a match
        }

        str++;
    }

    return 0; // Substring not found
}
    
 char *get_pth(const char* pth) {
    extern char **environ;
    char **envp = environ;
    char *argv = NULL;
    const char sp[2] = "\n";

    int i = 0;

    while (envp[i] != NULL) {
        if (isSubstring(envp[i], pth)) {
            argv = envp[i];
            break;
        }
        i++;
    }

    return argv;
}

int _chpath(const char* command){
    for(int i = 0; command[i] != '\0'; i++){
        if(command[i] == '/'){
            return 1;
        }
    }
    return 0;
}