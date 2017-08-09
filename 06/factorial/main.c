#include <stdio.h>


void factorial_1(int n) {
    int answer = 1;
    for (int i = 1; i <= n; i++) {
        answer = answer * i;
    }
    printf("factorial_1 answer = %d\n", answer);
}

int factorial_2_count = 0;

int factorial_2(int n) {
    factorial_2_count++;
    int ret = 0;
    if (n <= 1) {
        ret = 1;
    } else {
        ret = n * factorial_2(n - 1);
    }
    return ret;
}

int main() {
    factorial_1(10);
    printf("factorial_2 answer = %d factorial_2_count = %d \n", factorial_2(10), factorial_2_count);
    return 0;
}