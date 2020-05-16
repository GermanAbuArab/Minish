
#include "minish.h"

int externo(__attribute__((unused))int argc, char **argv) {
    pid_t p,waitp;
    int estadoretorno;
    p= fork();//<0 error,  =0  proceso hijo,  > 0 proceso padre
    if(p<0) { //si falla
        perror("Error al crear otro proceso:");
        return -1;
    }
    else if(p==0) { //proceso hijo el que llama  a ext
        if(execvp(argv[0],argv)== -1)
        {
            perror("Error al intentar ejecutar un proceso externo:");
            //exit(1);
            return -1;
                // para matar al hijo
        }
    }
    else { // proceso padre (yo) tengo que esperar al hijo
        do { // que espere al  hijo mientras
            if(( waitp=waitpid(p,&estadoretorno, WUNTRACED))==-1)
                return -1;
        } while(!WIFEXITED(estadoretorno) && !WIFSIGNALED(estadoretorno));
    }
    return estadoretorno;
}




//fork  procesos simultaneops llamos al externo(extect) y vuelvo







