#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	int *valeurs;
	double *logarithmes;
	int i;

	// Demande du nombres de valeurs
	printf("Combien de valeurs voulez-vous gérer ? ");
	scanf("%d", &n);

	// Vérification que n est positif
	if (n <= 0) {
		printf("Le nombre de valeurs doit être positif.\n");
		return 1;
	}

	// Allocation dynamique des tableaux
	valeurs = (int *)malloc(n * sizeof(int));
	logarithmes = (double *)malloc(n * sizeof(double));

	if (valeurs == NULL || logarithmes == NULL) {
		printf("Erreur d'allocation mémoire.\n");
		return 1;
	}

	// Saisie des valeurs avec notation classique
	printf("\nSaisie des %d : ", i + 1);
	for (i = 0; i < n; i++) {
		printf("Valeurs %d : ", i + 1);
		scanf("%d", &valeurs[i]);
	}

	// Caclcul des logarithmes avec arithmétique de pointeurs
	printf("\nCalcul des logarithmes népériens...\n");
	for (i = 0; i < n; i++) {
		if (*(valeurs + i) > 0) {
			*(logarithmes + i) = log(*(valeurs + i));
		} else {
			printf("Attention : ln(%d) n'est pas défini (valeur <= 0)\n", *(valeurs + i));
			*(logarithmes + i) = 0.0; //Valeur par défaut
		}
	}

	// Affichage des résultats avec arithmétique de pointeurs
	printf("\n=== RESULTATS ===\n");
	printf("%-10s | %-15s\n", "Valeur", "ln(valeur)");
	printf("--------------------------------\n");
	for (i = 0; i < n; i++) {
		if (*(valeurs + i) > 0) {
			printf("%-10d | %-15.6f\n", *(valeurs + i), *(logarithmes + i));
		} else {
			printf("%-10d | non défini\n", *(valeurs + i));
		}
	}

	// Libération de la mémoire
	free(valeurs);
	free(logarithmes);

	return 0;
}

