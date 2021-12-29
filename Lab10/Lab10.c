#include <stdio.h>
const char* g_author = "Karol Warda";
typedef enum {my_false = 0, my_true = !my_false}bool;


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

void StartInfo(char* text)
{
	printf(text);
	printf("Author: %s\n\n", g_author);
}
void EndInfo() { printf("Koniec Programu\n\n\n"); }

void PrintStarsInRow(int rows, int columns)
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			putchar('*');						// row filling
		}
		putchar('\n');							// end of the row
	}
}


void Zad67()
{
	StartInfo("Program which prints number of stars inputed by user\n\n");

	const int rows = 1;														// how many * you want to go under v
	int columns = GetInteger("How many stars you want?: ", &isPositive);	// how many * you want to go right >

	PrintStarsInRow(rows, columns); printf("\n\n");
	EndInfo();
}

void Zad68()
{
	StartInfo("Program which prints n by n box of starts, where n is user input\n");

	const int columns = 5;
	int rows = GetInteger("How many starts in row you want?: ", &isPositive);

	PrintStarsInRow(rows, columns); printf("\n\n");
	EndInfo();	
}

int main()
{
	// Laboratorium 10
	// Zad 67 - 74
	Zad67();
	Zad68();

}