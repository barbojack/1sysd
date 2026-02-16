#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int pop;
    float area;
} City;

City saisir_city() {
    
    City city;
    
    // Votre code ici
    
    return city;
}

void afficher_city(City city) {
    
    // Votre code ici
}


float densite_population(City city) {
    
    // Votre code ici
    
    return 0.0;
}



int main() {
    printf("============================================================\n");
    printf("EXERCICE - GESTION DE VILLES\n");
    printf("============================================================\n");
    printf("\n");
    
    printf("Test 1: Création d'une ville (Paris)\n");
    printf("------------------------------------------------------------\n");
    
    City paris;
    strcpy(paris.name, "Paris");
    paris.pop = 2161000;
    paris.area = 105.4;
    
    afficher_city(paris);
    float densite_paris = densite_population(paris);
    printf("Densité de population: %.2f hab/km²\n", densite_paris);
    printf("\n");
    
    printf("Test 2: Création d'une ville (Lyon)\n");
    printf("------------------------------------------------------------\n");
    
    City lyon;
    strcpy(lyon.name, "Lyon");
    lyon.pop = 516092;
    lyon.area = 47.87;
    
    afficher_city(lyon);
    float densite_lyon = densite_population(lyon);
    printf("Densité de population: %.2f hab/km²\n", densite_lyon);
    printf("\n");
    
    printf("Test 3: Saisie interactive d'une ville\n");
    printf("------------------------------------------------------------\n");
    
    City ma_ville = saisir_city();
    
    printf("\nVille saisie:\n");
    afficher_city(ma_ville);
    float densite_ma_ville = densite_population(ma_ville);
    printf("Densité de population: %.2f hab/km²\n", densite_ma_ville);
    printf("\n");
    
    printf("============================================================\n");
    printf("FIN DES TESTS\n");
    printf("============================================================\n");
    
    return 0;
}


void comparer_densite(City city1, City city2) {
}


City ville_la_plus_peuplee(City cities[], int n) {
    
    City max = cities[0];
    
    // Votre code ici
    
    return max;
}
