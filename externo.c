#include "minish.h"

int externo(int argc, char **argv) {
    pid_t p= fork();//<0 error =0  proceso hijo > 0 proceso padre
    if(p<0){//si falla
	perror("Error al crear otro proceso");
	}
	else if(p==0){//proceso hijo el que llama  a ext
	if((execv(argv[0],argv))==-1)return -1;
	}
	else{// proceso padre (yo) tengo que esperar al hijo 
	wait(p);
	}
    return 0;
}




//fork  procesos simultaneops llamos al externo(extect) y vuelvo






