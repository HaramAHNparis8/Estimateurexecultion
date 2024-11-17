#include <stdio.h>
#include <stdlib.h>

/*let rec quicksort = function
    | [] -> []
    | x::xs -> let smaller, larger = List.partition (fun y -> y < x) xs
               in quicksort smaller @ (x::quicksort larger) */


// je reproduis l'algorithme de ocaml


int* triRapide(int *tableau, int taille) {
    if (taille <= 1) { 
        int *resultat = (int*)malloc(taille * sizeof(int));
        for (int i = 0; i < taille; i++) resultat[i] = tableau[i];
        return resultat;
    }

    int pivot = tableau[0];  // Choisir le premier élément comme pivot
    int nombreGauche = 0, nombreDroite = 0;

    // Calculer la taille des tableaux gauche et droit en fonction du pivot
    for (int i = 1; i < taille; i++) {
        if (tableau[i] < pivot)
            nombreGauche++;
        else
            nombreDroite++;
    }

    // Créer les tableaux gauche et droit
    int *gauche = (int*)malloc(nombreGauche * sizeof(int));
    int *droite = (int*)malloc(nombreDroite * sizeof(int));
    int indiceGauche = 0, indiceDroite = 0;

    // Placer les éléments dans gauche ou droite en fonction du pivot
    for (int i = 1; i < taille; i++) {
        if (tableau[i] < pivot)
            gauche[indiceGauche++] = tableau[i];
        else
            droite[indiceDroite++] = tableau[i];
    }

    // Trier récursivement les tableaux gauche et droit
    int *triGauche = triRapide(gauche, nombreGauche);
    int *triDroite = triRapide(droite, nombreDroite);

    free(gauche);
    free(droite);

    // Créer un nouveau tableau pour combiner les résultats triés
    int *resultat = (int*)malloc(taille * sizeof(int));
    for (int i = 0; i < nombreGauche; i++) resultat[i] = triGauche[i];
    resultat[nombreGauche] = pivot;
    for (int i = 0; i < nombreDroite; i++) resultat[nombreGauche + 1 + i] = triDroite[i];

    free(triGauche);
    free(triDroite);

    return resultat;
}

// Fonction pour afficher le tableau
void afficherTableau(int *tableau, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

int main() {
    int tableau[] = {34, 7, 23, 32, 5, 62};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau avant tri: ");
    afficherTableau(tableau, taille);

    int *tableauTrie = triRapide(tableau, taille);

    printf("Tableau après tri: ");
    afficherTableau(tableauTrie, taille);

    free(tableauTrie);  // Libérer la mémoire allouée dynamiquement

    return 0;
}
