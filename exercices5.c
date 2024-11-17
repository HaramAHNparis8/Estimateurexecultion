#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"
#define taillesum 4 // la taille de le tableau our stocker le moyen 
#define taillecroissant 4 // la taille de tableau pour stocker le temps pris dans l'ordre de croissant   
#define tailledescroissant 4 // la taille de tableau pour stocker le temps pris dans l'ordre de descroissant 

//la fonction pour retourner la taille de tableau

int returntaille(){ //la fonction pour entrer la taille
	
	int taille;

	printf("\nentrez la taille de tableau\n");
	printf("\n\n->  ");
	scanf("%d", &taille);

	
	return taille;
}

// la fonction pour remplir les elements de tableaux
//generer le tableau, remplir les elements au tableau et retourner le tableau par la pointeur

//la premier proposition

int* generationdetab(int taille){ 


	int i;
	int* tab = (int*)malloc(taille * sizeof(int));	
	//int* tab = malloc(taille * sizeof(int)); 
	
	for(i = 0; i < taille; i++){

		tab[i] = rand() % 10000;

	}

	return tab;
}

//la deuxiement proposition

void RemplirLesTab(int* tab, int taille){

	int i;

	for(i = 0; i < taille; i++){ 
		
		tab[i] = rand() % 1000;


	}


}
// troisieme proposition
void remplirRecTab(int taille, int* tab){

	if(taille == 0){
		return;
	}
	tab[taille - 1] = rand() % 1000;
	
	remplirRecTab(taille - 1,tab);
}

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

    free(b);  
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


//les fonctions pour initialiser les tableaux copier les tableau original

int* CopierLeTab(int* tab, int taille){
	
	int i;
	int* copier = (int *)malloc(taille * sizeof(int));

	for(i = 0; i < taille; i++){

		copier[i] = tab[i];
		
	}

	return copier;

}



void CopierTab(int* oringinal,int* copier ,int taille){

	int i;	

	printf("\n--------------------------------------------------\n");
	printf("\n\n---------> l'ordre de lst est initialise <--------\n\n");
	printf("\n--------------------------------------------------\n");

	for(i = 0; i < taille; i++){
		
		copier[i] = oringinal[i];

	}
	printf("\n\n\nle resultat de l'initialisation\n\n\n");	
}

//afficher les elements de tableau

void affichagederes(int* tab,int taille){

	int i;

	
	
	printf("\n-------------les elements de tableau-------------\n\n");
	for(i = 0; i < taille; i++){


		printf("%d ", tab[i]);


	}
	printf("\n");
	printf("\nle nombre d'elements de tab\n");
	printf("\n-> %d\n\n", taille);
}

//les fonctions pour estimer des temps pris 

double EstimationMergeSortEncroissant(int* tab,int taille){ 

// la fonction pour estimer le temps pris de la fusion en l'ordre croissant
	
	printf("\n-------------------La fusion---------------------\n");
	affichagederes(tab,taille);
	clock_t debut = clock();
	mergeSortEncroissant(tab, 0, taille - 1);
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla fusion en croissant triee %f seconds\n", tempspris);
	
	return tempspris;	
}

double EstimationMergeSortDescroissant(int* tab,int taille){

// la fonction pour estimer le temps pris de la fusion en l'ordre descroissant
	printf("\n\n--------------en l'ordre descroissant-------------\n\n");


	affichagederes(tab,taille);
	clock_t debut = clock();
	mergeSortdescroissant(tab, 0, taille - 1);
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla fusion en descroissant triee %f seconds\n", tempspris);
	
	return tempspris;
	
}
double EstimationBublesortEncroissant(int* tab,int taille){
	printf("\n\n--------------en l'ordre croissant-------------\n\n");


	affichagederes(tab,taille);
	clock_t debut = clock();
	buble_sort_croissant(tab,taille);
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla fusion en descroissant triee %f seconds\n", tempspris);
	
	return tempspris;


}
double EstimationLafusionSortDescroissant(int* tab, int taille){
// la fonction pour estimer le temps pris de la fusion en l'ordre descroissant
	printf("\n\n--------------en l'ordre descroissant-------------\n\n");


	affichagederes(tab,taille);
	clock_t debut = clock();
	mergeSortdescroissant(tab, 0, taille - 1);
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla fusion en descroissant triee %f seconds\n", tempspris);
	
	return tempspris;
	
}
double EstimationTriRapideEncroissant(int* tab,int taille){
	printf("\n\n-----------------Tri Rapide----------------------\n\n");	
	
	affichagederes(tab,taille);
	
	clock_t debut = clock();
	TriRapideEnCroissant(tab, 0, taille - 1);
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla tri Rapide en croissant triee %f seconds\n", tempspris);
	
	return tempspris;

}

double EstimationTriRapideDescroissant(int* tab,int taille){
	
	affichagederes(tab,taille);
	
	clock_t debut = clock();
	TriRapideDesCroissant(tab, 0, taille - 1);	
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla tri Rapide en descroissant triee %f seconds\n", tempspris);
	
	return tempspris;

}

double EstimationEncroissant(int* tab,int taille){
	
	affichagederes(tab,taille);
	clock_t debut = clock();
	TriRapideDesCroissant(tab, 0, taille - 1);	
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla tri Rapide en descroissant triee %f seconds\n", tempspris);
	
	return tempspris;


}

double EstimationEncroissantQuicksort(int* tab,int taille){
	
	affichagederes(tab,taille);
	clock_t debut = clock();
	QuickortProbabilisteSortEnordreCroissant(tab,taille);
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla QuickSort en croissant triee %f seconds\n", tempspris);
	
	return tempspris;


}

double EstimationDesCroissantQuicksort(int* tab,int taille){
	
	affichagederes(tab,taille);
	clock_t debut = clock();
	QuickortProbabilisteSortEnordreDesCroissant(tab,taille);
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla QuickSort en descroissant triee %f seconds\n", tempspris);
	
	return tempspris;


}

double EstimationEnCroissantBubleSort(int* tab, int taille){
	affichagederes(tab,taille);
	clock_t debut = clock();
	buble_sort_croissant(tab, taille);	
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla BubleSort en croissant triee %f seconds\n", tempspris);
	
	return tempspris;

}

double  EstimationDesCroissantBubleSort(int* tab, int taille){

	affichagederes(tab,taille);
	clock_t debut = clock();
	buble_sort_descroissant(tab, taille);	
	clock_t fin = clock();
	double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
	affichagederes(tab,taille);
	printf("\nla BubleSort en Descroissant triee %f seconds\n", tempspris);
	
	return tempspris;

}
double min(double* tab,int taille){
	int i;
	double min = tab[0];
	
	for(i = 0; i < taille; i++){

		if(tab[i] < min){

			min = tab[i];

		}
		

	}

	return min;
}

//la fonction pour rechercher la postion

int Estdans(double* tab, int taille, double min){
	if(min == tab[taille]){
		
		return taille;
	}
	else{
		return Estdans(tab, taille - 1,min);
	}
}

int EstdansTaille(double* tab, int taille, double min){
		
		return Estdans(tab,taille - 1, min);
}

//la fonction pour verifier le tab est bien trie en ordre croissant

int estOrdreCroissant(int* tab, int taille){
	int i;

	for(i = 0; i < taille - 1; i++){

		if(tab[i] < tab[i + 1]){
			return (tab[i] > tab[i + 1]) ? 0 : 1; // c'est appris PIA
		}

	}
	return printf("");
}

int estOrdreDesCroissant(int* tab, int taille){
	int i;

	for(i = 0; i < taille - 1; i++){

		if(tab[i] > tab[i + 1]){
			return (tab[i] < tab[i + 1]) ? 0 : 1; // c'est appris PIA
		}

	}
	return printf("");

}

// la fonction pour verifier que le tableau est bien trie ou non

int CompareEnOrdreCroissant(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int CompareEnOrdreDesCroissant(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}



void comparaison(int* tab,int taille){
	
	int* copier = (int *)malloc(taille * sizeof(int));
	int i;
	double tabsum[taillesum],sum, Resfusioncroissant, Resfusiondescroissant,ResTriRapideEnCroissant,ResTriRapiDesCroissant,ResQuickortProbabilisteEncroissant,ResQuickortProbabilisteEnDesCroissant,ResBubleSortEnCroissant,ResBubleSortDesCroissant,tabcroissant[taillecroissant],tabdesecroissant[tailledescroissant];

	melangertout(tab,taille);
	CopierTab(tab,copier,taille);// j'use cette proposition parce que cette fonction n'a pas besoin de la memoire
	Resfusioncroissant = EstimationMergeSortEncroissant(copier,taille);
//la fonction pour intialiser la lst 
	//la fonction pour initialiser les tableaux c'est la premiere propostion
	CopierTab(tab,copier,taille);
//la fonction pour initialiser les tableaux c'est la deuxieme propostion
	//copier = CopierLeTab(tab,taille);
	//affichagederes(copier,taille);
	Resfusiondescroissant = EstimationMergeSortDescroissant(copier,taille);
	tabcroissant[0] = Resfusioncroissant;
	tabdesecroissant[0] = Resfusiondescroissant;
	sum = (Resfusioncroissant + Resfusiondescroissant) / 2;
	tabsum[0] = sum;//le tableau pour stocker les informations de moyen
	printf("\nresultat de temps pris en moyen \n\n-> %f \n", sum);
	sum = 0;
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	printf("\n\n");
	ResTriRapideEnCroissant = EstimationTriRapideEncroissant(copier,taille);
	printf("\n\n");
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResTriRapiDesCroissant = EstimationTriRapideDescroissant(copier,taille);
	sum = ResTriRapideEnCroissant + ResTriRapiDesCroissant / 2;
	tabcroissant[1] = ResTriRapideEnCroissant;
	tabdesecroissant[1] = ResTriRapiDesCroissant;
	printf("\nresultat de temps pris en moyen \n\n-> %f \n", sum);
	tabsum[1] = sum;
	sum = 0;
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResQuickortProbabilisteEncroissant = EstimationEncroissantQuicksort(copier,taille);
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResQuickortProbabilisteEnDesCroissant = EstimationDesCroissantQuicksort(copier,taille); 
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	sum = ResQuickortProbabilisteEncroissant + ResQuickortProbabilisteEnDesCroissant / 2; 
	tabsum[2] = sum;
	printf("\nresultat de temps pris en moyen \n\n-> %f \n", sum);
	tabcroissant[2] = ResQuickortProbabilisteEncroissant;
	tabdesecroissant[2] = ResQuickortProbabilisteEnDesCroissant;
	sum = 0;
	ResBubleSortEnCroissant = EstimationEnCroissantBubleSort(copier,taille);
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResBubleSortDesCroissant = EstimationDesCroissantBubleSort(copier,taille);
	CopierTab(tab,copier,taille);
	sum = ResBubleSortEnCroissant +  ResBubleSortDesCroissant/ 2; 
	tabsum[3] = sum;
	printf("\nresultat de temps pris en moyen \n\n-> %f \n", sum);
	sum = 0;	
	tabcroissant[3] = ResBubleSortEnCroissant;
	tabdesecroissant[3] = ResBubleSortDesCroissant;

	printf("\n--------------------------------------------------\n\n\n");

		
	
}
void TestLaFonction(){

	// testez la fonction pour generer les tableaux
	int taille;
	taille = returntaille();

	int* tab1 = generationdetab(taille);
	//affichagederes(tab1,taille);
	//RemplirLesTab(tab2,taille);
	//affichagederes(tab2,taille);
	
	//int* tab2 = (int*)malloc(taille * sizeof(int));
	//CopierTab(tab1,tab2,taille);
	//printf("\n\n--------------tab1-------------\n\n");
	//affichagederes(tab1,taille);
	//printf("\n\n--------------tab2-------------\n\n");

	//affichagederes(tab2,taille);
	//buble_sort_croissant(tab2, taille);
	//printf("\n\n--------------tab2-------------\n\n");
	//printf("\n\n--------------apres avoir trie-------------\n\n");
	//affichagederes(tab2,taille);
	//CopierTab(tab1,tab2,taille);
	//printf("\n\n--------------tab2-------------\n\n");
	//printf("\n\n--------------apres avoir copie------------\n\n");
	//affichagederes(tab2,taille);
	//printf("\n\n--------------apres avoir copie tab1-------------\n\n");
	affichagederes(tab1,taille);
	//printf("\n\n--------------apres avoir copie tab2-------------\n\n");
	//affichagederes(tab2, taille);
// testez les fonctions pour trier les elements de tableau 

	//printf("\n-----avant de trie---------\n");
	//printf("\n---------tab1---------------\n");
	//affichagederes(tab1,taille);
	//printf("\n---apres avoir trie avec merge---\n");
	//mergeSort(tab1, 0, taille - 1);	
	//affichagederes(tab1,taille);
	//printf("\n-----avant de trie--------\n");
	//printf("\n---------tab2--------------\n");
	//affichagederes(tab2,taille);
	//printf("\n---apres avoir trie avec triRapide---\n");
	//triRapide(tab2, 0, taille - 1);	
	//affichagederes(tab2,taille);
	//printf("\n------quickort probabiliste---\n");
	//printf("\navant de trie\n");
	//affichagederes(tab3, taille);
	//shuffle(tab3,taille);// testez la fonction de shuffle
	//quick_sort(tab3, 0,taille - 1);
	//printf("\napres avoir trie\n");
	//affichagederes(tab3,taille);
	//printf("\n--------buble sort----------\n");
	//printf("\navant de trie\n");
	//affichagederes(tab4,taille);
	//buble_sort_croissant(tab1,taille);
	//printf("\napres avoir trie\n");
	//affichagederes(tab2,taille);	
	//comparaison(tab1,taille);
	//CopierTab(tab2,tab1,taille);
	//QuickortProbabilisteSortEnordreCroissant(tab1,taille);
	//affichagederes(tab1,taille);
	//QuickortProbabilisteSortEnordreDesCroissant(tab1,taille);

	//printf("\nres de ordre croissant : %d\n\n", estOrdreCroissant(tab1,taille));
	//buble_sort_descroissant(tab1, taille);
	//affichagederes(tab1,taille);
	//printf("\nres de ordre Descroissant : %d\n\n", estOrdreDesCroissant(tab1,taille));

	//affichagederes(tab1,taille);

}


int main(void){

	srand(time(NULL));
	//int taille;
	//taille = returntaille();
	//int tab2[taille];
	TestLaFonction();

	return 0;
}
