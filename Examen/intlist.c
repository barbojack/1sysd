#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node {
    int value;
    Node *next;
};

void print_list(Node *head) {
    Node *current;

    current = head;
    while( current ) {
        printf("%d ", current->value);
        current = current->next; 
    }
    printf("\n");
}

Node *new_node(int value) {
    Node *node;
    node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

Node *append_value(Node *head, int value) {
    Node *current;

    current = head;

    // deux cas  possible : la liste est vide (head est NULL)
    // ou pas...
    if ( head == NULL ) {
        head = new_node(value);
    } else { // la liste n'est pas vide
        current = head;
        while ( current->next ) {
            current = current->next;
        }
        // arrivé ici on est sur un noeud qui n'a pas de successeur
        current->next = new_node(value);
    }
    return head;
}
        
int length(Node *head) {
    Node *current;
    int len = 0;

    current = head;
    while( current ) {
        len++;
        current = current->next;
    }
    return len; 
}

/* Calcule et renvoie de la somme de toutes les valeurs de la liste */
int total(Node *head)
{
	Node *current;
	int sum;
	sum = 0;
	current = head;

	/* Parcourt chaque noeud et ajoute sa valeur à sum */
	while(current)
	{
		sum += current->value;
		current = current->next;
	}

	return sum;
}

/* Calcule et renvoie la moyenne de toutes les valeurs de la liste, la liste ne oit pas être vide */
double average(Node *head)
{
	return(double)total(head) / length(head);
}

/* Renvoie 1 si les deux listes ont exactement les mêmes valeurs, 0 sinon */
int cmp_list(Node *head1, Node *head2)
{
	Node *current1;
	Node *current2;
	current1 = head1;
	current2 = head2;

	/*Parcourt les deux listes en même temps */
	while (current1 && current2)
	{
		if (current1->value != current2->value)
			return 0;

		current1 = current1->next;
		current2 = current2->next;
	}

	/* Si une liste est plus longue que l'autre, elles ne sont pas égales */
	if (current1 != NULL || current2 != NULL)
		return 0;

	return 1;
}

int main()
{
	Node *head = NULL;
	Node *head2 = NULL;
	Node *head3 = NULL;

	// head est mis à jour seulement lors du premier appel
	head = append_value(head, 42);
	head = append_value(head, 4);
	head = append_value(head, 5);
	head = append_value(head, 42);
	head = append_value(head, 1);

	print_list(head);
	printf("Longueur de la liste %d.\n", length(head));

	/* --- Test total() --- */
	printf("%d\n", total(head));

	/* --- Test average() --- */
	printf("%.2f\n", average(head));

	/* --- Test cmp_list() --- */
	head2 = append_value(head2, 42);
	head2 = append_value(head2, 4);
	head2 = append_value(head2, 5);
	head2 = append_value(head2, 42);
	head2 = append_value(head2, 1);

	head3 = append_value(head3, 42);
	head3 = append_value(head3, 4);
	head3 = append_value(head3, 99);

	printf("Listes identiques : %d\n", cmp_list(head, head2));
	printf("Listes différentes : %d\n", cmp_list(head, head3));

	exit(0);
}
