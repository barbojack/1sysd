#include <stdio.h>

int main() {
	int tableau[5];
	int somme = 0;

	printf("=== Programme avec tableau ===\n\n");

	//Demander et stocker 5 nombres dans le tableau
	for(int i = 0; i < 5; i++) {
		printf("Entrez le nombre &d : ", i + 1);
		scanf("%d", &tableau[i]);
		somme += tableau[i];
	}

	//Afficher le contenu du tableau
	printf("\nContenu du tableau : ");
	for(int i = 0; i < 5; i++) {
		printf("%d ", tableau[i]);
	}
	printf("\n");

	//Afficher la somme
	printf("La somme des 5 nombres est : %d\n", somme);

	return 0;
}
