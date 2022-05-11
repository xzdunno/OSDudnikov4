#include <iostream>
using namespace std;
long long Func(int i) {
    int b = 3, c = 3;
    if (i == 0) return 0;
    long long a = 0;
    for (long j = 1; j <= 100000000; j++) {
        a += long long(2 * b + c - i);
    }
    return Func(i - 1) + a;
}
int main()
{
    clock_t ts = clock();
    cout << Func(5) << "\n";
    float time = ((float)(clock() - ts)) / CLOCKS_PER_SEC;
    cout << time;
}