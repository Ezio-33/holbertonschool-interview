#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * word_count - compte les occurrences de chaque mot dans une sous-chaîne
 * @substring: la sous-chaîne à analyser
 * @words: le tableau de mots
 * @nb_words: nombre de mots
 * @word_len: longueur de chaque mot
 *
 * Return: 1 si la sous-chaîne contient exactement chaque mot une fois,
 *         0 sinon
 */
static int word_count(char const *substring, char const **words,
		      int nb_words, int word_len)
{
	int i, j, count;
	int *used; /* tableau pour marquer les mots utilisés */

	/* Allouer et initialiser le tableau des mots utilisés */
	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	/* Parcourir la sous-chaîne par blocs de word_len */
	for (i = 0; i < nb_words * word_len; i += word_len)
	{
		count = 0;
		/* Chercher ce bloc dans le tableau words */
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(substring + i, words[j], word_len) == 0)
			{
				used[j] = 1;
				count = 1;
				break;
			}
		}
		/* Si aucun mot correspondant trouvé, ce n'est pas valide */
		if (!count)
		{
			free(used);
			return (0);
		}
	}

	free(used);
	return (1);
}

/**
 * resize_indices_array - redimensionne le tableau d'indices
 * @indices: pointeur vers le tableau d'indices
 * @capacity: pointeur vers la capacité actuelle
 * @n: nombre d'éléments actuels
 *
 * Return: pointeur vers le nouveau tableau ou NULL en cas d'erreur
 */
static int *resize_indices_array(int **indices, int *capacity, int n)
{
	int *new_indices;

	if (n >= *capacity)
	{
		*capacity = *capacity == 0 ? 1 : *capacity * 2;
		new_indices = realloc(*indices, *capacity * sizeof(int));
		if (!new_indices)
			return (NULL);
		*indices = new_indices;
	}
	return (*indices);
}

/**
 * validate_input - valide les paramètres d'entrée
 * @s: la chaîne à scanner
 * @words: le tableau de mots
 * @nb_words: nombre de mots
 * @s_len: pointeur pour stocker la longueur de s
 * @word_len: pointeur pour stocker la longueur des mots
 * @total_len: pointeur pour stocker la longueur totale
 *
 * Return: 1 si valide, 0 sinon
 */
static int validate_input(char const *s, char const **words, int nb_words,
			  int *s_len, int *word_len, int *total_len)
{
	if (!s || !words || nb_words <= 0)
		return (0);

	*s_len = strlen(s);
	*word_len = strlen(words[0]);
	*total_len = *word_len * nb_words;

	if (*s_len < *total_len)
		return (0);

	return (1);
}

/**
 * find_substring - trouve tous les indices de sous-chaînes possibles
 *                  contenant une liste de mots
 * @s: la chaîne à scanner
 * @words: le tableau de mots
 * @nb_words: le nombre d'éléments dans le tableau words
 * @n: adresse où stocker le nombre d'éléments dans le tableau retourné
 *
 * Return: un tableau alloué avec les indices, ou NULL si aucune solution
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices = NULL;
	int s_len, word_len, total_len;
	int i, capacity = 0;

	*n = 0;

	if (!validate_input(s, words, nb_words, &s_len, &word_len, &total_len))
		return (NULL);

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (word_count(s + i, words, nb_words, word_len))
		{
			if (!resize_indices_array(&indices, &capacity, *n))
			{
				*n = 0;
				return (NULL);
			}
			indices[*n] = i;
			(*n)++;
		}
	}

	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}

	return (indices);
}
