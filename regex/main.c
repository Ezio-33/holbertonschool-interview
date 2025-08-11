/*
 * File: main.c (tests locaux uniquement)
 * Desc: Programme de test pour la fonction regex_match.
 */

#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

#define TEST_MATCH(s, p) \
	do { \
		int res = regex_match((s), (p)); \
		printf("%s -> %s = %d\n", (s), (p), res); \
	} while (0)

/**
 * main - Point d'entrée (tests locaux uniquement)
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	TEST_MATCH("H", "H");
	TEST_MATCH("HH", "H");
	TEST_MATCH("HH", "H*");
	TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");

	TEST_MATCH("Holberton", ".*");
	TEST_MATCH("Alex", ".*");
	TEST_MATCH("Guillaume", ".*");
	TEST_MATCH("Julien", ".*");

	TEST_MATCH("Holberton", "Z*H.*");
	TEST_MATCH("Holberton", "Z*H.*olberton");
	TEST_MATCH("Holberton", "Z*H.*o.");
	TEST_MATCH("Holberton", "Z*H.*o");

	TEST_MATCH("Holberton", "holberton");
	TEST_MATCH("Holberton", ".olberton");

	TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

	return (EXIT_SUCCESS);
}
