#include <stdio.h>

/* Compter combien de fois « value » apparaît dans le tableau « tab » de taille « size » */
int compte_int(int *tab, int size, int value)
{
	int count; /* nombre de fois où la valeur est trouvée */
	int i; /* index pour parcourir le tableau */

	count = 0;

	/* Parcourir chaque élément du tableau */
	for (i = 0; i < size; i++)
	{
		if (tab[i] == value)
			count++;
	}
	return count;
}

int main()
{
	int t1[5] = {2, 42, 1, 42, 9};
	int t2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("%d dans t1 : %d fois.\n", 42, compte_int(t1, 5, 42));
	printf("%d dans t1 : %d fois.\n", 2, compte_int(t1, 5, 2));
	printf("%d dans t2 : %d fois.\n", 10, compte_int(t2, 10, 10));
	printf("%d dans t2 : %d fois.\n", 42, compte_int(t2, 10, 42));

	return 0;
}
