#include "minish.h"

void printlines(FILE * h,int cantComAnteriores) {
    char *liner[MAXLINE];
    char line[MAXLINE];
    int indice =NULL ;
    while((fgets(line,MAXLINE,h) != NULL)) {
        if(indice==NULL) {
            indice=0;
        }
        liner[indice]=strdup(line);
        indice++;
    }
    if(indice!=NULL) {
        for (int i = indice-cantComAnteriores; i <indice; i++)
        {
            if(i>=0)
                printf("%s\n",liner[i]);
        }
    }
}

int builtin_history(int argc, char **argv)
{

    FILE *h;
    char  nombre[MAXLINE];
    int cantComAnteriores = 0;

    if (argc ==2) {
        cantComAnteriores = atoi(argv[1]);   // se mando un segundo argumento entonces lo pongo como cantidad de comandos anteriores
    }
    else if (argc == 1)
    {
        cantComAnteriores = 10;   // no se manda un  segundo argumento entonces por defecto es 10
    }
    else {
        printf("%s solo lleva un argumeto usted puso %d \n",argv[0],argc );  // se le pasaron mas argumentos de los necesarios
        return -1;
    }

    snprintf(nombre,MAXLINE, "%s/%s",getenv("HOME"),HISTORY_FILE); // uno los strings y lo guardo en nombre

    h = fopen(nombre, "r");  //abro el archivo y lo guardo en h con "r" por que es lectura
    if(h == NULL) { // si hubo un error
        perror("Error al abrir nombre");
        return-1;
    } else {
        printlines(h,cantComAnteriores);
    }

    return 0;
}


//franri estuvo aqui
