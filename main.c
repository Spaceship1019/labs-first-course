#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(){
    Queue* root = Make();
    Queue* tek = root;
    int a;
    scanf("%d", &a);
    do {
        Add(root, a);
        scanf("%d", &a);
    } while (a != 0);
    root = Result(root);
    PrintReverse(root);
    Print(tek);
}