#include "Struct_2D_Array.h"
#include <stdlib.h>
/*
	This file contains prototype of what I wanted to put into Lab13.c

	Well... its too confusing and probably there is a memory leak (didnt find one but...)

	Feel free to use and modify it as you want
*/



void Array_C(Array* arr, var length)
{
	if (arr == NULL)										// Error condition return
		return;												// pointer argument cannot be equal to NULL

	arr->buffer = (ptr)malloc(length * sizeof(var));		// Creates array[length]
	if (!arr->buffer)
		ERROR_EXIT;

	arr->length = length;									// give length member value
}

void Array_D(Array* arr)
{
	if (arr == NULL)										// Error condition return
		return;												// pointer argument cannot be equal to NULL

	free(arr->buffer);										// Cleans Array struct
	arr->buffer = NULL;										//	*	dealocates memory
	arr->length = 0;										//	*	cleans length member value
}

void Array_2D_C(Array_2D* arr_2d, var row, var column)
{
	if (arr_2d == NULL)										// Error condition return
		return;												// pointer argument cannot be equal to NULL

	arr_2d->buffer = (Array*)malloc(row * sizeof(Array));	// Allocate memory for rows (arrays 1D)
															// and check if it was success
	if (arr_2d->buffer == NULL)								//
		ERROR_EXIT;											//

	for (int arr = 0; arr < row; ++arr)						// Allocate memory for columns (array 1D elements)
		Array_C(&arr_2d->buffer[arr], column);				// 

	arr_2d->ColumnLength = column;
	arr_2d->rowLength = row;
}

void Array_2D_D(Array_2D* arr_2d)
{
	if (arr_2d == NULL)									// Error condition return
		ERROR_EXIT;										// pointer argument cannot be equal to NULL

	for (int arr = 0; arr < arr_2d->rowLength; ++arr)
		Array_D(&arr_2d->buffer[arr]);					// Clean the current element of array_2D (array)


	free(arr_2d->buffer);								// Frees the memory reserved for
	arr_2d->buffer = NULL;								// Matrix (array_2d) 
	arr_2d->ColumnLength = 0;							// and cleans lengths member variables
	arr_2d->rowLength = 0;								//

}