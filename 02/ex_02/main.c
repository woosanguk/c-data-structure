#include <stdio.h>

#define ROW 4
#define COL 4

int main() {
    float tables[ROW][COL] = {
            {8.1, 7,   4,   2},
            {6.5, 8.2, 2,   7},
            {10,  5,   2.5, 7},
            {7,   2,   3,   2.3}
    };

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%-5.1f ", tables[i][j]);
        }
        printf("\n");
    }

    return 0;
}