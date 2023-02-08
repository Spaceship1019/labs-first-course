#include <stdio.h> 
#include <math.h> 

#define START 0.0
#define END 1.0
#define STEP 0.01

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

long double MyPow(long double x, int y) { 
    long double z = 1; 
    while (y > 0) { 
        if (y & 1) { 
            z *= x; 
        } 
        x *= x; 
        y = y >> 1; 
    } 
    return z; 
} 

long double Abs(long double a){
	return a < 0 ? -1 * a : a; 
}

int main(){
    printf("%s", "    x    ");
    
	printf("%s","  | част. сумма ряда");

	printf("%s", "  |    значение функции");

	printf("%s", "   | число итераций |\n");


	long double e = MachineEpsilon();
	for (long double x = START; x <= END; x += STEP) {
		long double taylor = 0, xn = x, fact = 1, elem = 1;
		int it = 0;
		for (int n = 2; n < 100 && elem > e; ++n) {
			taylor += elem;
			xn *= x;
			fact *= n+1;
			elem = MyPow(xn, 2* n) * (2* n + 1) / fact;
			it++;
		}
		long double bi = (1 + 2 * MyPow(x, 2)) * exp(MyPow(x, 2));
		printf("| %.3Lf | %.20Lf | %.20Lf | %d", x, taylor, bi, it);
		for (int i = log10(it); i < 14; ++i) {
			printf(" ");
		}
		printf("|\n");
	}

}
