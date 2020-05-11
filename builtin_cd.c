#include "minish.h"


int builtin_cd(int argc, char **argv) {
    if (argc>1) {
        if (strcmp(argv[1],"-")==0) {

            return 0;
        } else if (strcmp(argv[1],"--")==0) {
            if (chdir(getenv("HOME")) != 0) { return -1; }
            else { return 0; }
        } else {
            if (chdir(argv[1]) != 0) {
                printf("No existe esa carpeta o directorio \n");
                return -1;
            } else {
                return 0;
            }
        }
    } else {
        printf("Tiene que dar una directoria al cual ir");
        return -1;
    }
}

