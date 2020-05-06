#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "minish.h"
#define MAXLINE  1024        // tamaño máximo de la línea de entrada
#define MAXCWD 1024         // tamaño máximo para alojar el pathname completo del directorio corriente
#define MAXWORDS 256        // cantidad máxima de palabras en la línea



int main() {
    char str[MAXLINE];
    int argc = MAXWORDS;
    char *argv[MAXWORDS];
 	int val=0;
    while(val!=10) {
        printf("(minish) >");
        fgets(str,MAXLINE,stdin);
        if(str!=NULL) {
            argc =linea2argv(str,argc,argv);
       	    val=ejecutar(argc,argv);
       	}
        else {
            //handelear error de strcmp
        }
    }

}
