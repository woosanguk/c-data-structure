#include <stdio.h>

int main() {
    int int_val = 20;
    int *ptr_int_1 = &(int_val);
    printf("%d \n", *ptr_int_1);
    *ptr_int_1 = 10;
    printf("%d \n", *ptr_int_1);

    int int_array[10] = {0,};
    int *ptr_int_2 = &(int_array);
    *ptr_int_2 = 100;
    *(ptr_int_2 + 1) = 90;
    *(ptr_int_2 + 2) = 80;
    printf("%d \n", int_array[0]);
    printf("%d \n", int_array[1]);
    printf("%d \n", int_array[2]);
    printf("%d \n", int_array[3]);

    return 0;

}