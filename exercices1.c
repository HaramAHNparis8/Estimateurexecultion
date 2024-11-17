#include <stdio.h>
#include <time.h>


int fiboR(int n) {
    if (n < 2) {
        return n;
    }
    return fiboR(n - 1) + fiboR(n - 2);
}


void echange(int *a, int *b) {
    int tmp;
    tmp = *a + *b;
    *a = *b;
    *b = tmp;
}


int fiboB(int n) {
    int c1 = 0, c2 = 1;

    if (n < 2) {
        return n;
    }
    
    for (int i = 2; i <= n; i++) {
        echange(&c1, &c2);
    }

    return c2; 
}

int main(void) {
    for (int n = 30; n <= 45; n++) {
                

	clock_t startR = clock();
        int resultR = fiboR(n);
        clock_t endR = clock();
        double timeR = (double)(endR - startR) / CLOCKS_PER_SEC;
        
        clock_t startB = clock();
        int resultB = fiboB(n);
        clock_t endB = clock();
        double timeB = (double)(endB - startB) / CLOCKS_PER_SEC;

        printf("n=%d, Recursif %.6f secondes, Result=%d\n", n, timeR, resultR);
        printf("n=%d, Iteratif %.6f secondes, Result=%d\n", n, timeB, resultB);
    }
    
    return 0;
}
