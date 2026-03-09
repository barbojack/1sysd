#include <stdio.h>

/* Fonction qui convertit des degrés Celsius en degrés Fahrenheit */
double celsius2fahrenheit(double c)
{
    return (9.0 / 5.0) * c + 32;
}

/* Fonction qui convertit des degrés Fahrenheit en degrés Celsius */
double fahrenheit2celsius(double f)
{
    return (f - 32) * 5.0 / 9.0;
}

int main()
{
    int choice;        /* 1 = Celsius vers Fahrenheit, 2 = Fahrenheit vers Celsius */
    double temp;      /* température saisie par l'utilisateur */
    double result;  /* résultat de la conversion */

    /* Affichage du menu */
    printf("=== Convertisseur de température ===\n");
    printf("1 - Celsius vers Fahrenheit\n");
    printf("2 - Fahrenheit vers Celsius\n");
    printf("Votre choix (1 ou 2) : ");
    scanf("%d", &choice);

    /* Conversion selon le choix de l'utilisateur */
    if (choice == 1)
    {
        printf("Entrez la température en Celsius : ");
        scanf("%lf", &temp);

        result = celsius2fahrenheit(temp);

        printf("%.2f °C = %.2f °F\n", temp, result);
    }
    else if (choice == 2)
    {
        printf("Entrez la température en Fahrenheit : ");
        scanf("%lf", &temp);

        result = fahrenheit2celsius(temp);

        printf("%.2f °F = %.2f °C\n", temp, result);
    }
    else
    {
        printf("Choix invalide ! Veuillez entrer 1 ou 2.\n");
    }

    return 0;
}
