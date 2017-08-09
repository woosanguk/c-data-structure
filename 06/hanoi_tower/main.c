#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to) {
    if (n == 1) {
        printf("원판 1을 %c에서 %c로 옮겼습니다.\n", from, to);
    } else {
        hanoi_tower(n - 1, from, to, temp);
        printf("원판 %i를 %c에서 %c로 옮겼습니다\n", n, from, to);
        hanoi_tower(n - 1, temp, from, to);
    }
}

int main() {
    char from = 'A';
    char temp = 'B';
    char to = 'C';
    hanoi_tower(2, from, temp, to);
    return 0;
}