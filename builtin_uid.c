#include "minish.h"

int builtin_uid(int argc, char **argv) {
    uid_t id=getuid(); // These functions are always successful(No hay que chequear errores)
    printf("El id del Usuario es : %d \n",id);
    return 0;
}
