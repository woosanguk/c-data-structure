#include <stdio.h>
#include <stdlib.h>

int main() {
    int **tables = NULL;
    int col = 4, row = 5;

    tables = (int **) malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        tables[i] = (int *) malloc(sizeof(int) * col);
    }

    int val = 0;


    for (int i = 0; i < row; i++) {
        val++;
        for (int j = 0; j < col; j++) {
            tables[i][j] = val;
//            *(*tables + 3) + 4 = val;
        }
    }

    printf("%d \n", tables[0][0]);
    printf("%d \n", *(*tables));
    printf("%d \n", tables[3][4]);
    printf("%d \n", *(*tables + 3) + 4);

    *(*tables + 2) = 4;

    printf("%d \n", tables[3][0]);

//    printf("1234");
//    for (int i = 0; i < row; i++) {
//
//    }
    return 0;
}