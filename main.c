#include <stdio.h>
#include <stdlib.h>

typedef struct table {
    int key;
    int value;
} table;

void PrintTable(table* my_tab, int size) {
    printf("KEY :  Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d       %d\n", my_tab[i].key, my_tab[i].value);
    }
}

int BinSearch(table* my_tab, int key, int size) {
    int ri = size, le = -1;
    while (le + 1 < ri) {
        int mid = (ri + le) / 2;
        if (my_tab[mid].key == key) {
            printf("Value: %d\n", my_tab[mid].value);
            return 0;
        }
        if (my_tab[mid].key < key) {
            le = mid;
        } else {
            ri = mid;
        }
    }
    printf("NO\n");
    return 1;
}

void Insertion_Sort(table* my_tab, int size) {
    for (int i = 0; i < size; i++) {
        int j = i - 1;
        int key1 = my_tab[i].key;
        int val1 = my_tab[i].value;
        while (my_tab[j].key  > key1 && j >= 0) {
            my_tab[j + 1].key = my_tab[j].key;
            my_tab[j + 1].value = my_tab[j].value;
            j -= 1;
        }
        my_tab[j + 1].key = key1;
        my_tab[j + 1].value = val1;

    }
}
int main() {
    int size;
    FILE* fi;
    fi = fopen("input.txt", "r");
    fscanf(fi, "%d", &size);
    table my_tab[size];
    for (int i = 0; i < size; i++) {
        fscanf(fi, "%d %d", &my_tab[i].key, &my_tab[i].value);
    }
    Insertion_Sort(my_tab, size);
    BinSearch(my_tab, 3, size);
    PrintTable(my_tab, size);
    return 0;
}