#include <stdio.h>

typedef enum {my_false = 0, my_true = !my_false} bool;
const char* g_author = "Karol Warda";

int GetInteger(char* text)
{
	int result = 0;
	while (my_true) {

		printf(text);
		if (!scanf_s("%d", &result) || getchar() != '\n') {
			printf("Error - wrong format or the number wasn't integer\n\n");
			while (getchar() != '\n');			// Buffer cleaning if incorrect (no need to clean when result is correct)
		}
		else
			return result;
	}
}

char GetCharacterT(char* text)
{
	char result;
	while (my_true) {
		printf(text);
		printf("Your input: ");
		result = getchar();												// Getting input from user

		if (result != 't' || getchar() != '\n') {						// Condition and extra character check
			printf("Error - Wrong character or Too many of them\n\n");
			while (getchar() != '\n');									// cleaning extra characters in buffer
		}
		else
			return result;
	}
}


long double RecPower(int base, int pow)
{
	if (pow <= 0)
		return 1;

	return base * RecPower(base, pow - 1);
}

int Factorial(int n)
{
	// condition for last recurention
	if (n <= 1)
		return 1;	

	return Factorial(n - 1) * n;	// ex. 6! = 6 * (6-1) * (6 - 2)... = 720
}

long double f(long double numerator, int n)
{
	if (n <= 1)
		return numerator / ((long double)n + 1);							// initial f(n) value for n = 1
	else
		return f(numerator, n - 1) * numerator / ((long double)n + 1);		// k/(n + 1) * f(n - 1)
}

void Zad48()
{
	printf("Program which prints first 50 powers of 2\n");
	printf("Author:% s\n\n", g_author);

	const int base = 2;

	int i = 0;
	while (i < 50) {
		int result = RecPower(base, i);		

		if (result < 0) {
			printf("Error - 2 Powered to number %d cannot be hold in integer type variable\n\n", i);
			break;
		}

		printf("Power number %d: %d\n", i, result);

		++i;
	}
	putchar('\n');
	

	printf("Koniec Programu\n\n\n");
}


void Zad49()
{
	printf("Program which tries to prints first 20 factorials as int type variables\n");
	printf("Author:% s\n\n", g_author);

	const int maxRange = 20;
	int i = 1;
	while(i <= 20) {
		if (Factorial(i) < 0) {
			printf("factorial of and higher %d cannot be hold in int type variables\n\n", i);
			break;
		}

		printf("!%d = %d\n", i, Factorial(i));
		++i;
	}
	putchar('\n');

	printf("Koniec Programu\n\n\n");
}

void Zad50()
{
	printf("Program which calculate value of f(n) = 3^n/(n+1)! for n = 1, 2, 3, ..., 200\n");
	printf("Author:% s\n\n", g_author);

	const int minRange = 1;
	const int maxRange = 200;
	const long double numerator = 3.0;
	for (int n = minRange; n <= maxRange; n++) {
		long double funct = f(numerator, n);

		if (funct < 0) {
			printf("Error - function for n >= %d cannot be stored in double\n\n", n);
			break;
		}

		printf("f(%d) = %.16lf\n", n, funct);
	}
	putchar('\n');

	printf("Koniec Programu\n\n\n");

}

void Zad51()
{
	printf("Program which calculate value of f(n) = 90^n/(n+1)! and find min n which for f(n) < 1\n");
	printf("Author:% s\n\n", g_author);


	int n = 1;
	const long double numerator = 90.0;
	while (my_true) {
		long double funct = f(numerator, n);

		if (funct < 1.0)
			break;

		++n;
	}
	printf("Minimal n which gives < 1 for f(n) is equal to: %d\n\n", n);

	printf("Koniec Programu\n\n\n");
}

void Zad52()
{
	// No functions for this Exercise - wanted to process how getchar() is working here

	printf("Program which takes string input and deletes all spaces in between words\n");
	printf("Author:% s\n\n", g_author);

	char current = '0';				// Character to override with getchar()
	char previous = '0';			// Character to override with char current


	// Comunicating with user, preperation for setting/getting input
	printf("Please enter a string: ");
	current = getchar();
	printf("End result: ");


	while (my_true) { 
		if (current == '\n')		// Program ends when ENTER was current char
			break;

		// Checking for SPACE
		if (current != ' ') {		
			putchar(current);
		}
		else {
			if (previous == ' ')
				putchar(current);
		}

		// overriding characters
		previous = current;
		current = getchar();
	}
	printf("\n\n");
	printf("Koniec Programu\n\n\n");
}

void Zad53()
{
	printf("Program which takes user integer input and prints the result\n");
	printf("Author:% s\n\n", g_author);

	int num = GetInteger("Please enter an integer number: ");

	printf("The number is equal to: %d\n\n", num);
	printf("Koniec Programu\n\n\n");
}

void Zad54()
{
	printf("Program which takes user char input and prints the result only if character is \'t\'.\n");
	printf("Author:% s\n\n", g_author);

	char c = GetCharacterT("Please enter the \'t\' character: ");

	printf("The character is equal to: %c\n\n", c);
	printf("Koniec Programu\n\n\n");
}


int main()
{
	// Labolatorium 7
	// Zad 48 - 54
	// Autor Karol Warda

	Zad48();
	Zad49();
	Zad50();
	Zad51();
	Zad52();
	Zad53();
	Zad54();

	return 0;
}