#include "minish.h"


struct builtin_struct builtin_arr[] = {
    { "exit", builtin_exit, HELP_EXIT },
    { "help", builtin_help, HELP_HELP },
    { "pid", builtin_pid, HELP_PID },
    { "history", builtin_history, HELP_HISTORY },
    { "dir", builtin_dir, HELP_DIR },
    { "status", builtin_status, HELP_STATUS },
    { "uid", builtin_uid, HELP_UID },
    { "getenv", builtin_getenv, HELP_GETENV },
    { "gid", builtin_gid, HELP_GID },
    { "setenv", builtin_setenv, HELP_SETENV },
    { "unsetenv", builtin_unsetenv, HELP_UNSETENV },
    { "cd", builtin_cd, HELP_CD },
    { NULL, NULL, NULL }
};

int flag=0;

void interrumpir() {
    flag = 1;
    printf("Se interrumpio una funcion interna");
}

void interrumpir2() {
    printf("Se quiso interrumpir una funcion externa");
}

int ejecutar(__attribute__((unused))int argc, char **argv) {
    flag=0;
    for(int i=0; i<12; i++) {
        if (strcmp(argv[0], builtin_arr[i].cmd) == 0) {

            signal(SIGINT,interrumpir);
            if(flag!=1)
                return  builtin_arr[i].func(argc, argv);
            else return 0;
        }
    }
    signal(SIGINT,interrumpir2);
    return externo(argc, argv);

}
