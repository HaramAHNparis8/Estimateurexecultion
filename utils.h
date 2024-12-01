#ifndef UTILS_H
#define UTILS_H
#define taillesum 4 // la taille de le tableau our stocker le moyen 
#define taillecroissant 4 // la taille de tableau pour stocker le temps pris dans l'ordre de croissant   
#define tailledescroissant 4 // la taille de tableau pour stocker le temps pris dans l'ordre de descroissant 
#include <stdio.h>
#include <stdlib.h>

int returntaille();
int* generationdetab(int taille);
int* ReturnTableauRempli(int taille);
void affichagederes(int* tab, int taille);
void RemplirLesTab(int* tab, int taille);
void remplirRecTab(int taille, int* tab);
int* CopierLeTab(int* tab, int taille);
void CopierTab(int* oringinal,int* copier ,int taille);
void comparaison(int* tab,int taille);
double min(double* tab,int taille);
int Estdans(double* tab, int taille, double min);
int EstdansTerminal(double* tab, int taille, double min);
void estOrdreCroissant(int* tab, int taille);
void estOrdreDesCroissant(int* tab, int taille);
void comparaison(int* tab,int taille);
int CompareEnOrdreCroissant(const void *a, const void *b);
int CompareEnOrdreDesCroissant(const void *a, const void *b);
void estbientrie(int* tab1, int* tab2, int taille);

#endif 
