#include <stdio.h>
#include <stdlib.h>
#include <process.h> 

int main(void) {
    int pid = _spawnl(_P_WAIT, "child_process.exe", "child_process.exe", NULL);
    
    if (pid < 0) {
        perror("spawn");
        exit(1);
    }

    printf("Parent process\n");
    for (int i = 0; i < 10; i++) {
        printf("*\n");
    }

    printf("Parent process continues.\n");
    printf("++\n");
    return 0; 
}
