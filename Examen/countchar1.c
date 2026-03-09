#include <stdio.h>

/* Compter combien de fois « c » apparaît dans la chaîne « str » */
int count_char(char *str, char c)
{
    int count;  /* nombre de fois où le caractère est trouvé */
    int i;      /* index pour parcourir la chaîne */

    count = 0;
    i = 0;

    /* Parcourir chaque caractère de la chaîne jusqu'à la fin “\0” */
    while (str[i] != '\0')
    {
        if (str[i] == c)
            count++;
        i++;
    }

    return count;
}

int main(int argc, char *argv[])
{
    char *str;    /* la chaîne à examiner (premier argument) */
    char c;       /* le caractère à compter (deuxième argument) */
    int  result;  /* le nombre d'occurrences du caractère */

    /* Vérifier que l'utilisateur a fourni exactement 2 arguments */
    if (argc != 3)
    {
        printf("Usage: %s <string> <character>\n", argv[0]);
        return 1;
    }

    str = argv[1];  /* premier argument = la chaîne */
    c = argv[2][0];  /* deuxième argument = le caractère (première lettre uniquement) */

    result = count_char(str, c);

    printf("%d\n", result);

    return 0;
}

