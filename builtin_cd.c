#include "minish.h"

int builtin_cd(int argc, char **argv) {

    if(oldpwd==NULL)   {
        free(oldpwd);
        oldpwd=strdup(cwd);
    }

    if (argc > 1) {
        if (strcmp(argv[1], "-") == 0) {
            if(chdir(oldpwd)!=0) {

                //todo printear algo
                return -1;
            } else {
                free(oldpwd);
                oldpwd=cwd;


                return 0;
            }
        } else if (strcmp(argv[1], "--") == 0) {
            if (chdir(getenv("HOME")) != 0) {
                //todo printear algo
                return -1;
            }
            else {
                free(oldpwd);
                oldpwd=cwd;
                return 0;
            }
        } else {
            if (chdir(argv[1]) != 0) {
                printf("No existe esa carpeta o directorio \n");
                return -1;
            } else {
                free(oldpwd);
                oldpwd=cwd;
                return 0;
            }
        }
    } else {          // repito codigo porque si argv[1] es null  el strcmp va a tirar error
        if (chdir(getenv("HOME")) != 0) {
            return -1;
        }
        else {
            strcpy(oldpwd,cwd);
            oldpwd=cwd;
            return 0;
        }
    }
}
