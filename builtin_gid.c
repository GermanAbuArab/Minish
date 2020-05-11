#include "minish.h"

int builtin_gid(int argc, char **argv) {
    gid_t gid = getgid();// no hay que handeleaer errores porque nunca falla
    printf("El id del grupo Principal es %d\n", gid);
    gid_t *group;
    int nogroups;


    if (nogroups = getgroups(0, NULL) < 0) {
        //todo handelear errno
        return -1;
    }

    if (group = malloc(nogroups * sizeof(gid_t)) == NULL) {

//todo errno1966019f26da57353bb44c0b6f970
        printf("Error interno de Memoria \n");
        return -1;
    }
    if (group=getgroups(nogroups, group) != -1) { //group= getgroup

        printf("Grupos secundarios:");
        for (int i = 0; i < nogroups; i++) {
            if (group[i] != getgid()) {
                printf("%d ", (int) group[i]);          //Si hay grupos que no sean el principal los imprimo
            }
        }
        printf("\n");
    } else {

//todo handelear errores
        return -1;
    }
    return 0;
}
