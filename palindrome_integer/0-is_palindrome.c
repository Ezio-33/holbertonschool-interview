#include "palindrome.h"

/**
 * is_palindrome - Vérifie si un entier non signé est un palindrome
 * @n: Nombre à vérifier
 *
 * Return: 1 si n est un palindrome, 0 sinon
 */
int is_palindrome(unsigned long n)
{
    unsigned long original = n; /* Sauvegarde du nombre original */
    unsigned long reversed = 0; /* Nombre inversé */
    unsigned long remainder;

    /* Construire le nombre inversé */
    while (n != 0)
    {
        remainder = n % 10;         /* Extraire le dernier chiffre */
        reversed = reversed * 10 + remainder; /* Ajouter le chiffre au nombre inversé */
        n /= 10;                   /* Supprimer le dernier chiffre */
    }

    /* Comparer le nombre original avec son inverse */
    if (original == reversed)
        return (1);
    else
        return (0);
}
