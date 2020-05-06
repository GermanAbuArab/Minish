#include "minish.h"




struct builtin_struct builtin_arr[] = {
    { "exit", builtin_exit, HELP_EXIT },
    { "help", builtin_help, HELP_HELP },
    { "pid", builtin_pid, HELP_PID },
    { "history", builtin_history, HELP_HISTORY },
    { "dir", builtin_dir, HELP_DIR },
    { "status", builtin_status, HELP_STATUS },
    { "uid", builtin_uid, HELP_UID },
    { "getenv", builtin_getenv, HELP_GETENDV },
    { "gid", builtin_gid, HELP_GID },
    { "setenv", builtin_setenv, HELP_SETENV },
    { "unsetenv", builtin_unsetenv, HELP_UNSETENV },
    { "cd", builtin_cd, HELP_CD },
    { NULL, NULL, NULL }
};





int ejecutar(int argc, char **argv) {
  for(int i=0;i<13;i++){
    if (strcmp(argv[0], builtin_arr[i].cmd) == 0) {
        return builtin_arr[i].func(argc, argv);
    }}
      return   externo(argc, argv);
}
