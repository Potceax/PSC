#include <stdio.h>
#include <limits.h>

typedef enum {my_false = 0, my_true = !my_false} bool;
const char* g_author = "Karol Warda";


int Power(int base, int pow)
{
	int result = 1;
	for (int i = 0; i < pow; ++i)
		result *= base;

	return result;
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

long double f(int numerator, int n)
{
	if (n <= 1)
		return ((numerator / n + 1));
	else
		return f(numerator, n-1) + ((numerator / n + 1) * (RecPower(numerator, n) / (long double)Factorial(n)));
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
	
	for (int i = 1; i <= 20; i++) {
		if (Factorial(i) < 0) {
			printf("factorial of and higher %d cannot be hold in int type variables\n\n", i);
			break;
		}

		printf("!%d = %d\n", i, Factorial(i));
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
	const int numerator = 3;
	for (int n = minRange; n < maxRange; n++) {
		long double funct = f(numerator, n);

		if (funct < 0) {
			printf("Error - function for n >= %d cannot be stored in double\n\n", n);
			break;
		}

		printf("f(%d) = %.3lf\n", n, funct);
	}
	putchar('\n');

	printf("Koniec Programu\n\n\n");

}

void Zad51()
{
	printf("Program which calculate value of f(n) = 90^n/(n+1)! and find min n which for f(n) < 1\n");
	printf("Author:% s\n\n", g_author);


	int n = 1;
	const int numerator = 90;
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
	// do it with the photo example 


	printf("Program which takes string input and deletes all spaces in between words\n");
	printf("Author:% s\n\n", g_author);

	char* text = "";
	printf("Please enter a text string: ");




}

int main()
{
	Zad48();
	Zad49();
	Zad50();
	Zad51();
	//Zad52();

	return 0;
}