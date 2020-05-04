#define MAXLINE 1024        // tamaño máximo de la línea de entrada
#define MAXCWD 1024         // tamaño máximo para alojar el pathname completo del directorio corriente
#define MAXWORDS 256        // cantidad máxima de palabras en la línea
#define HISTORY_FILE    ".minish_history"   // nombre del archivo que almacena historia de comandos
#define MAXARG 100

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <error.h>
#include <errno.h>
#include <signal.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minish.h"

int builtin_exit (int argc, char ** argv) {

}

int builtin_help (int argc, char ** argv) {

}

int builtin_history (int argc, char ** argv) {

}

int builtin_status (int argc, char ** argv) {

}

int builtin_cd (int argc, char ** argv) {

}

int builtin_dir (int argc, char ** argv) {

}

int builtin_getenv (int argc, char ** argv) {

}

int builtin_gid (int argc, char ** argv) {

}

int builtin_setenv (int argc, char ** argv) {

}

int builtin_pid (int argc, char ** argv) {

}

int builtin_uid (int argc, char ** argv) {

}

int builtin_unsetenv (int argc, char ** argv) {

}

int ejecutar (int argc, char ** argv) {
printf("%s",argv[0]);
    if (strcmp(argv[0], "exit") == 0)
    {
        // do something
    }
    else if (strcmp(argv[0], "pid") == 0)
    {
   	printf("hola");
    }

    else if (strcmp(argv[0], "uid") == 0)
    {
        // do something else

    }

    else if (strcmp(argv[0], "getenv") == 0)
    {
        // do something else
    }

    else if (strcmp(argv[0], "setenv") == 0)
    {
        // do something else
    }

    else if (strcmp(argv[0], "cd") == 0)
    {
        // do something else
    }

    else if (strcmp(argv[0], "status") == 0)
    {
        // do something else
    }

    else if (strcmp(argv[0], "help") == 0)
    {
        // do something else
    }

    else if (strcmp(argv[0], "dir") == 0)
    {
        // do something else
    }

    else if (strcmp(argv[0], "history") == 0)
    {
        // do something else
    }
   
    else /* default: */
    {
        externo(argc,argv);
    }





}

int externo (int argc, char ** argv) {

}

int linea2argv(char *linea, int argc, char ** argv) {
    int N=0;
    int i=0;
    int enpalabra;
    while(*linea != '\0') {
        if(*linea == ' ' || *linea == '\t'){
	*linea='\0';
	 linea ++;
	}
	else if(*linea){
        argv[i]=linea;
        i++;
        N++;
	}
        while(*linea !=' ' && *linea !='\t' && *linea !='\n') {
            linea++;
        }
    }
    return N;
}

