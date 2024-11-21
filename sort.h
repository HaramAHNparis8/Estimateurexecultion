#ifndef SORT_H
#define SORT_H

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
void merge(int* tab,int* tmp,int bas, int milieu, int haut, int ordre);
void mergeSortEncroissant(int* tab, int bas, int haut, int* tmp);
void mergeSortdescroissant(int* tab, int bas, int haut, int* tmp);
void LafusionExecutionEncroissant(int*tab, int taille);
void LafusionExecutionDesCroissant(int*tab, int taille);
void echanger(int *a, int *b);
void TriRapideEnCroissant(int *tab, int bas, int haut);
void TriRapideDesCroissant(int *tab, int bas, int haut);
void QuickortProbabilisteSortEnordreCroissant(int* tab, int taille);
void QuickortProbabilisteSortEnordreDesCroissant(int* tab, int taille);
void melangertout(int* tab, int taille);
void buble_sort_croissant(int* tab, int taille);
void buble_sort_descroissant(int* tab, int taille);

#endif
