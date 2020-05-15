#include "minish.h"

int builtin_help(__attribute__((unused))int argc, char **argv) {
    if(argv[1]!=NULL) {
        for(int i=0; i<12; i++) {
            if (strcmp(argv[1], builtin_arr[i].cmd) == 0) {
                printf("%s\n", builtin_arr[i].help_txt);
                return 0;
            }
        }
        printf("%s no es un comando valido \n",argv[1]);
    }
    printf("Escriba `help name' para saber mas sobre la funcion `name'.\n");
    return 0;
}

