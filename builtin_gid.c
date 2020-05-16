#include "minish.h"
int builtin_gid(__attribute__((unused))int argc,__attribute__((unused)) char **argv) {
    gid_t gid = getgid();// no hay que handeleaer errores porque nunca falla
    printf("El id del grupo Principal es %d\n", gid);
    gid_t *group;
    int nogroups;

    if ((nogroups =getgroups(0,NULL)) < 0) {
        printf("Error al obtener los id de los grupos secundarios");
        return -1;
    }
    if ((group = malloc(nogroups * sizeof(gid_t))) == NULL) {
        printf("Error interno de Memoria \n");
        free(group);
        return -1;
    }

    if (getgroups(nogroups, group) !=-1) {
        printf("Id de los grupos secundarios:");
        for (int i = 0; i < nogroups; ++i) {
            if (group[i] != getgid()) {
                printf("%d ",  group[i]);
            }
        }
        printf("\n");
    } else {

       free(group);
        return -1;
    }
    free(group);
    return 0;
}

