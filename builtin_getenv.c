#include "minish.h"

int builtin_getenv(int argc, char **argv) {
;
    for(int i=1;i<argc;++i) {
        char *var=getenv(argv[i]);
        if(var!=NULL) {
            printf("%s \n",var);
        }
        else {
            printf("No se encontro la variable de ambiente %s \n",argv[i]);
        }
    }
    if(argv[1]==NULL) {
        printf("No se dio ninguna variable para ver su valor\n");
        return 0;
    }
    return 0;
}
