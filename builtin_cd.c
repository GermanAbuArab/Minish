#include "minish.h"


int builtin_cd(int argc, char **argv) {
    if (argv[1] == "-") {
        return 0;

    } else if (argv[1] == "--") {
        if (chdir(getenv("HOME")) != 0) {
            return -1;
        }
        else {
            return 0;
        }
    } else {
        if (chdir(argv[1]) != 0) {
            printf("No existe esa carpeta o directorio \n");
            return -1;
        } else {
            return 0;
        }
    }
}
