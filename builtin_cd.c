#include "minish.h"


int builtin_cd(int argc, char **argv) {
    if (chdir(argv[1]) != 0) {
        printf("No existe esa carpeta o directorio \n");
        return -1;
    } else {
        return 0;
    }
}
