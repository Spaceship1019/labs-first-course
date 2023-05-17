#include <stdio.h>
#define SIZE 100

int main(void) {
    FILE *myfile;
    myfile = fopen("input.txt", "r");
    int n, m;
    fscanf(myfile, "%d %d", &n, &m);
    int value;
    int first_arr_ind[SIZE], frst_arr_val[SIZE];
    int ind = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fscanf(myfile, "%d", &value);
            if (value != 0) {
                first_arr_ind[ind] = (i - 1) * m + j - 1;
                frst_arr_val[ind] = value;
                ind++;
            }
        }
    }

    int a, b;
    fscanf(myfile, "%d %d", &a, &b);
    int second_arr_ind[SIZE], second_arr_val[SIZE];
    int second_ind = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            fscanf(myfile, "%d", &value);
            if (value != 0) {
                second_arr_ind[second_ind] = (i - 1) * b + j - 1;
                second_arr_val[second_ind] = value;
                second_ind++;
            }
        }
    }
    if (a != m) {
        printf("Умножение невозможно\n");
    } else {
        int x, y, x2, y2;
        int index, index2;
        int eend_ind[SIZE], eend_val[SIZE];
        int eend_count = 0;
        for (int str = 1; str <= n; ++str) {

            for (int clmn = 1; clmn <= b; ++clmn) {
                int sum = 0;
                for (int i = 0; i < ind; i++) {
                    index = first_arr_ind[i];

                    x = (index / m) + 1;
                    y = (index % m) + 1;

                    for (int i2 = 0; i2 < second_ind; i2++) {
                        index2 = second_arr_ind[i2];

                        x2 = (index2 / b) + 1;
                        y2 = (index2 % b) + 1;
                        if ((y == x2) && ((x == str) && (y2 == clmn))) {
                            sum += frst_arr_val[i] * second_arr_val[i2];
                        }
                    }
                }

            if (sum != 0) {
                eend_ind[eend_count] = (str - 1) * b + clmn - 1;
                eend_val[eend_count] = sum;
                eend_count++;
            }
            }
        }
        printf("\n");


        printf("Первая матрица в представлении двух векторов:\n");
        for (int i = 0; i < ind; i++) {
            printf("%d -> %d\n", first_arr_ind[i], frst_arr_val[i]);
        }
        printf("\n");

        printf("Вторая матрица в представлении двух векторов:\n");
        for (int i = 0; i < second_ind; i++) {
            printf("%d -> %d\n", second_arr_ind[i], second_arr_val[i]);
        }
        printf("\n");

        printf("Итоговая матрица в представлении двух векторов:\n");
        for (int i = 0; i < eend_count; i++) {
            printf("%d -> %d\n", eend_ind[i], eend_val[i]);
        }
        printf("\n");
        
        int x_res, y_res, res_ind  = 0;
        printf("Итоговая матрица в классическом представлении:\n");
         for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= b; j++) {
                x_res = (eend_ind[res_ind] / b) + 1;
                y_res = (eend_ind[res_ind] % b) + 1;
                if (i == x_res && j == y_res) {
                    printf ("%d ", eend_val[res_ind]);
                    res_ind++;
                } else {
                    printf ("0 ");          
                }
                
            }
            printf("\n");  
        }
        printf("\n");
        printf("Кол-во ненулевых элементов в произведении:\n");
        printf("%d %s ", eend_count, "\n");
    }
    return 0;
}