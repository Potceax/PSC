#include <stdio.h>
const char* g_author = "Karol Warda";
typedef enum {my_false = 0, my_true = !my_false}bool;


void StartInfo(char* text)
{
	printf(text);
	printf("Author: %s\n\n", g_author);
}
void EndInfo() { printf("Koniec Programu\n\n\n"); }



// Function which gets integer number if its correct
// put NULL at condition argument if you dont want specified conditions
int GetInteger(char* text, bool (*condition)(int num))
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
bool isInRange(int num) { return (num >= 1 && num <= 9); }


void PrintCharacterInRowAndColumn(char c, int rows, int columns)
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			putchar(c);						// row filling
		}
		putchar('\n');						// end of the row
	}
}

void PrintCharacters(char c, int howMany)
{
	for (int i = 0; i < howMany; i++)
		putchar(c);
}





/*Multiplication table functions */

void UpperPrep(int size)
{
	/* Upper tabel */
	putchar('\t');
	for (int i = 1; i <= size; ++i)
		printf("%5d", i);
	putchar('\n');
	PrintCharacters('-', size * 5 + 8);			// size * 5 + 8 because there are 5 spaces between numbers and first '\t' takes 8 spaces 
	putchar('\n');
}

void SideAndMiddlePrep(int size)
{
	/* side and fill */
	for (int row = 1; row <= size; ++row) {
		printf("%2d |\t", row);
		for (int column = 1; column <= size; ++column) {
			printf("%5d", row * column);
		}
		putchar('\n');
	}
}

void MultiTable(int size)
{
	UpperPrep(size);
	SideAndMiddlePrep(size);
}




void Print_ASCII_tableCharacter(int code)
{
	switch (code)
	{
		case 0:
			printf("%5s\n", "nul");
			break;
		case 7:
			printf("%5s\n", "bel");
			break;
		case 8:
			printf("%5s\n", "bs");
			break;
		case 9:
			printf("%5s\n", "ht");
			break;
		case 10:
			printf("%5s\n", "nl");
			break;
		case 11:
			printf("%5s\n", "vt");
			break;
		case 12:
			printf("%5s\n", "np");
			break;
		case 13:
			printf("%5s\n", "cr");
			break;
		case 26:
			printf("%5s\n", "eof");
			break;
		case 27:
			printf("%5s\n", "esc");
			break;
		case 127:
			printf("%5s\n", "del");
			break;
		default:
			printf("%5c\n", code);
	}
}


/* Exercise functions */

void Zad67()
{
	StartInfo("Program which prints number of stars inputed by user\n\n");

	const int rows = 1;														// how many * you want to go under v
	int columns = GetInteger("How many stars do you want?: ", &isPositive);	// how many * you want to go right >

	PrintCharacterInRowAndColumn('*', rows, columns); printf("\n\n");
	EndInfo();
}

void Zad68()
{
	StartInfo("Program which prints n by n box of starts, where n is user input\n");

	int rows = GetInteger("How many row do you want?: ", &isPositive);
	const int columns = rows;

	PrintCharacterInRowAndColumn('*', rows, columns); printf("\n\n");
	EndInfo();	
}

void Zad69()
{
	StartInfo("Program which prints n by n/2 rectangle of starts, where n is user input\n");

	int columns = GetInteger("How many columns do you want?: ", &isPositive);
	const int rows = columns / 2;

	PrintCharacterInRowAndColumn('*', rows, columns); printf("\n\n");
	EndInfo();
}

void Zad70()
{
	StartInfo("Program which prints triangle of n row starts, where n is user input\n");

	int size = GetInteger("How many rows do you want?: ", &isPositive);	
	
	const int rows = 1;									// variable for proper triangle build (is used in function)
	int columns = 1;

	while (columns <= size)								// O(n^3) but I dont want to bloat this file with simillar functions 
		PrintCharacterInRowAndColumn('*', rows, columns++);
	printf("\n\n");

	EndInfo();
}

void Zad71()
{
	StartInfo("Program which prints festive tree of n row starts, where n is user input\n");

	int size = GetInteger("How many rows do you want?: ", &isPositive);

	const int rows = 1;
	int columns = 1;

	for (int spaces = size - 1; spaces >= 0; --spaces, columns += 2) {
		PrintCharacters(' ', spaces);
		PrintCharacterInRowAndColumn('*', rows, columns);
	}
	printf("\n\n");

	EndInfo();
}

void Zad72()
{
	StartInfo("Program which prints multiplication table from 1 to 15\n");

	const int size = 15;

	MultiTable(size);
	printf("\n\n");

	EndInfo();
}

void Zad73()
{
	StartInfo("Program which prints ASCII character table from 0 to 255\n");
	
	const int size = 255;

	printf("ASCII Table\n");
	printf("%3s%5s\n", "Dec", "Char");
	for (int i = 0; i <= size; ++i) {
		printf("%3d", i);
		Print_ASCII_tableCharacter(i);
	}
	printf("\n\n");

	EndInfo();
}

void Zad74()
{
	StartInfo("Program which prints sum of n = {0, ..., 9} n numbers: 1 + 22 + 333 + ... + nn...n\n");

	int sum = 0;
	int size = GetInteger("How many numbers do you want?: ", &isInRange);

	for (int n = 1; n <= size; ++n) {
		int number = 0;
		for (int j = 0; j < n; ++j) {					// making current n number
			number = number * 10 + n;			
		}
		sum += number;									// summing it up

		printf("%d", number);

		if (n < size)									// check for symbol
			printf(" + ");
		else
			printf(" = ");

	}
	printf("%d\n\n", sum);
	EndInfo();
}

int main()
{
	// Laboratorium 10
	// Zad 67 - 74
	Zad67();
	Zad68();
	Zad69();
	Zad70();
	Zad71();
	Zad72();
	Zad73();
	Zad74();
}