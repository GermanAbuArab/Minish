#include "minish.h"

int builtin_gid(int argc, char **argv) {
   gid_t gid =getgid();// no hay que handeleaer errores porque nunca falla
   printf("El id del grupo Principal es %d\n",gid);
gid_t *group;
int nogroups;



 if(nogroups = getgroups( 0, NULL )<0){
	//todo handelerar error
}

if(group = malloc(nogroups* sizeof(gid_t))==NULL){
//todo handelear error
//si falla devuelve un puntero nullo
}


if(getgroups(nogroups, group) !=-1){

printf("Grupos secundarios:");
        for(int i = 0; i < nogroups; i++ ) {
            if(group[i]!= getgid()) {
                printf( "%d ", ( int ) group[i] );          //Si hay grupos que no sean el principal los imprimo
            }
        }
        printf("\n");
}
else{


//todo handelear errores

}
   return 0;
}
