#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./solve-hanoi <disk-count>\n");
        exit(EXIT_FAILURE);
    }
    int count = atoi(argv[1]);
    if (count < 0) {
        printf("Negative disk-count is not allowed\n");
        exit(EXIT_FAILURE);
    }
    if (count > 20) {
        printf("> 20 is too slow!\n");
        exit(EXIT_FAILURE);
    }
    hanoi_t hanoi = hanoi_init(count);
    hanoi_print(hanoi);
    hanoi_solve(hanoi);
    hanoi = hanoi_destroy(hanoi);
    return 0;
}

/*	--- Tasa de Ejecucion ---
*	(24 direct, 24 indirect) bytes in 1 blocks are definitely lost in loss record 2 of 2
*	at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so) 
*	by 0x1092BB: stack_push (stack.c:20) <-- stack.c Ya fue implementado y no tenia memory leaks, posiblemente el error este en move (hanoi.c)
*	by 0x10971E: move (hanoi.c:63) <-- linea 63 en hanoi.c
*	by 0x109752: move (hanoi.c:65) <-- linea 65 move en hanoi.c
*	by 0x10960A: hanoi_solve (hanoi.c:39) <-- hanoi_solve llama a move en hanoi.c
*	by 0x109CDE: main (main.c:21) <-- la funcion main llama a hanoi_solve
*	--- Errores en hanoi.c: No se inicializaban los stacks y tampoco se destruian ---
*/
