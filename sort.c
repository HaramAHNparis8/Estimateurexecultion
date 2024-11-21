#include "sort.h"
#include "utils.h"
//la fonction pour trier les elements de tableau

//la fusion


void merge(int* tab, int* tmp, int bas, int milieu, int haut, int ordre) {
    int i = bas, j = milieu + 1, k = bas;

    while (i <= milieu && j <= haut) {
        if ((ordre > 0 && tab[i] <= tab[j]) || (ordre < 0 && tab[i] >= tab[j])) {
            tmp[k++] = tab[i++];
        } else {
            tmp[k++] = tab[j++];
        }
    }

    while (i <= milieu) {
        tmp[k++] = tab[i++];
    }
    while (j <= haut) {
        tmp[k++] = tab[j++];
    }

    for (i = bas; i <= haut; i++) {
        tab[i] = tmp[i];
    }
}

void mergeSortEncroissant(int* tab, int bas, int haut, int* tmp) {
	int mid;
    if (bas < haut) {
        mid = (bas + haut) / 2;
        mergeSortEncroissant(tab, bas, mid, tmp);
        mergeSortEncroissant(tab, mid + 1, haut, tmp);
        merge(tab, bas, mid, haut, tmp, 1);
    }
}


void mergeSortdescroissant(int* tab, int bas, int haut, int* tmp) {
    int mid;
    if (bas < haut) {
        mid = (bas + haut) / 2;
        mergeSortdescroissant(tab, bas, mid, tmp);
        mergeSortdescroissant(tab, mid + 1, haut, tmp);
        merge(tab, tmp, bas, mid, haut, -1);
    }
}

void LafusionExecutionEncroissant(int*tab, int taille){

	int* tmp = generationdetab(taille);
	mergeSortEncroissant(tab, 0, taille - 1, tmp);
	free(tmp);
}

void LafusionExecutionDesCroissant(int*tab, int taille){

	int* tmp = generationdetab(taille);
	mergeSortdescroissant(tab, 0, taille - 1, tmp);
	free(tmp);

}

// trier rapide

void echanger(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void partition(int* tab, int* bas, int* haut, int pivot, int ordre) {
    int i = *bas, j = *haut;

    while (i <= j) {
        if (ordre > 0) { 
            while (tab[i] < pivot){ 
			i++;
	 }
            while (tab[j] > pivot) {
			j--;
	}
        } 
	else { 
            while (tab[i] > pivot){
			
			i++;
		}
            while (tab[j] < pivot){
			
			j--;
		}
        }

        if (i <= j) {
            echanger(&tab[i], &tab[j]);
            i++;
            j--;
        }
    }

    *bas = i;
    *haut = j;
}

void TriRapide(int* tab, int bas, int haut, int ordre) {
    if (bas >= haut) {
        return;
    }

    int pivot = tab[(bas + haut) / 2], i = bas, j = haut;

    partition(tab, &i, &j, pivot, ordre);

    TriRapide(tab, bas, j, ordre);
    TriRapide(tab, i, haut, ordre);
}

void LaTriRapidExecutionEnCroissant(int* tab, int taille){
	
	TriRapide(tab, 0, taille - 1, 1);

}

void LaTriRapidExecutionEnDesCroissant(int* tab, int taille){
	
	TriRapide(tab, 0, taille - 1, -1);

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


