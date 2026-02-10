#include <stdio.h>

int main() {
	int nombre, somme = 0;

	printf("=== Programme de calcul de somme ===\n\n");

	//Demander 5 nombres
	for(int i = 1; i <= 5; i++) {
		printf("Entrez le nombre %d : ", i);
		scanf("%d", &nombre);
		somme += nombre;
	}

	// Afficher la somme
	printf("\nLa somme des 5 nombres est : %d\n", somme);

	return 0;
}
