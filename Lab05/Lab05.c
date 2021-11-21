#include <stdio.h>
#include <math.h>

typedef enum {my_false = 0, my_true = !my_false} bool;

typedef struct
{
	double x;
	double y;
} Point;


// The function pointer is an overkill but I wanted to try it out
char GetCharacter(char* text, bool (*condition)(char c))
{
	char c;
	while (my_true) {
		printf("%s", text);
		c = getchar();
		while (getchar() != '\n');		// to clear out the buffer

		if (condition(c))		// checks condition inside a function which was passed by argument
			return c;

		printf("Error - %c is a wrong character\n", c);
	}
}

bool IsMathChar(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

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

// Prints and returns value of chosen equasion
int PrintOperationResult(int x, int y, char c)
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
		if (y == 0) {
			printf("Error You cannot divide by 0\n\n");
			return -1;
		}
		else
		{
			printf("The result of %d / %d is equal to% d\n\n", x, y, div(x, y));
			return div(x, y);
		}
	default:										// With function pointer checking condition default is not needed
		printf("Error - wrong character\n\n");
		return -1;
	}
}


double FirstDistanceAlgorithm(const Point point)
{
	return sqrt(pow(point.x, 2) + pow(point.y, 2));
}

double SecondDistanceAlgorithm(const Point point)
{
	if (point.x == 0.0)
		return fabs(point.y);
  	else if ((fabs(point.x) >= fabs(point.y)) && point.x != 0.0)
		return fabs(point.x) * sqrt(1 + pow(point.y / point.x, 2));
	else
		return fabs(point.y) * sqrt(1 + pow(point.x / point.y, 2));
	
}

// determine if answers for algorithms are equal
void PrintAnswerForDistanceAlgorithms(const Point point)
{
	double distanceOfFirstAlgorithm = FirstDistanceAlgorithm(point);
	double distanceOfSecondAlgorithm = SecondDistanceAlgorithm(point);

	if (distanceOfFirstAlgorithm == distanceOfSecondAlgorithm) {
		printf("OBA ALGORYTMY DAJA TEN SAM WYNIK.\n");
		printf("Odleglosc punktu (%.lf,% .lf) od (0, 0) wynosi %.17g\n\n", point.x, point.y, distanceOfFirstAlgorithm);
	}
	else {
		printf("ALGORYTMY DAJA ROZNE WYNIKI.\n");
		printf("Odleglosc punktu (%.lf,% .lf) od (0, 0) wynosi:\n", point.x, point.y);
		printf("-wg \"klasycznego\" algorytmu %.17g\n", distanceOfFirstAlgorithm);
		printf("-wg \"specjalnego\" algorytmu %0.17g\n\n", distanceOfSecondAlgorithm);

		printf("Wartosc bezwzgledna roznicy miedzy wynikami:\n%.17g\n\n", fabs(distanceOfFirstAlgorithm - distanceOfSecondAlgorithm));
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
	
	bool(*statment) = &IsMathChar;			// function pointer is needed for GetCharacter()
	char c = GetCharacter("Choose one: (+, -, *, /): ", statment);

	PrintOperationResult(x, y, c);

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

void Zad40()
{
	printf("Program which takes input x nad y from the user and determine distance from two algorithms\n");
	printf("Autor: Karol Warda\n\n");

	Point input;

	printf("Please enter\n");
	input.x = GetDoubleNumber("X point value: ");
	input.y = GetDoubleNumber("Y point value: ");

	PrintAnswerForDistanceAlgorithms(input);


}

int main()
{
	// Lab05
	// Zad 34 - 35
	// Autor: Karol Warda

	Zad34();
	Zad35();
	Zad36();
	Zad37();
	Zad38();
	Zad39();
	Zad40();
}