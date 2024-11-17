#include <stdio.h>

void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void triRapide(int *tab, int bas, int haut) {
    if (bas >= haut) return;

    int pivot = tab[(bas + haut) / 2];
    int i = bas, j = haut;
    while (i <= j) {
        while (tab[i] < pivot){ 
		i++;
			}
        while (tab[j] > pivot) {
		j--;
			}
        if (i <= j) {
            echanger(&tab[i], &tab[j]);
            i++;
            j--;
        }
    }
    triRapide(tab, bas, j);
    triRapide(tab, i, haut);
}


void afficher(int* tab, int n){

	int i;

	for(i = 0; i < n; i++){


		printf("%d ",tab[i]);


	}

}
int main(void){

	int i;

	int tab[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, n;
	
	n = sizeof(tab) / sizeof(tab[0]);

	printf("\n----------------------------------------\n");
	printf("\navant de trier\n");		
	afficher(tab,n);
	printf("\n----------------------------------------\n");	
	printf("\napres avoir trie\n");
	printf("\n----------------------------------------\n");
	triRapide(tab, 0, n - 1);
	afficher(tab,n);
			
	return 0;
}
