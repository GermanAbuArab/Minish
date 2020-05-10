#include "minish.h"

int builtin_unsetenv(int argc, char **argv) {

    for(int i=1;i<argc;i++) {
        if( unsetenv(argv[i])){
	//todo handelear errores Einval
	}

    }
    if(argc==1) {
        printf("Faltan argumentos \n");
    }
    return 0;
}
