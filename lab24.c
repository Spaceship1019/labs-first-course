#include "stek.h"
#include <stdio.h>
#include "string.h"

void PolishNote(char c, char *vi, Stek *stck) {
    c = getchar();
    while (c != '\n') {
        if (((c >= '0') && (c <= '9')) || (('a' <= c) && (c <= 'z'))) {
            if ('a' <= c && c <= 'z') {
                if (per[c - 'a'] != 1) per[c - 'a'] = 1;
            }
            *vi = c;
            vi = vi + 1;
        } else {
            if (prior(PeekChar(stck)) < prior(c)) {
                PushChar(stck, c);
            } else {
                while (prior(PeekChar(stck)) >= prior(c)) {
                    *vi = PopChar(stck);
                    vi = vi + 1;
                }
                PushChar(stck, c);
            }
            
            
            
        }

        c = getchar();
    }
    while (not(IsEmptyChar(stck))) {
        *vi = PopChar(stck);
        vi = vi + 1;
    }
}

Stek* BuildTree(char *res, int sizee) {
    Stek * st = (Stek*) malloc(sizeof(Stek));
    for (int i = 0; i < sizee; i++) {
        if (prior(res[i]) != 0) {
            LChar * stnew = (LChar*) malloc(sizeof(LChar));
            LChar * x = (LChar*) malloc(sizeof(LChar));
            LChar * y = (LChar*) malloc(sizeof(LChar));  
            if (st->front->left == NULL) {
                x->data = PopChar(st);
                
                
            } else {
                x = st->front;
                Pop(st);
            }
            
            if (st->front->left == NULL) {
                y->data = PopChar(st);
                
            } else {
                y = st->front;
                Pop(st);
            }  
            stnew->right = x;
            stnew->left = y;
            stnew->data = res[i];
            Push(st, stnew);
        } else {
            PushChar(st, res[i]);
        }
    }
    return st;
}

void Print(LChar * st) {
    if (st->data == '^') {
        int i = 0;
        while (answer[st->left->data - 'a'][i] != '\000') {
            i++;
        }
        answer[st->left->data - 'a'][i] = st->right->data;
    } else {
        if (st->left != NULL) Print(st->left);
        if (st->right != NULL) Print(st->right);
    }
}

int main() {
    // FILE * fl;
    // fl = fopen("input.txt", "r");
    int n = 100;
    char str;
    printf("%s", "Введите размер строки: ");
    int sizee;
    scanf("%d\n", &sizee);
    char res[n];
    Stek * mystek = (Stek*) malloc(sizeof(Stek));
    PolishNote(str, &res[0], mystek);
    Stek* t = BuildTree(res, sizee);
    Print(t->front);
    for (int i = 0; i < 26; i++) {
        if (per[i] == 1 && answer[i][0] != '\000') {
            char r = 'a' + i;
            if (i != 0) printf("*%c", r);
            else printf("%c", r);
            printf("%s", "^(");
            int j = 0;
            while (answer[i][j] != '\000') {
                if (j != 0 ) printf("+%c", answer[i][j]);
                else {
                    printf("%c", answer[i][j]);
                }
                j++;
            }
            printf("%s", ")");
        }
        
    }
    putchar('\n');
    printf("%s\n", res);
}