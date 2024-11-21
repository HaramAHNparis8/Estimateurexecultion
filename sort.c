#include "sort.h"
#include "utils.h"
//la fonction pour trier les elements de tableau

//la fusion


void merge(int* tab, int bas, int milieu, int haut) {
    
    int taille = haut - bas + 1;
    int b[taille];
    int i = bas, j = milieu + 1, k = 0;

    
    while (i <= milieu && j <= haut) {
        if (tab[i] <= tab[j]) {
            b[k++] = tab[i++];
        } 
	else {
            b[k++] = tab[j++];
        }
    }
    while (i <= milieu) {
        b[k++] = tab[i++];
    }
    while (j <= haut) {
        b[k++] = tab[j++];
    }

    
    for (i = 0; i < taille; i++) {
        tab[bas + i] = b[i];
    }
}

void mergeSortEncroissant(int* a, int low, int hight) {
    
    int mid;

    if (low < hight) {
        mid = (low + hight) / 2;
        mergeSortEncroissant(a, low, mid);
        mergeSortEncroissant(a, mid + 1, hight);
        merge(a, low, mid, hight);
    }
}

void MergeEnDecroissant(int* tab, int bas, int milieu, int haut) {
    int taille = haut - bas + 1;
    int* b = (int*)malloc(taille * sizeof(int)); 
    int i = bas, j = milieu + 1, k = 0;

  
    while (i <= milieu && j <= haut) {
        if (tab[i] >= tab[j]) {
            b[k++] = tab[i++];
        } else {
            b[k++] = tab[j++];
        }
    }

    
    while (i <= milieu) {
        b[k++] = tab[i++];
    }
    while (j <= haut) {
        b[k++] = tab[j++];
    }

    
    for (i = 0; i < taille; i++) {
        tab[bas + i] = b[i];
    }

}

void mergeSortdescroissant(int* a, int low, int hight) {
    
    int mid;

    if (low < hight) {
        mid = (low + hight) / 2;
        mergeSortdescroissant(a, low, mid);
        mergeSortdescroissant(a, mid + 1, hight);
        MergeEnDecroissant(a, low, mid, hight);
    }
}

// trier rapide

void echanger(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void TriRapideEnCroissant(int *tab, int bas, int haut) {
    if (bas > haut){ 
		return;
	}

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
    TriRapideEnCroissant(tab, bas, j);
    TriRapideEnCroissant(tab, i, haut);
}


void TriRapideDesCroissant(int *tab, int bas, int haut) {
    if (bas >= haut) { 
        return;
    }

    int pivot = tab[(bas + haut) / 2];
    int i = bas, j = haut;
    while (i <= j) {
        while (tab[i] > pivot) { 
            i++;
        }
        while (tab[j] < pivot) {
            j--;
        }
        if (i <= j) {
            echanger(&tab[i], &tab[j]);
            i++;
            j--;
        }
    }
    TriRapideDesCroissant(tab, bas, j);
    TriRapideDesCroissant(tab, i, haut);
}

void melangertout(int* tab, int taille){

	int i,j;
	for(i = taille - 1; i > 0; i--){
		
		j = rand() % (i + 1);
		echanger(&tab[i], &tab[j]);
		
	}
}

void QuickortProbabilisteSortEnordreCroissant(int* tab, int taille){
	
	melangertout(tab, taille);
	
	int i = 0,j ,IndiceMinimal = i;
	
	while(i < taille - 1){

		IndiceMinimal = i;
		j = i + 1;

		while(j < taille){
		
		    if(tab[j] < tab[IndiceMinimal]){

				IndiceMinimal = j;

			}
			j++;

		}	
	
	echanger(&tab[i],&tab[IndiceMinimal]);
	i++;

	}

}

void QuickortProbabilisteSortEnordreDesCroissant(int* tab, int taille){
	
	melangertout(tab, taille);
	
	int i = 0,j ,IndiceMinimal = i;
	
	while(i < taille - 1){

		IndiceMinimal = i;
		j = i + 1;

		while(j < taille){
		
		    if(tab[j] > tab[IndiceMinimal]){

				IndiceMinimal = j;

			}

			j++;

		}	
	
	echanger(&tab[i],&tab[IndiceMinimal]);
	i++;

	}

}

void buble_sort_croissant(int* tab, int taille){

	int echange = 1, i;
	while(echange){

		echange = 0;
		for(i = 0; i < taille - 1; i++){

			if(tab[i] > tab[i + 1]){
				
				echanger(&tab[i],&tab[i + 1]);
				echange = 1;
			}

		}
		taille--;
	}
}

void buble_sort_descroissant(int* tab, int taille){

	int echange = 1, i;
	while(echange){

		echange = 0;
		for(i = 0; i < taille - 1; i++){

			if(tab[i] < tab[i + 1]){
				
				echanger(&tab[i],&tab[i + 1]);
				echange = 1;
			}

		}
		taille--;
	}
}


