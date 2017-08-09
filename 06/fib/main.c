#include <stdio.h>

int fib_1_count = 0;

int fib_1(int n) {
    fib_1_count++;
    if (n < 2) {
        return n;
    }
    return fib_1(n - 2) + fib_1(n - 1);
}

int fib_2_count = 0;

int fib_2(int n) {
    if (n < 2) return n;
    int temp = 0, current = 1, last = 0;
    for (int i = 2; i <= n; i++) {
        fib_2_count++;
        temp = current;
        current += last;
        last = temp;
    }
    return current;
}

int memo[100] = {0,};
int fib_3_count = 0;

int fib_3(int n) {
    fib_3_count++;
    if (n < 2) return n;
    else if (memo[n] != 0) {
        return memo[n];
    } else {
        return memo[n] = fib_3(n - 1) + fib_3(n - 2);
    }
}

int main() {
    printf("fib_1 = %d fib_1_count = %d \n", fib_1(10), fib_1_count);
    printf("fib_2 = %d fib_2_count = %d \n", fib_2(10), fib_2_count);
    printf("fib_3 = %d fib_3_count = %d \n", fib_3(10), fib_3_count);
    return 0;
}