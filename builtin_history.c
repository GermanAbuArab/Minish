#include "minish.h"
#define SIZE 100
int builtin_history(int argc, char **argv)
{
    
    FILE *h;
    char * nombre[SIZE];
    int cantComAnteriores = 0;
    char line[MAXLINE];

     if (argc ==2){       

        cantComAnteriores = atoi(argv[1]);   // se mando un segundo argumento entonces lo pongo como cantidad de comandos anteriores
    }
    else if (argc == 1)
    {
        cantComAnteriores = 10;   // no se manda un  segundo argumento entonces por defecto es 10
    }
    else{
        printf("%s solo lleva un argumeto usted puso %d \n",argv[0],argc );  // se le pasaron mas argumentos qe los necesarios
        return -1;
    }
    snprintf(nombre, SIZE, "%s/%s", getenv("HOME"), HISTORY_FILE); // uno los strings y lo guardo en nombre
    h = fopen(nombre, "r");  //abro el archivo y lo guardo en h con "r" por que es lectura
    if(h == NULL){  // si hubo un error
        printf('Error al abrir nombre');
        return-1;
    }else{
        printlines(MAXLINE,h,cantComAnteriores);
    }

    return 0;
}

void printlines(int SIZE,FILE h,int cantComAnteriores){
    char liner[MAXLINE];
    int indice =0;
    while(fgets(line,SIZE,h) != NULL){
        liner[indice++]=strdup(line);
    }
    for (int i = indice; i >=indice-cantComAnteriores; i--)
    {
        printf("%s\n",liner[i]);
    }

}
