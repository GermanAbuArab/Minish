#include "minish.h"

int builtin_pid(__attribute__((unused))int argc,__attribute__((unused)) char **argv) {
    pid_t id=getpid();  // this function is always succesfull (no hay que chequear errores)
    printf("El id del proceso es : %d \n",id);
    return 0;
}

