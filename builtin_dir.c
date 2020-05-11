#include "minish.h"

//todo cambiar

int builtin_dir (int argc, char ** argv) {
    DIR *d;
    struct dirent *dir;
    printf("DIR %s\n", getenv("PWD"));
    d = opendir(getenv("PWD"));                         //abro directorio actual
    char *cont[1000];                           //array de contenido para ordenar alfabeticamente
    int i = 0;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)     //uso readdir para leer su contenido
        {
            if(argc<=1) {
                cont[i++] = dir->d_name;             //agrego a array
            } else {
                if(strstr(dir->d_name, argv[1]))   //si hay una parte de una palabra imprimo aca
                    cont[i++] = dir->d_name;
            }
        }

        closedir(d);
        if( i > 0) {
            qsort(cont, i, sizeof(char*), myCompare);       //qsort es una funcion del sistema que ordena usando quicksort, o sea que se hace $
            for (int inx = 0; inx < i; inx++)
                printf("%s\n", cont[inx]);
        }
        return 0;
    }
    return -1;
}