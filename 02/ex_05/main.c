#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0, j = 0, value = 0;
    int row = 4, col = 5;

    int **pptr_int_array = (int **) malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        pptr_int_array[i] = (int *) malloc(sizeof(int) * col);
    }

    for (i = 0; i <row; i++){
        for(j = 0; j < col; j++){
            value++;
            pptr_int_array[i][j] = value;
        }
    }
    printf("%d\n", *(*(pptr_int_array + 3) + 2));
    printf("%d\n", *(*(pptr_int_array + 1) + 1));
    printf("%d\n", *(*(pptr_int_array + 3) + 4));
    return 0;
}