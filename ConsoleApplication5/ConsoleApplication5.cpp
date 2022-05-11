#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>

const int count_iteration = 100000000;

long long f(int arg, int b, int c) {
    if (arg == 0) return 0;
    char curarg = (char)(arg);
    char curb = (char)b;
    char curc = (char)c;
    short ress;
    long long a = 0;
    int itter1 = 100000000, itter2 = 1;
    if (2 * b + c - arg <= 3) {
        itter1 = 10001;
        itter2 = 9999;
    }
    else {
        itter1 = 1010101;
        itter2 = 99;
    }

    for (int j = 0; j < itter1; j++) {
        __asm {
            mov Bl, 2
            mov Dx, 0
            mov ECX, itter2
            L1 :
            mov al, curb
                mul bl
                Push dx
                mov dl, curc
                mov dh, 0
                add Ax, Dx
                mov dl, curarg
                mov dh, 0
                sub Ax, Dx
                pop Dx
                add Dx, Ax
                mov ress, dx
                Loop L1
        }
        a += ress;
    }
    return f(arg - 1, b, c) + a + 2 * b + c - arg;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    int b;
    int c;
    std::cout << "Введите размер:";
    std::cin >> n;
    std::cout << "Введите b:";
    std::cin >> b;
    std::cout << "Введите c:";
    std::cin >> c;
    setlocale(LC_ALL, "Russian");
    float time;
    std::cout << std::endl;
    clock_t ts = clock();
    long long result = f(n, b, c);
    time = ((float)(clock() - ts)) / CLOCKS_PER_SEC;
    std::cout << std::endl;
    std::cout << result << std::endl;
    std::cout << time * 1000 << " мс" << std::endl;
    return 0;
}