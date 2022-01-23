#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Constant length of 2D Arrays
#define LENGTH_ROW 25
#define LENGTH_COLUMN 25

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
bool isInRangeOfLength(int num) { return num > 0 && num <= LENGTH_ROW; } // is between (0, 25)
bool isBinnary(int num) { return num == 0 || num == 1; }

void FillArrayWithInput(int* tab, int length, char* text, bool(*condition)(int num))
{
	for (int i = 0; i < length; i++)
		tab[i] = GetInteger(text, condition);
}

void FillArrayWithRandom(int* tab, int length)
{

	for (int i = 0; i < length; i++) {
		tab[i] = rand();
	}

}


/*
Function which prints array from L->R  or R->L
@param
	tab			->	array
	start		->	begining index of array
	end			->	end index of array
	isRising	->	argument for L->R(true) or R->L(false)

*/
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

/*
Function which fills array 2D with random
@param
	tab			->	2D array (written as pointer)
	rows		->	Number of Rows in array
	columns		->	Number of columns in array
*/
void Fill_2D_ArrayWithRandom(int tab[][LENGTH_COLUMN], int rows, int columns)
{
	for (int m = 0; m < rows; ++m)
		FillArrayWithRandom(tab[m], columns);	// Fills current row with random numbers

	putchar('\n');
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
void Fill_2D_ArrayWithInput(int tab[][LENGTH_COLUMN], int rows, int columns, char* text, bool(*condition)(int num))
{
	for (int m = 0; m < rows; ++m) {
		printf("ROW %d\n\n", m + 1);
		FillArrayWithInput(tab[m], columns, text, condition);	// Fills current row with input numbers
	}
	putchar('\n');

}

/*
Function which prints m over n 2D array
@Param
	tab			->	2D array
	length		->	length of m (rows) or n (columns) 
	begin		->	index of the begining
	end			->	index of end
	isInOrder	->	argument which tells if we want to print 2D array Rows->Columns(true) or Columns->rows(false)
	isRising	->	argument which tells if we want to print from L->R(true) or R->L(flase)
*/
void Print_2D_Array(int tab[][LENGTH_COLUMN], int length, int begin, int end, bool isInOrder, bool isRising)
{
	if (isInOrder) {
		for (int m = 0; m < length; m++)
			PrintArray(tab[m], begin, end, isRising);
	}
	else {
		if (isRising) {
			for (int n = 0; n < length; n++) {
				for (int m = begin; m < end; ++m)
					printf("%d ", tab[m][n]);

				putchar('\n');
			}
		}
		else {
			for (int n = length - 1; n >= 0; --n) {
				for (int m = end - 1; m >= begin; --m)
					printf("%d ", tab[m][n]);

				putchar('\n');
			}
		}
	}

}

int GetMaxValueFromArray(int tab[], int length)
{
	int maxValue = INT_MIN;		
	for (int index = 0; index < length; ++index) {		// Look through the whole array 
		if (tab[index] > maxValue)						// if current element is higher than maxValue
			maxValue = tab[index];						// get that value as maxValue 
	}													//

	return maxValue;
}

int GetMaxValueFrom_2D_Array(int tab[][LENGTH_COLUMN], int rows, int columns)
{
	int maxValue = INT_MIN;
	for (int m = 0; m < rows; ++m) {										// Look through 2D array
		int currentRowMaxValue = GetMaxValueFromArray(tab[m], columns);		// if current row max element is higher than maxValue
		if (currentRowMaxValue > maxValue)									// get that value as maxValue
			maxValue = currentRowMaxValue;									// 
	}

	return maxValue;
}


// Function which returns true/false
// depending if in every row there is exactly one element with value of argument
bool Does_2D_ArrayHasExactlyOneValueInEveryRow(int tab[][LENGTH_COLUMN], int rows, int columns, int valueToFind)
{
	for (int m = 0; m < rows; ++m) {			// loop through every row and column 
		int numberOfArgumentValue = 0;			// set variable for number of argument value
		for (int n = 0; n < columns; ++n) {
			if (tab[m][n] == valueToFind)		// if current element is equal to argument value
				++numberOfArgumentValue;		// increment variable value
		}

		if (numberOfArgumentValue != 1)			// check if current row has exactly one 1
			return my_false;
	}
	return my_true;
}

void Zad87()
{
	StartInfo("Program which prints 2D array filled with user input\n");
	int rows = GetInteger("Type number of rows: ", &isInRangeOfLength);
	int columns = GetInteger("Type number of columns: ", &isInRangeOfLength);

	int array_2d[LENGTH_ROW][LENGTH_COLUMN] = { {0} };

	//Fill_2D_ArrayWithRandom(array_2d, rows, columns);
	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please enter positive number: ", NULL);
	Print_2D_Array(array_2d, rows, 0, columns, my_true, my_true);

	EndInfo();
}

void Zad88()
{
	StartInfo("Program which prints 2D array of m rows and n columns in order columns->rows\n");
	int rows = GetInteger("Type number of rows: ", &isInRangeOfLength);
	int columns = GetInteger("Type number of columns: ", &isInRangeOfLength);

	int array_2d[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please enter positive number: ", NULL);
	Print_2D_Array(array_2d, columns, 0, rows, my_false, my_true);

	EndInfo();
}

void Zad89()
{
	StartInfo("Program which finds max element in 2D array filled by user\n");
	int rows = GetInteger("Type number of rows: ", &isInRangeOfLength);
	int columns = GetInteger("Type number of columns: ", &isInRangeOfLength);

	int array_2d[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please enter positive number: ", NULL);

	printf("The max value of 2D array is equal to %d\n", GetMaxValueFrom_2D_Array(array_2d, rows, columns));
	EndInfo();
}

void Zad90()
{
	StartInfo("Program which fills 2D array with 0 and 1 and tells if every row have only one 1\n");
	int rows = GetInteger("Type number of rows: ", &isInRangeOfLength);
	int columns = GetInteger("Type number of columns: ", &isInRangeOfLength);

	int array_2d[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please enter positive number: ", &isBinnary);

	int value = 1;	// value you are looking for
	bool hasOneInEveryRow = Does_2D_ArrayHasExactlyOneValueInEveryRow(array_2d, rows, columns, value);

	if (hasOneInEveryRow)
		printf("Array have exactly one 1 in every row!\n");
	else
		printf("Array doesn't have exactly one 1 in every row...\n");

	EndInfo();
}

void Zad91()
{
	StartInfo("Program which fills 2D array with inputs and gives sum of every element\n");
	int rows = GetInteger("Type number of rows: ", &isInRangeOfLength);
	int columns = GetInteger("Type number of columns: ", &isInRangeOfLength);

	int array_2d[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please enter positive number: ", NULL);

	int sum = 0;
	for (int m = 0; m < rows; m++)			// loops through full 2D array
		for (int n = 0; n < columns; n++) 	// 
			sum += array_2d[m][n];			// and adds every element value to sum

	printf("The sum of every element in 2D array is equal to: %d\n", sum);
	EndInfo();

}


void Zad92() 
{
	StartInfo("Program which gets sum of main diagonal in 2D array\n");
	int rows = GetInteger("Type number of rows and columns (cannot be higher then 25): ", &isInRangeOfLength);
	int columns = rows;
	const int length = rows;

	int array_2d[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please enter positive number: ", NULL);

	int sum = 0;
	for (int n = 0; n < length; ++n)	//
		sum += array_2d[n][n];			// adds to sum every [n][n] element 

	printf("Sum of elements on main diagonal is equal to: %d\n", sum);
	EndInfo();
}


int main()
{
	// Labolatorium nr 13
	// Zad 87 - 92
	// Autor: Karol Warda

	// Debug Option
	srand(time(NULL));


	Zad87();
	Zad88();
	Zad89();
	Zad90();
	Zad91();
	Zad92();


	return 0;


}

