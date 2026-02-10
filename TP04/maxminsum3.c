#include <stdio.h>

int main() {
    int tableau[100];
    int n, somme = 0;
    
    printf("=== Programme avec taille variable ===\n\n");
    
    // Demander combien de nombres
    do {
        printf("Combien de nombres voulez-vous saisir (max 100) ? ");
        scanf("%d", &n);
        
        if(n < 1 || n > 100) {
            printf("Erreur : veuillez entrer un nombre entre 1 et 100.\n");
        }
    } while(n < 1 || n > 100);
    
    // Demander et stocker les nombres dans le tableau
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("Entrez le nombre %d : ", i + 1);
        scanf("%d", &tableau[i]);
        somme += tableau[i];
    }
    
    // Afficher le contenu du tableau
    printf("\nContenu du tableau : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
    
    // Afficher la somme
    printf("La somme des %d nombres est : %d\n", n, somme);
    
    return 0;
}

