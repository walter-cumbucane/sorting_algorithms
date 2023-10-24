#ifndef SORT_H
#define SORT_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* algorithms */
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Operational functions */
size_t smallest(int *array, size_t size, size_t i);
int partition(int *array, int low, int high, size_t size);
void sort_quickly(int *array, int low, int high, size_t size);
void swp(int *arr, int *x, int *y, size_t size);

#endif
