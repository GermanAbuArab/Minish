#include "minish.h"

int builtin_pid(int argc, char **argv) {
    pid_t id=getpid();// this function is always succesfull (no hay que hacer un if para los errores)
    printf("El id del proceso es : %d \n",id);
    return 0;
}
