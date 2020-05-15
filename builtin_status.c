#include "minish.h"


int builtin_status(__attribute__((unused))int argc,__attribute__((unused)) char **argv) {
    printf("El estado del ultimo comando fue %d\n",globalstatret);
    return globalstatret ;
}

