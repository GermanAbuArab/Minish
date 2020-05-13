#include "minish.h"


int builtin_exit(int argc, char **argv) {
    char *endptr[MAXLINE];
    if (argc==1) {
        exit(0);
    }
    else {
        if(strtol(argv[1],endptr,10)==0){// si devuelve 0 o argv[1] es  0 o no  es un numero (nptr=argv[1]!='\0') 
 	    if(strcmp(argv[1],"0")!=0){ //Verifico si strcmp no era 0 y si era un numero
  	     	printf("A exit se le deberia un parametro numerico, ojo al tejo la proxima vez\n");
	    }
            exit(0);
        }
        else {
	   exit(atoi(argv[1]));

        }
    }
}
