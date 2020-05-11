#include "minish.h"

int builtin_setenv (int argc, char ** argv) {

    if(argc>2) {                                //Si tengo dos argumentos puedo hacer el set$
        if(setenv(argv[1],argv[2],1) == 0)
            return 0;
        else {
            // TODO HANDELEAR ERRORES
            //    printf("No se pudo cambiar la variable de ambiente %s por %s",argv[1], argv[2]);
            //  return 0;
        }
    }
    printf("No hay suficientes argumentos\n");          //Si no hay argue$
    return 0;
}
