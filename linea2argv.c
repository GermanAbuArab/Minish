#include "minish.h"

int linea2argv(char *linea, int argc, char ** argv) {
    int i=0;
    char *lineaCopia =linea;
    int enpalabra=0;
    while(*lineaCopia != '\0') {
        if(*lineaCopia == ' ' || *lineaCopia == '\t' || *lineaCopia == '\n') {
            *lineaCopia='\0';
            lineaCopia ++;
            enpalabra=0;
        }
        else if(enpalabra==0) {
            argv[i]=lineaCopia;
            i++;
            enpalabra =1;
        } else {
            lineaCopia++;
        }
    }
    argv[i]=NULL;
    argc=i;
    return i;
}
