CFLAGS = -Wall -Wextra -std=gnu99 -O0 -ggdb -fsanitize=signed-integer-overflow -fsanitize=undefined

minish:minish.c linea2argv.c ejecutar.c externo.c builtin_exit.c builtin_help.c builtin_history.c builtin_status.c builtin_cd.c builtin_dir.c builtin_getenv.c builtin_gid.c builtin_setenv.c builtin_pid.c builtin_uid.c builtin_unsetenv.c

