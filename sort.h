#ifndef SORT_H
#define SORT_H

#include <stdio.h> 
#include <stdlib.h>

void merge(int* tab, int bas, int milieu, int haut);
void mergeSortEncroissant(int* a, int low, int hight);
void MergeEnDecroissant(int* tab, int bas, int milieu, int haut);
void mergeSortdescroissant(int* a, int low, int hight);
void echanger(int *a, int *b);
void TriRapideEnCroissant(int *tab, int bas, int haut);
void TriRapideDesCroissant(int *tab, int bas, int haut);
void QuickortProbabilisteSortEnordreCroissant(int* tab, int taille);
void QuickortProbabilisteSortEnordreDesCroissant(int* tab, int taille);
void melangertout(int* tab, int taille);
void buble_sort_croissant(int* tab, int taille);
void buble_sort_descroissant(int* tab, int taille);

#endif
