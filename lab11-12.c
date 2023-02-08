#include <stdio.h>

int main() {
    int c = 'a';
    int ans = 0;
    int fl = 1;

    while (1)
    {
        c = getchar();
        if (с >= 'A' and c <= 'Z') {
            ans++;
        } 
       
        if (c == EOF) {
            printf("%d\n", ans);
            break;
        }
    }

    return 0;
}