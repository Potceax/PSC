#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

// Constant length of 2D Arrays
#define LENGTH_ROW 25
#define LENGTH_COLUMN 25

typedef enum { my_false = 0, my_true = !my_false }bool;
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
	begin		->	begining index of current array (current row)
	end			->	end index of current array (current row)
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

bool AreElementEqualToZeroInRange(int* tab, int begin, int end)
{
	for (int i = begin; i < end; ++i) {
		if (tab[i] != 0)
			return my_false;
	}
	return my_true;
}

void BelowDiagonalZeroCheck(int tab[][LENGTH_COLUMN], int length)
{
	for (int m = 0; m < length; ++m) {
		if(!AreElementEqualToZeroInRange(tab[m], 0, m)){
			printf("Not all elements below main diagonal are equal to 0...\n");
			return;
		}
	}
	printf("All elements below main diagonal are equal to 0!\n");
}


// swaps every value from one array to another
void SwapTabs(int* tab1, int* tab2, int length)
{
	for (int index = 0; index < length; ++index) {
		int temp = tab1[index];					// temporary value of array current element

		tab1[index] = tab2[index];				//
		tab2[index] = temp;						// Swap of elemnets
	}
}

void SwapRowsIn_2D_Array(int tab[][LENGTH_COLUMN], int rows, int columns)
{
	for (int m = 0; m < rows - 1; ++m)
		SwapTabs(tab[m], tab[m + 1], columns);
}

// Returns index of max value from main diagonal of 2D Array with n X n lengths
int GetMaxDiagonalValueIndex(int tab[][LENGTH_COLUMN], int length)
{
	int maxIndex = 0;
	for (int n = 0; n < length; n++)
	{
		if (tab[maxIndex][maxIndex] < tab[n][n])
			maxIndex = n;
	}

	return maxIndex;
}


/*
Function which fills given 2D array with sum of every element from other 2D arrays
@param
	arrayToFill		->	2D argument array where sums will go
	arr1			->	2D array, first element of sum
	arr2			->	2D array, second element of sum
	rows			->	length of rows
	columns			->	length of columns
*/
void Fill_2D_ArrayWithSumOfOthers(int arrayToFill[][LENGTH_COLUMN],
	int arr1[][LENGTH_COLUMN], int arr2[][LENGTH_COLUMN], int rows, int columns)
{
	if (!arr1 || !arr2)		// error exit condition (NULL check)
		return;

	for (int m = 0; m < rows; ++m)
		for (int n = 0; n < columns; ++n)
			arrayToFill[m][n] = arr1[m][n] + arr2[m][n];
}

int GetSumFromTheArrayElements(int* array, int length)
{
	int sum = 0;
	for (int i = 0; i < length; ++i)
		sum += abs(array[i]);

	return sum;
}

void Zad94()
{
	StartInfo("Program which checks if elements below main diagonal are equal to 0\n");
	int array_2D[LENGTH_ROW][LENGTH_ROW] = { {0} };

	int length = GetInteger("Please enter length from [1, 25]: ", isInRangeOfLength);
	Fill_2D_ArrayWithInput(array_2D, length, length, "Please enter an integer number: ", NULL);

	// check if all elements below diagonal are equal to 0 and prints the answer
	BelowDiagonalZeroCheck(array_2D, length);	
	EndInfo();
}

void Zad95()
{
	StartInfo("Program which swaps two rows in 2D array\n");
	int array_2D[LENGTH_ROW][LENGTH_COLUMN] = { 0 };

	int rows = GetInteger("Please enter row length from [1, 25]: ", isInRangeOfLength);
	int columns = GetInteger("Please enter column length from [1, 25]: ", isInRangeOfLength);
	Fill_2D_ArrayWithInput(array_2D, rows, columns, "Please enter an integer number: ", NULL);

	SwapRowsIn_2D_Array(array_2D, rows, columns);

	printf("Array with swapped rows\n");
	Print_2D_Array(array_2D, rows, 0, columns, my_true, my_true);
	EndInfo();
}

void Zad96()
{
	StartInfo("Program which swaps row and column in s index in 2D array\n");
	int array_2D[LENGTH_ROW][LENGTH_COLUMN] = { 0 };

	int length = GetInteger("Please enter array length from [1, 25]: ", isInRangeOfLength);
	Fill_2D_ArrayWithInput(array_2D, length, length, "Please enter an integer number: ", NULL);

	int s = GetMaxDiagonalValueIndex(array_2D, length);

	int temp = 0;								// variable which holds value to change
	for (int m = 0; m < length; ++m) {
		temp = array_2D[m][s];					// Switch row element on s column
		array_2D[m][s] = array_2D[s][m];		// with column element on s row
		array_2D[s][m] = temp;					//
	}

	Print_2D_Array(array_2D, length, 0, length, my_true, my_true);
	EndInfo();

}

void Zad97()
{
	StartInfo("Program which calculates the value of the 2D_array from sum of the other 2D_arrays elements\n");

	int array_a[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	int array_b[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	int array_c[LENGTH_ROW][LENGTH_COLUMN] = { {0} };

	int rows = GetInteger("Please enter the row length from [1, 25]: ", &isInRangeOfLength);
	int columns = GetInteger("Please enter the column length from [1, 25]: ", &isInRangeOfLength);


	printf("First array\n");
	Fill_2D_ArrayWithInput(array_a, rows, columns, "Please enter an integer: ",NULL);

	printf("Second array\n");
	Fill_2D_ArrayWithInput(array_b, rows, columns, "Please enter an integer: ", NULL);

	Fill_2D_ArrayWithSumOfOthers(array_c, array_a, array_b, rows, columns);

	printf("Sum of two arrays\n");
	Print_2D_Array(array_c, rows, 0, columns, my_true, my_true);
	EndInfo();

}

void Zad98()
{
	StartInfo("Program which calculates the value of the 2D_array from operation on the other 2D_arrays elements\n");

	int array_a[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	int array_b[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	int array_c[LENGTH_ROW][LENGTH_COLUMN] = { {0} };

	int m = GetInteger("Please enter the row length from [1, 25]: ", &isInRangeOfLength);
	int k = GetInteger("Please enter the column length from [1, 25]: ", &isInRangeOfLength);
	int n = GetInteger("Please enter the range for the sum from [1, 25]", &isInRangeOfLength);

	printf("First array\n");
	Fill_2D_ArrayWithInput(array_a, m, k, "Please enter an integer: ", NULL);

	printf("Second array\n");
	Fill_2D_ArrayWithInput(array_b, m, k, "Please enter an integer: ", NULL);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			int sum = 0;								//
			for (int s = 0; s < n; ++s) {				//	Get the sum from the operation on
				sum += array_a[i][s] * array_b[s][j];	//  two 2D arrays
			}											//

			array_c[i][j] = sum;						// Fill element with sum
		}
	}


	printf("Sum of two arrays\n");
	Print_2D_Array(array_c, m, 0, k, my_true, my_true);
	EndInfo();

}

void Zad99()
{
	StartInfo("Program which calculates the max value in every row for 2D array\n");

	int rows = GetInteger("Please enter the row length from [1, 25]: ", &isInRangeOfLength);
	int columns = GetInteger("Please enter the column length from [1, 25]: ", &isInRangeOfLength);
	
	int array_2d[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please eneter an integer: ", NULL);

	int sum = 0;
	for (int i = 0; i < rows; ++i) {
		int currentRowSum = GetSumFromTheArrayElements(array_2d[i], columns);	// Get current row sum
		if (currentRowSum > sum)			// 
			sum = currentRowSum;			// if its bigger than sum replace it
	}

	printf("Max sum of the row from whole 2D array is equal to: %d\n", sum);
	EndInfo();
}

void Zad100()
{
	StartInfo("Program which calculates the sum of the sum in every row for 2D array\n");

	int rows = GetInteger("Please enter the row length from [1, 25]: ", &isInRangeOfLength);
	int columns = GetInteger("Please enter the column length from [1, 25]: ", &isInRangeOfLength);

	int array_2d[LENGTH_ROW][LENGTH_COLUMN] = { {0} };
	Fill_2D_ArrayWithInput(array_2d, rows, columns, "Please eneter an integer: ", NULL);

	int sum = 0;
	for (int i = 0; i < rows; ++i) {				// calculate sum operation
		for (int j = 0; j < columns; ++j) {			// for every element in 2D array
			sum += pow(abs(array_2d[i][j]), 2);		//
		}											//
	}

	printf("The value of operation is equal to: %f\n", sqrt((float)sum));
	EndInfo();
}

int main()
{
	// Labolatorium 14
	// Zadania 94 - 100
	// Autor: Karol Warda

	Zad94();
	Zad95();
	Zad96();
	Zad97();
	Zad98();
	Zad99();
	Zad100();

	printf("test");

	return 0;
}