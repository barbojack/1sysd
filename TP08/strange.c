#include <stdio.h>
#include <stdlib.h>

/* 
 * Fonction: slen
 * Renvoie la longueur d'une chaîne de caractères
 * Paramètre: s - pointeur vers la chaîne
 * Retour: nombre de caractères (sans compter '\0')
 */
int slen(char *s) {
    int longueur = 0;
    
    // On parcourt la chaîne jusqu'au caractère de fin '\0'
    while (*s != '\0') {
        longueur++;
        s++;  // On avance le pointeur d'un caractère
    }
    
    return longueur;
}

/* 
 * Fonction: is_upper
 * Vérifie si tous les caractères alphabétiques sont en majuscules
 * Paramètre: s - pointeur vers la chaîne
 * Retour: -1 si vrai, 0 si faux
 */
int is_upper(char *s) {
    while (*s != '\0') {
        // Si on trouve une lettre minuscule (a-z), on retourne 0
        if (*s >= 'a' && *s <= 'z') {
            return 0;
        }
        s++;
    }
    return -1;  // Aucune minuscule trouvée
}

/* 
 * Fonction: is_lower
 * Vérifie si tous les caractères alphabétiques sont en minuscules
 * Paramètre: s - pointeur vers la chaîne
 * Retour: -1 si vrai, 0 si faux
 */
int is_lower(char *s) {
    while (*s != '\0') {
        // Si on trouve une lettre majuscule (A-Z), on retourne 0
        if (*s >= 'A' && *s <= 'Z') {
            return 0;
        }
        s++;
    }
    return -1;  // Aucune majuscule trouvée
}

/* 
 * Fonction: supper
 * Convertit tous les caractères minuscules en majuscules
 * Paramètre: s - pointeur vers la chaîne à modifier
 * Note: modifie directement la chaîne (pas de retour)
 */
void supper(char *s) {
    while (*s != '\0') {
        // Si c'est une minuscule, on la convertit en majuscule
        if (*s >= 'a' && *s <= 'z') {
            // Astuce: la différence entre 'a' et 'A' est constante (32 en ASCII)
            *s = *s - 32;
        }
        s++;
    }
}

/* 
 * Fonction: slower
 * Convertit tous les caractères majuscules en minuscules
 * Paramètre: s - pointeur vers la chaîne à modifier
 * Note: modifie directement la chaîne (pas de retour)
 */
void slower(char *s) {
    while (*s != '\0') {
        // Si c'est une majuscule, on la convertit en minuscule
        if (*s >= 'A' && *s <= 'Z') {
            // On ajoute 32 pour passer de majuscule à minuscule
            *s = *s + 32;
        }
        s++;
    }
}

/* 
 * Fonction: scopy
 * Crée une copie d'une chaîne en allouant la mémoire nécessaire
 * Paramètre: s - pointeur vers la chaîne à copier
 * Retour: pointeur vers la nouvelle chaîne copiée
 * Note: N'OUBLIEZ PAS de libérer la mémoire avec free() !
 */
char *scopy(char *s) {
    // Étape 1: calculer la longueur de la chaîne
    int longueur = slen(s);
    
    // Étape 2: allouer la mémoire (+1 pour le '\0')
    char *copie = (char *)malloc((longueur + 1) * sizeof(char));
    
    // Étape 3: vérifier que l'allocation a réussi
    if (copie == NULL) {
        return NULL;
    }
    
    // Étape 4: copier caractère par caractère
    char *debut = copie;  // On garde le début pour le retourner
    while (*s != '\0') {
        *copie = *s;
        copie++;
        s++;
    }
    *copie = '\0';  // Ne pas oublier le caractère de fin !
    
    return debut;
}

/* 
 * Fonction: sequal
 * Compare deux chaînes pour vérifier si elles sont identiques
 * Paramètres: s1, s2 - pointeurs vers les chaînes à comparer
 * Retour: -1 si égales, 0 si différentes
 */
int sequal(char *s1, char *s2) {
    // On compare caractère par caractère
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return 0;  // Caractères différents trouvés
        }
        s1++;
        s2++;
    }
    
    // Si les deux pointeurs sont sur '\0', les chaînes sont égales
    if (*s1 == '\0' && *s2 == '\0') {
        return -1;
    }
    
    return 0;  // Une chaîne est plus longue que l'autre
}

/* ========== PROGRAMME PRINCIPAL ========== */
int main() {
    printf("╔════════════════════════════════════════════╗\n");
    printf("║   Tests des fonctions de manipulation     ║\n");
    printf("║        de chaînes avec pointeurs          ║\n");
    printf("╚════════════════════════════════════════════╝\n\n");
    
    // ========== Test 1: slen ==========
    printf("┌─ Test 1: slen (longueur de chaîne)\n");
    char chaine1[] = "Bonjour";
    char chaine2[] = "Hello World!";
    printf("│ slen(\"%s\") = %d\n", chaine1, slen(chaine1));
    printf("│ slen(\"%s\") = %d\n", chaine2, slen(chaine2));
    printf("└─────────────────────────────────\n\n");
    
    // ========== Test 2: is_upper ==========
    printf("┌─ Test 2: is_upper (tout en majuscules?)\n");
    char maj[] = "BONJOUR";
    char mixte[] = "Bonjour";
    printf("│ is_upper(\"%s\") = %d (attendu: -1)\n", maj, is_upper(maj));
    printf("│ is_upper(\"%s\") = %d (attendu: 0)\n", mixte, is_upper(mixte));
    printf("└─────────────────────────────────\n\n");
    
    // ========== Test 3: is_lower ==========
    printf("┌─ Test 3: is_lower (tout en minuscules?)\n");
    char min[] = "bonjour";
    char mixte2[] = "Bonjour";
    printf("│ is_lower(\"%s\") = %d (attendu: -1)\n", min, is_lower(min));
    printf("│ is_lower(\"%s\") = %d (attendu: 0)\n", mixte2, is_lower(mixte2));
    printf("└─────────────────────────────────\n\n");
    
    // ========== Test 4: supper ==========
    printf("┌─ Test 4: supper (convertir en majuscules)\n");
    char test_maj[] = "Bonjour le Monde!";
    printf("│ Avant:  \"%s\"\n", test_maj);
    supper(test_maj);
    printf("│ Après:  \"%s\"\n", test_maj);
    printf("└─────────────────────────────────\n\n");
    
    // ========== Test 5: slower ==========
    printf("┌─ Test 5: slower (convertir en minuscules)\n");
    char test_min[] = "HELLO WORLD!";
    printf("│ Avant:  \"%s\"\n", test_min);
    slower(test_min);
    printf("│ Après:  \"%s\"\n", test_min);
    printf("└─────────────────────────────────\n\n");
    
    // ========== Test 6: scopy ==========
    printf("┌─ Test 6: scopy (copier une chaîne)\n");
    char original[] = "Copie-moi!";
    char *copie = scopy(original);
    if (copie != NULL) {
        printf("│ Original: \"%s\" (adresse: %p)\n", original, (void*)original);
        printf("│ Copie:    \"%s\" (adresse: %p)\n", copie, (void*)copie);
        printf("│ → Les adresses sont différentes: la copie est réussie!\n");
        free(copie);  // IMPORTANT: libérer la mémoire !
    }
    printf("└─────────────────────────────────\n\n");
    
    // ========== Test 7: sequal ==========
    printf("┌─ Test 7: sequal (comparer deux chaînes)\n");
    char str1[] = "test";
    char str2[] = "test";
    char str3[] = "autre";
    printf("│ sequal(\"%s\", \"%s\") = %d (attendu: -1)\n", str1, str2, sequal(str1, str2));
    printf("│ sequal(\"%s\", \"%s\") = %d (attendu: 0)\n", str1, str3, sequal(str1, str3));
    printf("└─────────────────────────────────\n\n");
    
    printf("Tous les tests sont terminés!\n");
    
    return 0;
}

