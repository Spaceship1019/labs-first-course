#include <stdio.h>

int main()
{
    int n, k, t;
    scanf("%d", &n);
    int m[n * n];
    for (int i = 0; i < n * n; ++i) {
        scanf("%d", &m[i]);
    }
    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
        printf("%d ", m[i * n + j]);
        j++;
    }
    putchar('\n');
    int up = 1;
    int i = 1;
    j = n - 1;
    int fl = 1;
    do {
        if (up == 1) {
            j = n - 1;
            while (i < n) {
                printf("%d ", m[i * n + j]);
                if (i == 0 && j == 0) {
                    break;
                }
                j--;
                i++; 
                
                 
            }
            
            if (i == 0 && j == 0) {
                    break;
            }
            i = n - j - 2;
            
            up = 0;
            
        } else {
            j = 0;
            //printf("%d\n", i);
            while (i >= 0) {
                printf("%d ", m[i * n + j]);
                if (i == 0 && j == 0) {
                    fl = 0;
                }
                j++;
                i--;
            } 
            
            
            up = 1;
            i = n - j + 1;
            if (i == 0 && j == 0) {
                    fl = 0;
                }
            
        }
        if (fl == 0) break;
        putchar('\n');
    } while (i != 0 || j != 0);
    return 0;
}
