#include "minish.h"
int builtin_dir (int argc, char ** argv) {
    DIR *d;
    int i;
    struct dirent *dir;
    char *directorios[MAXLINE];
    if((d=opendir("."))== NULL) {
        printf("Error abriendo el directorio actual :\n");
        return -1;
    }
    for(i=0; (dir=readdir(d))!=NULL; ++i) { //Guardo el nombre de los directorios
        directorios[i]=dir->d_name;
    }
    char *aux;
    if (closedir(d)==-1) {
        perror("Error al cerrar el directorio");
        return -1;
    }
    for(int j=0; j<i-1; ++j) { //Ordeno de forma Alfabetica los directorios
        for(int k=0; k<i-j-1; ++k) {
            if(strcmp(directorios[k],directorios[k+1])>0) {
                aux=directorios[k];
                directorios[k]=directorios[k+1];
                directorios[k+1]=aux;
            }
        }
    }
    for(int g=0; g<i; ++g) {
//	if((g+1)%8==0)printf("\n");
        if((argc>1) &&(strstr(directorios[g],argv[1])==NULL)) {

        } else {
            printf("%s\n",directorios[g]);
        }
    }
    return 0;
}

//abrir ordenar e impirmir

