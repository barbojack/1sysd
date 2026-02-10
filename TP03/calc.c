#include <stdio.h>

int main() {
    double num1, num2, resultat;
    int operation;
    
    // Boucle infinie pour continuer les calculs
    while(1) {
        // Saisie des nombres
        printf("Premier nombre : ");
        scanf("%lf", &num1);
        
        printf("Second nombre  : ");
        scanf("%lf", &num2);
        
        // Affichage du menu
        printf("1. + (addition)\n");
        printf("2. - (soustraction)\n");
        printf("3. * (multiplication)\n");
        printf("4. / (division)\n");
        printf("Opération : ");
        scanf("%d", &operation);
        
        // Calcul selon l'opération choisie avec switch/case
        switch(operation) {
            case 1:
                resultat = num1 + num2;
                printf("Résultat : %.3f\n\n", resultat);
                break;
            case 2:
                resultat = num1 - num2;
                printf("Résultat : %.3f\n\n", resultat);
                break;
            case 3:
                resultat = num1 * num2;
                printf("Résultat : %.3f\n\n", resultat);
                break;
            case 4:
                if (num2 != 0) {
                    resultat = num1 / num2;
                    printf("Résultat : %.3f\n\n", resultat);
                } else {
                    printf("Erreur : Division par zéro!\n\n");
                }
                break;
            default:
                printf("Erreur : Opération invalide! Veuillez choisir 1, 2, 3 ou 4.\n\n");
        }
    }

	return 0;
}
