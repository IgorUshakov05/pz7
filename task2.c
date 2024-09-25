#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void childProcess() {
    printf("Child process\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
        Sleep(rand() % 3000); // Задержка от 0 до 3000 мс (0 до 3 секунд)
    }
}

int main(void) {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Создаем новый процесс
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Создаем дочерний процесс
    if (!CreateProcess(NULL, "child_process.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 1;
    }

    // Код для родительского процесса
    printf("Parent process\n");
    for (int i = 0; i < 10; i++) {
        printf("*\n");
        Sleep(rand() % 5000); // Задержка от 0 до 5000 мс (0 до 5 секунд)
    }

    printf("Parent process continues.\n");
    printf("++\n");

    // Ждем завершения дочернего процесса
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0; // Завершение родительского процесса
}
