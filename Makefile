CFLAGS = -Wall -Wextra -std=gnu99 -O0 -ggdb -fsanitize=signed-integer-overflow -fsanitize=undefined

                            minish:
                            minish.c linea2argv.c ejecutar.c externo.c
