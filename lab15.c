#include <stdio.h>
 
int main(void){
    int N;
    int i, j, n, k, t;
    
    scanf("%i", &n);
    int m[n * n - 1];
    int arr[n];
    for (k = 0; k != n * n; ++k) scanf("%d", m + k);
    
    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j) {
            if (i == j) {
                t = m[i * n + j];
                m[i * n + j] = m[i * n + (n - 1 - j)];
                printf("%d\n", m[i * n + (n - 1 - j)]);
                m[i * n + (n - 1 - j)] = t;
            }
            
        }
    }
    
    for (k = 0; k != n * n; ++k) {
        printf("%d ", m[k]);
        if (k % n == n - 1) putchar('\n');
    }
    
    return 0;
}
