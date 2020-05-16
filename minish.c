#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include "minish.h"
#define MAXLINE  1024        // tamaño máximo de la línea de entrada
#define MAXCWD 1024         // tamaño máximo para alojar el pathname completo del directorio corriente
#define MAXWORDS 256        // cantidad máxima de palabras en la línea

int globalstatret;
char *oldpwd=NULL;
char *cwd =NULL;
int argc;


void signal_handler(int sig) {
    printf(" Signal number: %d\n", sig);
    argc = 0;
    return;
}

int main() {
    FILE *historial;
    char str[MAXLINE];
    char dirHist[MAXLINE];
    int argc = MAXWORDS;
    char *argv[MAXWORDS];
    struct sigaction new_action;
    new_action.sa_handler = signal_handler;
    snprintf(dirHist, MAXLINE, "%s/%s",getenv("HOME"),HISTORY_FILE);
    historial=fopen(dirHist,"a");

    while(globalstatret!=10) {

        if (sigaction(SIGINT, &new_action, NULL) == -1) {
            continue;
        }



        // sigaction(SIGINT, &new_action, NULL);
        //------------------------------///
        fprintf(stderr, "(minish)%s:%s>", getenv("USER"),getcwd(str,100));
        cwd=malloc(strlen(str)+1);
        strcpy(cwd,str);
        fgets(str,MAXLINE,stdin);
        if(str!=NULL) {


            if(strcmp(str,"\n")!=0) {
                argc =linea2argv(str,argc,argv);
                if (strcmp(argv[0],"exit")==0)
                {
                    fclose(historial);
                    free(cwd);
                }
                globalstatret=ejecutar(argc,argv);
                fprintf(historial,"%s\n",argv[0]);



            }
        }

        else {
            // todo handelear error de strcmp
        }
        free(cwd);
    }



}

