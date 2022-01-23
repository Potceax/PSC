#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef enum {my_false = 0, my_true = !my_false}bool;
const char* g_author = "Karol Warda";

void StartInfo(char* text)
{
	printf(text);
	printf("Author: %s\n\n", g_author);
}
void EndInfo() { printf("Koniec Programu\n\n\n"); }


// Function which gets integer number if its correct
// put NULL at condition argument if you dont want specified conditions
int GetInteger(char* text, bool(*condition)(int num))
{
	int result = 0;

	while (my_true) {
		printf(text);
		if (!scanf_s("%d", &result) || (condition != NULL && !condition(result)) || getchar() != '\n') {
			printf("Error - wrong format\n\n");
			while (getchar() != '\n');		// Buffer clean if wrong
		}
		else
			return result;
	}
}
bool isPositive(int num) { return num > 0; }


void FillArrayWithInput(int* tab, int length, char* text, bool(*condition)(int num))
{
	for (int i = 0; i < length; i++)
		tab[i] = GetInteger(text, condition);
}

void FillArrayWithRandom(int* tab, int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		tab[i] = rand();
}

void PrintArray(int* tab, int start, int end, bool isRising)
{
	if (isRising) {
		for (int i = start; i < end; ++i)
			printf("%d ", tab[i]);
	}
	else {
		for (int i = end - 1; i >= start; --i)
			printf("%d ", tab[i]);
	}
	printf("\n\n");
}

void Create_2D_Array(int** tab, int rows, int columns)
{
	tab = (int*)malloc(rows * sizeof(int*));
	if (!tab) {
		printf("Error - memory allocation failed\n\n");
		return;
	}

	for (int row = 0; row < rows; ++row) {
		tab[row] = (int)malloc(columns * sizeof(int));

		if (!tab[row]) {
			printf("Error - memory allocation failed\n\n");
			return;
		}
	}
}

void Delete_2D_Array(int** tab, int rowLength)
{
	for (int row = 0; row < rowLength; ++row) {
		free(tab[row]);
		tab[row] = NULL;
	}
	free(tab);
	tab = NULL;
}

/*
Function which fills array 2D with random

@param
	tab			->	2D array (written as pointer)
	rows		->	Number of Rows in array
	columns		->	Number of columns in array
*/
void Fill_2D_ArrayWithRandom(int** tab, int rows, int columns)
{
	for (int m = 0; m < rows; ++m)
		FillArrayWithRandom(tab[m], columns);	// Fills current row with random numbers
}

/*
Function which fills array 2D with input

@param
	tab			->	2D array (written as pointer)
	rows		->	Number of Rows in array
	columns		->	Number of columns in array
	text		->	text for GetInput Command
	condition	->	pointer function which takes condition for GetInput check (type NULL to ignore)

*/
void Fill_2D_ArrayWithInput(int** tab, int rows, int columns, char* text, bool(*condition)(int num))
{
	for (int m = 0; m < rows; ++m) {
		if (!tab[m]) {
			printf("Error - current row is equal NULL");
		}

		FillArrayWithInput(tab[m], columns, text, condition);	// Fills current row with input numbers
	}

}



void Print_2D_Array(int** tab, int rows, int start, int end, bool isRising)
{
	for (int m = 0; m < rows; m++)
		PrintArray(tab[m], start, end, isRising);
}


void Zad87()
{
	StartInfo("Program which prints 2D array filled with user input");
	int rows = GetInteger("Type number of rows: ", &isPositive);
	int columns = GetInteger("Type number of columns: ", &isPositive);

	int** array_2d = NULL;
	Create_2D_Array(array_2d, rows, columns);

	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please enter positive number", NULL);
	Print_2D_Array(array_2d, rows, 0, columns, my_true);

	Delete_2D_Array(array_2d, rows);

	EndInfo();
}

int main()
{
	Zad87();

	return 0;


}

