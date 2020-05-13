#include "minish.h"
int builtin_gid(int argc, char **argv) {
    gid_t gid = getgid();// no hay que handeleaer errores porque nunca falla
    printf("El id del grupo Principal es %d\n", gid);
    gid_t *group;
    int nogroups;

    if ((nogroups =getgroups(0,NULL)) < 0) {
        printf("Error al obtener los id de los grupos secundarios");
        return -1;
    }
    printf("%d\n",nogroups);
    if ((group = malloc(nogroups * sizeof(gid_t))) == NULL) {
        printf("Error interno de Memoria \n");
        return -1;
    }
    if (getgroups(nogroups, group) !=-1) {
        printf("%d\n",nogroups);

        printf("Id de los grupos secundarios:");
        for (int i = 0; i < nogroups; ++i) {
            if (group[i] != getgid()) {
                printf("%d ",  group[i]);
            }
        }
        printf("\n");
    } else {

//todo handelear errores
        return -1;
    }
    return 0;
}
