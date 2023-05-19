#include <stdio.h>
#include <stdlib.h>

typedef enum movie_genres{
    Sci_fiction,
    Western,
    Action,
    Melodrama,
    Historical,
    Finish
} movie_genres;

movie_genres ConvertString(char symbol[10]) {
    switch(symbol[0]){
        case 'S':
            return 0;
        case 'W':
            return 1;
        case 'A':
            return 2;
        case 'M':
            return 3;
        case 'H':
            return 4;
    }
}
int ind = 0;

typedef struct list {
    movie_genres value;
    struct list* next;
} list;

void PrText(list* root) {
    while (root != NULL) {
        switch (root->value) {
            case Finish:
                printf("%s", "Finish");
                break;
            case Western:
                printf("%s", "Western ");
                break;
            
            case Historical:
                printf("%s", "Historical ");
                break;

            case Action:
                printf("%s", "Action ");
                break;

            case Sci_fiction:
                printf("%s", "Sci_fiction ");
                break;
                
            case Melodrama:
                printf("%s", "Melodrama ");
                break;
        }
        root = root->next;
    }
}


list* Create() {
    list* current = (list*)malloc(sizeof(list));
    list* finish = (list*)malloc(sizeof(list));
    current->next = finish;
    finish->next = NULL;
    finish->value = Finish;
    return current;
}

void Insert(list* root, int index, list* el) {
    list* curr_el = root;
    if (curr_el->next->value != Finish) {
        for (int i = 0; i < index; i++) {
            curr_el = curr_el->next;
        }
    }
    el->next = curr_el->next;
    curr_el->next = el;
}

void Delete(list* root, int index) {
    list* curr_el = root;
    list* prev_el;
    for (int i = 0; i < index; i++) {
        prev_el = curr_el;
        curr_el = curr_el->next;
    }
    prev_el->next = curr_el->next;
}

list* Clear_list(list* root, movie_genres val) {
    list* curr = root;
    int fl = 0;
    while (curr->value != Finish) {
        if (curr->value == val) fl = 1;
        curr = curr->next;
    }
    if (fl) root = curr;
    return root;
}

int main() {
    list* root = Create();
    int n;
    FILE* myfile;
    myfile = fopen("input.txt", "r");
    fscanf(myfile, "%d", &n);
    char symbol[13];
    fscanf(myfile, "%s", symbol);
    root->value = ConvertString(symbol);
    for (int i = 0; i < n - 1; ++i) {
        char symbol[13];
        fscanf(myfile, "%s", symbol);
        list* elem = Create();
        elem->value = ConvertString(symbol);
        Insert(root, i, elem);
    }
    //Delete(root, 1);
    root = Clear_list(root, Action);
    PrText(root);
    putchar('\n');
    return 0;
}