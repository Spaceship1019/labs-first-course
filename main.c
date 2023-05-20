#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "person.h"

void usage()
{
printf("Usage: program filename\n");
}

int main(int argc, char * argv[]) {
    // if (argc != 2) {
    //     usage();
    //     return 1;
    // }
    FILE *in = fopen("data_base.csv", "r");
    if (!in) {
        perror("Can't open file");
        return 2;
    }
    student s;
    int marks(int a, int b, int c) {
        if (a == b || a == c || b == c) return 1;
        return 0;
    }
    //fscanf(in,"%s %c%c %c %d %d %d %d %d %d", s.surname, &s.name, &s.father_name, &s.gender, &s.school_numb,
    // &s.medal, &s.math, &s.rus, &s.inform, &s.essay) == 10;
    int ind = 1;
    while (fscanf(in,"%s %c%c %c %d %d %d %d %d %d", s.surname, &s.name, &s.father_name, &s.gender, &s.school_numb,
     &s.medal, &s.math, &s.rus, &s.inform, &s.essay) == 10) {
        //printf("%c\n", s.gender);
        if (s.gender == 'F'  && marks(s.math, s.inform, s.rus)) {
            printf("%d %s\n", ind, s.surname);
            ind++;
        }
    }  
    fclose(in);
    return 0;
}