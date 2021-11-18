#include <stdio.h>
#include <math.h>
#define LENGTH 3

typedef enum {my_false = 0, my_true = !my_false} bool;

char GetCharacter(char* text)
{
	char c;
	while (my_true) {
		bool isCorrect = my_true;

		printf("%s", text);
		if (!scanf_s("%c", &c) /*&& getchar() != '\n'*/) {
			printf("Error - Passed value is not an int type\n");
			isCorrect = !isCorrect;
		}
		while (getchar() != '\n');		// to clear out the buffer

		if (isCorrect)
			return c;
	}
}

// Format SHOULD ONLY BE for base types (hex, dec, octal, bin)
int GetIntNumber(char* text, char* format)
{
	int num;
	while (my_true) {
		bool isCorrect = my_true;

		printf("%s", text);
		if (!scanf_s(format, &num) /*&& getchar() != '\n'*/) {
			printf("Error - Passed value is not an int type\n");
			isCorrect = !isCorrect;
		}
		while (getchar() != '\n');		// to clear out the buffer

		if (isCorrect)
			return num;
	}
}

double GetDoubleNumber(char* text)
{
	double num;
	while (my_true) {
		bool isCorrect = my_true;

		printf("%s", text);
		if (!scanf_s("%lf", &num) /*&& getchar() != '\n'*/) {
			printf("Error - Passed value is not a double type\n");
			isCorrect = !isCorrect;
		}
		while (getchar() != '\n');		// to clear out the buffer

		if (isCorrect)
			return num;
	}
}


double functionDouble34(double x)
{
	double firstEq = pow(x, 2) + 1;

	double sinOfFirstEq = sin(firstEq);

	return sqrt(firstEq) + (log(firstEq) / (5 + sinOfFirstEq)) - exp(sinOfFirstEq);
}



double functionDouble36(double x)
{
	double eq = x - 2;
	return eq * (eq *(17 + 23 * eq) + 13);
	
}

double functionDouble37(double x, double y)
{
	double pX = x * x;
	double pY = y * y;

	double sum = pX + pY;


	return y + sqrt(sum) + (sum / cos(pX));
}

double functionDouble39(double x)
{
	switch (x > 0) {
	case 1:
		return pow(2, x);
	default:
		return -1;
	}
}

int add(int x, int y) { return x + y; }
int od(int x, int y) { return x - y; }
int multi(int x, int y) { return x * y; }
int div(int x, int y)
{
	if (y == 0)
		return 0;
	return x / y;
}

int PrintResult(int x, int y, char c)
{
	switch (c) {
	case '+':
		printf("The result of %d + %d is equal to% d\n\n", x, y, add(x,y));
		return add(x, y);
	case '-':
		printf("The result of %d - %d is equal to% d\n\n", x, y, od(x,y));
		return od(x, y);
	case '*':
		printf("The result of %d * %d is equal to% d\n\n", x, y, multi(x,y));
		return multi(x, y);
	case '/':
		printf("The result of %d / %d is equal to% d\n\n", x, y, div(x,y));
		return div(x, y);
	default:
		printf("Error - wrong character\n\n");
		return -1;
	}
}

void Zad34()
{
	printf("Program which takes input x from the user and Prints the value of the function f(x)\n");
	printf("Autor: Karol Warda\n\n");

	double x = GetDoubleNumber("Please enter the double value: ");

	printf("The f(x) function is equal to %.2f\n\n", functionDouble34(x));

	printf("Koniec Programu\n\n\n");
}

void Zad35()
{
	printf("Program which takes int input and returns the value of it powered to 8th power\n");
	printf("Autor: Karol Warda\n\n");

	int x = GetIntNumber("Please enter an integer value: ", "%d");

	printf("The number %d powered to the 8th power is equal to: ", x);
	x = (x *= (x *= (x *= x)));
	printf("%d\n\n", x);

	printf("Koniec Programu\n\n\n");
}


void Zad36()
{
	printf("Program which takes input x from the user and Prints the value of the function f(x)\n");
	printf("Autor: Karol Warda\n\n");

	double x = GetDoubleNumber("Please enter the double value: ");

	printf("The f(x) function is equal to %.2f\n\n", functionDouble36(x));
}

void Zad37()
{
	printf("Program which takes input x and y from the user and Prints the value of the function f(x, y)\n");
	printf("Autor: Karol Warda\n\n");

	double x;
	double y;

	do {
		printf("Please enter: \n");
		x = GetDoubleNumber("x double value: ");
		y = GetDoubleNumber("y double value: ");

		if (fabs(x) >= 1 || fabs(y) >= 1)
			printf("Error - value x or y in module are > 1\n");

	} while (fabs(x) >= 1 || fabs(y) >= 1);

	printf("The f(x) function is equal to %.2f\n\n", functionDouble37(x, y));

	printf("Koniec Programu\n\n\n");
}

void Zad38()
{
	printf("Program which takes input x and y from the user and gives him a choice to +, -, *, /\n");
	printf("Autor: Karol Warda\n\n");

	int x = GetIntNumber("x integer value: ", "%d");
	int y = GetIntNumber("y integer value: ", "%d");
	char c = GetCharacter("Choose one: (+, -, *, /): ");

	PrintResult(x, y, c);

	printf("Koniec Programu\n\n\n");
}

void Zad39()
{
	printf("Program which takes input x from the user and Prints the value of the function f(x)\n");
	printf("Autor: Karol Warda\n\n");

	double x = GetDoubleNumber("Please enter the double value: ");

	printf("The f(x) function is equal to %.2f\n\n", functionDouble39(x));

	printf("Koniec Programu\n\n\n");
}

int main()
{
	/*Zad34();*/
	/*Zad35();*/
	/*Zad36();*/
	/*Zad37();*/
	/*Zad38();*/
	Zad39();

}