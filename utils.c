#include "utils.h"
#include "sort.h"

const char* TabNomAlgo[]{
	
	"la fusion Croissant";
	"la fusion Descroissant";
	"Quicksort Croissant";
	"Quicksort Descroissant";
	"QuickortProbabiliste Croissant";
	"QuickortProbabiliste Descroissant";
	"BubleSort Croissant";
	"BubleSort Descroissant";


};

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

	int* tab = (int*)malloc(taille * sizeof(int));		

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
//

int* ReturnTableauRempli(int taille){

	int* tab = generationdetab(taille);
	RemplirLesTab(tab, taille);
	
	return tab;
}

//les fonctions pour initialiser les tableaux copier les tableau original

int* CopierLeTab(int* tab, int taille){
	
	int i;
	int* copier = generationdetab(taille);

	for(i = 0; i < taille; i++){

		copier[i] = tab[i];
		
	}

	return copier;

}



void CopierTab(int* oringinal,int* copier ,int taille){

	int i;	

	printf("\n--------------------------------------------------\n");
	printf("\n\n-> l'ordre de lst est initialise <--------\n\n");
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

double EstimationGeneral(int* tab, int taille, void (*f)(int*, int), const char** TabNomAlgo, int Indice) {
   
    printf("\n\n--------------%s-------------\n\n", TabNomAlgo[Indice]);
    affichagederes(tab, taille); 
    clock_t debut = clock(); 
    f(tab, taille);   
    clock_t fin = clock(); 
    double tempspris = (double)(fin - debut) / CLOCKS_PER_SEC;
    affichagederes(tab, taille); 
    printf("\nTemps pris pour l'algorithme  %s : %f seconds\n", TabNomAlgo[Indice], tempspris);

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

int EstdansTerminal(double* tab, int taille, double min){
		
		return Estdans(tab,taille - 1, min);
}

//la fonction pour tester que les tableaux sont bien trie ou pas

void estbientrie(int* tab1, int* tab2, int taille){
	
	int i = 0;

	printf("\n--------------------------------------------------\n");
	printf("\nLe resultat de la comparaison entre les elements du tableau trie et chaque element un par un\n");
	while(i < taille){

		if(tab1[i] == tab2[i]){

			printf("\n -> correct \n");
		}
		else{
			printf("\n -> non correct \n");
			printf("\nle tableau non trie\n");
			exit(1);
		}
		
		i++;	
	
	}
	printf("\n\nres : bien trie\n\n");
	
		
}

//la fonction pour verifier le tab est bien trie en ordre croissant

void estOrdreCroissant(int* tab, int taille){
	
	int i = 0;

	printf("\n--------------------------------------------------\n");
	printf("\nLe resultat de tableau est en ordre croissant\n");
	while(i < taille - 1){

		if(tab[i] < tab[i + 1]){
			printf("\nle resultat %deme %d eme[%d  %d]\n",i, i + 1, tab[i], tab[i + 1]);
			printf("\n -> correct\n");


		}
		else{
			printf("\nle resultat %deme %deme[%d %d]\n",i, i + 1, tab[i], tab[i + 1]);
			printf("\n -> non correct\n");
		}
		i++;


	}
}

void estOrdreDesCroissant(int* tab, int taille){

	printf("\n--------------------------------------------------\n");
	
	int i = 0;
	printf("\nle tableau est en ordre descroissant\n");

	while(i < taille - 1){

		if(tab[i] > tab[i + 1]){

			printf("\nle resultat %deme %deme[%d  %d]\n",i, i + 1, tab[i], tab[i + 1]);
			printf("\n -> correct\n");


		}
		else{
			printf("\nle resultat %deme %deme[%d %d]\n",i, i + 1, tab[i], tab[i + 1]);
			printf("\n -> non correct\n");

		}
		i++;


	}

}


// la fonction pour verifier que le tableau est bien trie ou non

int CompareEnOrdreCroissant(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int CompareEnOrdreDesCroissant(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// la fonction pour vertifier qu'il est bien trie ou pas

void comparaison(int* tab,int taille){
	
	int* copier = generationdetab(taille);	
	int* testtabenOrdreCroissant = generationdetab(taille);// le tableau pour tester bien trier ou pas
	int* testtabenOrdreDesCroissant = generationdetab(taille);// le tableau pour tester bien trier ou pas

	double tabsum[taillesum],sum, Resfusioncroissant, Resfusiondescroissant,ResTriRapideEnCroissant,ResTriRapiDesCroissant,ResQuickortProbabilisteEncroissant,ResQuickortProbabilisteEnDesCroissant,ResBubleSortEnCroissant,ResBubleSortDesCroissant,tabcroissant[taillecroissant],tabdesecroissant[tailledescroissant];
	CopierTab(tab,testtabenOrdreCroissant,taille);
	CopierTab(tab,testtabenOrdreDesCroissant,taille);
	qsort(testtabenOrdreCroissant,taille,sizeof(int),CompareEnOrdreCroissant);
	qsort(testtabenOrdreDesCroissant,taille,sizeof(int),CompareEnOrdreDesCroissant);
	melangertout(tab,taille);
	CopierTab(tab,copier,taille);// j'use cette proposition parce que cette fonction n'a pas besoin de la memoire
	Resfusioncroissant = EstimationGeneral(copier,taille,LafusionExecutionEncroissant(copier, taille),TabNomAlgo[0]);
	estbientrie(copier,testtabenOrdreCroissant,taille);
//la fonction pour intialiser la lst 
	estOrdreCroissant(copier,taille);	
	//la fonction pour initialiser les tableaux c'est la premiere propostion
	CopierTab(tab,copier,taille);
//la fonction pour initialiser les tableaux c'est la deuxieme propostion
	//copier = CopierLeTab(tab,taille);
	//affichagederes(copier,taille);
	Resfusiondescroissant = EstimationGeneral(copier,taille,LafusionExecutionDesCroissant(copier, taille),TabNomAlgo[1]);
	estbientrie(copier,testtabenOrdreDesCroissant,taille);
	estOrdreDesCroissant(copier,taille);
	tabcroissant[0] = Resfusioncroissant;
	tabdesecroissant[0] = Resfusiondescroissant;
	sum = (Resfusioncroissant + Resfusiondescroissant) / 2;
	tabsum[0] = sum;//le tableau pour stocker les informations de moyen
	printf("\nresultat de temps pris en moyen \n\n-> %f \n", sum);
	sum = 0;
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	printf("\n\n");
	ResTriRapideEnCroissant = EstimationGeneral(copier,taille,LaTriRapidExecutionEnCroissant(copier, taille),TabNomAlgo[2]);

	estbientrie(copier,testtabenOrdreCroissant,taille);
	estOrdreCroissant(copier,taille);
	printf("\n\n");
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResTriRapiDesCroissant = EstimationGeneral(copier,taille,LaTriRapidExecutionEnDesCroissant(copier, taille),TabNomAlgo[3]);
	estbientrie(copier,testtabenOrdreDesCroissant,taille);
	estOrdreDesCroissant(copier,taille);
	sum = ResTriRapideEnCroissant + ResTriRapiDesCroissant / 2;
	tabcroissant[1] = ResTriRapideEnCroissant;
	tabdesecroissant[1] = ResTriRapiDesCroissant;
	printf("\nresultat de temps pris en moyen \n\n-> %f \n", sum);
	tabsum[1] = sum;
	sum = 0;
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResQuickortProbabilisteEncroissant = EstimationGeneral(copier,taille,QuickortProbabilisteExecutionEnOrdreCroissant(copier,taille),TabNomAlgo[4]);
	estbientrie(copier,testtabenOrdreCroissant,taille);
	estOrdreCroissant(copier,taille);
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResQuickortProbabilisteEnDesCroissant = EstimationGeneral(copier,taille,TrierTriRapideProbabilisteExcutionEnOredreDescroissant(copier,taille),TabNomAlgo[5]);
; 
	estbientrie(copier,testtabenOrdreDesCroissant,taille);
	estOrdreDesCroissant(copier,taille);
	sum = ResQuickortProbabilisteEncroissant + ResQuickortProbabilisteEnDesCroissant / 2; 
	printf("\nresultat de temps pris en moyen \n\n-> %f \n", sum);
	tabsum[2] = sum;
	tabcroissant[2] = ResQuickortProbabilisteEncroissant;
	tabdesecroissant[2] = ResQuickortProbabilisteEnDesCroissant;
	sum = 0;
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResBubleSortEnCroissant = EstimationGeneral(copier,taille,BubleSortExecutionEnOrdreCroissant(copier,taille),TabNomAlgo[6]);

	estbientrie(copier,testtabenOrdreCroissant, taille);
	estOrdreCroissant(copier,taille);
	CopierTab(tab,copier,taille);
	affichagederes(copier,taille);
	ResBubleSortDesCroissant = EstimationGeneral(copier,taille,BubleSortExecutionEnOrdreDesCroissant(copier,taille),TabNomAlgo[7]);
	estbientrie(copier,testtabenOrdreDesCroissant, taille);
	estOrdreDesCroissant(copier,taille);
	CopierTab(tab,copier,taille);
	sum = ResBubleSortEnCroissant +  ResBubleSortDesCroissant/ 2; 
	tabsum[3] = sum;
	printf("\nresultat de temps pris en moyen \n\n-> %f \n", sum);
	sum = 0;	
	tabcroissant[3] = ResBubleSortEnCroissant;
	tabdesecroissant[3] = ResBubleSortDesCroissant;
	printf("\n--------------------------------------------------\n\n\n");

		
	
}

