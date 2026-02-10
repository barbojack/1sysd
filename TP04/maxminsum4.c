#include <stdio.h>

int main() {
    int tableau[100];
    int n, somme = 0;
    int min, max;
    
    printf("=== Programme complet avec min/max ===\n\n");
    
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
    
    // Initialiser min et max avec le premier élément
    min = tableau[0];
    max = tableau[0];
    
    // Trouver le minimum et le maximum
    for(int i = 1; i < n; i++) {
        if(tableau[i] < min) {
            min = tableau[i];
        }
        if(tableau[i] > max) {
            max = tableau[i];
        }
    }
    
    // Afficher le contenu du tableau
    printf("\nContenu du tableau : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
    
    // Afficher les résultats
    printf("\nRésultats :\n");
    printf("- Somme      : %d\n", somme);
    printf("- Minimum    : %d\n", min);
    printf("- Maximum    : %d\n", max);
    
    return 0;
}
