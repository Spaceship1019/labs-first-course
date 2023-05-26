
#ifndef _STEKH_
#define _STEKH_

#include <stdio.h>
#include <stdlib.h>

typedef struct LChar {
    char data;
    struct LChar * next, *left, *right;
} LChar;

int per[26];
char answer[26][100];
typedef struct Vec {
    char data[26][1000];
    Vec *next;
} Vec;

typedef struct Stek {
    struct LChar * front;
    int size;
} Stek;

typedef struct Tree {
    char value;
    Tree* left, *right;
} Tree;

int prior(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void PushChar(Stek * cur, char data) {
    LChar * tmp = (struct LChar*) malloc(sizeof(struct LChar));
    tmp->data = data;
    tmp->next = cur->front;
    cur->front = tmp;
    cur->size = cur->size + 1;
}



void Push(Stek * cur, LChar *tmp) {
    tmp->next = cur->front;
    cur->front = tmp;
    cur->size = cur->size + 1;
}

char PopChar(Stek * cur) {
    LChar *out = cur->front;
    char buf;
    if (cur != NULL && cur->front != NULL) {
        buf = out->data;
        cur->front = out->next;
        cur->size = cur->size - 1;
        free(out);

    }
    return buf;
}

char Pop(Stek * cur) {
    LChar *out = cur->front;
    char buf;
    if (cur != NULL && cur->front != NULL) {
        buf = out->data;
        cur->front = out->next;
        cur->size = cur->size - 1;

    }
    return buf;
}

void PrintStackChar(Stek * cur) {
    LChar * node = cur->front;
    printf("Stack Elements\n");
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

char PeekChar(Stek* stack) {
    if (stack->front == NULL) {
        return -1; 
    } else {
        return stack->front->data;
    }
}

int IsEmptyChar(Stek* stack) {
    return stack->front == NULL;
}

int IsSizeChar(Stek * cur) {
    return cur->size;
}

#endif