#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Print the current sub-array being searched
 * @array: Pointer to the array
 * @left: Starting index
 * @right: Ending index
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursive function to find the first occurrence
 * @array: Sorted array
 * @left: Left index of current search space
 * @right: Right index of current search space
 * @value: Target value
 * Return: Index of the first occurrence or -1
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return ((int)mid);
		else
			return (recursive_search(array, left, mid - 1, value));
	}
	else if (array[mid] > value)
	{
		return (recursive_search(array, left, mid - 1, value));
	}
	else
	{
		return (recursive_search(array, mid + 1, right, value));
	}
}

/**
 * advanced_binary - Entry point for advanced binary search
 * @array: Sorted array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of first occurrence or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
