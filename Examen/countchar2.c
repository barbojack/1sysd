#include <stdio.h>

/* Convertir un caractère en minuscule */
char to_lower(char c)
{
    
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

/* Compter le nombre d'occurrences de « c » dans « str » */
/* Si « ignore_case » est égal à 1, les majuscules et les minuscules sont traitées de la même manière */
int count_char(char *str, char c, int ignore_case)
{
    int  count;  /* nombre de fois où le caractère est trouvé */
    int  i;      /* index pour parcourir la chaîne */
    char current;  /* caractère actuellement examiné */
    char target;   /* le caractère que nous recherchons */

    count = 0;
    i = 0;
    target = c;

    /* Si ignore_case est actif, convertir la cible en minuscules */
    if (ignore_case)
        target = to_lower(c);

    /* Parcourir chaque caractère de la chaîne jusqu'à la fin “\0” */
    while (str[i] != '\0')
    {
        current = str[i];

        /* Si ignore_case est actif, convertir également le caractère actuel */
        if (ignore_case)
            current = to_lower(str[i]);

        if (current == target)
            count++;
        i++;
    }

    return count;
}

int main(int argc, char *argv[])
{
    char *str;       /* la chaîne à examiner (premier argument)  */
    char c;          /* le caractère à compter (deuxième argument) */
    int ignore_case; /* 1 si le drapeau -i est présent, 0 sinon */
    int result;      /* le nombre d'occurrences du caractère */

    /* Vérifier que l'utilisateur a fourni au moins 2 arguments (et au maximum 3) */
    if (argc < 3 || argc > 4)
    {
        printf("Usage: %s <string> <character> [-i]\n", argv[0]);
        return 1;
    }

    str = argv[1];     /* premier argument  = la chaîne */
    c = argv[2][0];    /* deuxième argument = le caractère */
    ignore_case = 0;   /* par défaut, sensible à la casse */

    /* Vérifier si le drapeau optionnel -i est présent en tant que troisième argument */
    if (argc == 4 && argv[3][0] == '-' && argv[3][1] == 'i')
        ignore_case = 1;

    result = count_char(str, c, ignore_case);

    printf("%d\n", result);

    return 0;
}
