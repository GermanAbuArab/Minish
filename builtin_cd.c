#include "minish.h"

char *aux; // variable para cambiara cwd con oldpwd
int builtin_cd(int argc, char **argv) {

    if (argc > 1) {
        if (strcmp(argv[1], "-") == 0) {
            if (chdir(getenv(oldpwd)) != 0) {
                return -1;
            } else {
                aux = oldpwd;
                oldpwd = cwd;
                cwd = aux;
                return 0;
            }
        } else if (strcmp(argv[1], "--") == 0) {
            if (chdir(getenv("HOME")) != 0) { return -1; }
            else {
                oldpwd=cwd;
                cwd=getenv("HOME"); // getenv no tiene errores
                return 0;
            }
        } else {
            if (chdir(argv[1]) != 0) {
                printf("No existe esa carpeta o directorio \n");
                return -1;
            } else {
                if(argv[1][0]=='/'){ // es una ruta absoluta
                    oldpwd=cwd;
                    cwd=argv[1];
                }else
                {
                    oldpwd=cwd;
                    strcat(cwd,argv[1]);
                return 0;
            }
        }
    } else {          // repito codigo porque si argv[1] es null  el strcmp va a tirar error
        if (chdir(getenv("HOME")) != 0) { return -1; }
        else {
            oldpwd=cwd
            cwd=getenv("HOME"); // getenv no tiene errores
            return 0;
        }
    }
}

