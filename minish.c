#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "minish.h"
#define MAXLINE  1024        // tamaño máximo de la línea de entrada
#define MAXCWD 1024         // tamaño máximo para alojar el pathname completo del directorio corriente
#define MAXWORDS 256        // cantidad máxima de palabras en la línea

int globalstatret;
char *oldpwd=NULL;
char *cwd =NULL;

int main() {
    FILE *historial;
    char str[MAXLINE];
    char dirHist[MAXLINE];
    int argc = MAXWORDS;
    char *argv[MAXWORDS];

    while(globalstatret!=10) {
        fprintf(stderr, "(minish)%s:%s>", getenv("USER"),getcwd(str,100));
        cwd=strdup(str);
        snprintf(dirHist, MAXLINE, "%s/%s",getenv("HOME"),HISTORY_FILE);
        fgets(str,MAXLINE,stdin);
        if(str!=NULL) {
            if(strcmp(str,"\n")!=0) {
                historial=fopen(dirHist,"a");
                argc =linea2argv(str,argc,argv);
                globalstatret=ejecutar(argc,argv);
                fprintf(historial,"%s\n",argv[0]);
                fclose(historial);
            }
        }
        else {
            // todo handelear error de strcmp
        }
    }

}


