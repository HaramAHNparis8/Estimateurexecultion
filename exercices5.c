#include "sort.h"
#include "utils.h"
#include "exercices5.h"


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
	qsort(tab1,taille,sizeof(int),CompareEnOrdreCroissant);
	affichagederes(tab1,taille);
	qsort(tab1,taille,sizeof(int),CompareEnOrdreDesCroissant);
	affichagederes(tab1,taille);

	
}


int main(void){

	srand(time(NULL));
	//int taille;
	//taille = returntaille();
	//int tab2[taille];
	TestLaFonction();

	return 0;
}
