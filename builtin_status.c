#include "minish.h"


int builtin_status(int argc, char **argv) {
    printf("El estado del ultimo comando fue %d\n",globalstatret);
    return globalstatret ;
}

