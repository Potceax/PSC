#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

typedef enum {my_false = 0, my_true = !my_false} bool;
typedef enum {name_capitalError, name_smallError, name_notAlphaError, name_correct}name;
const char* g_author = "Karol Warda";

int GetInteger(char* text)
{
	int result = 0;

	while (my_true) {
		printf(text);

		if (!scanf_s("%d", &result) || getchar() != '\n') {
			printf("Error - The number is incorrect\n\n");
			while (getchar() != '\n');
		}
		else
			return result;
	}
}

double GetDouble(char* text)
{
	double result = 0.0;

	while (my_true) {
		printf(text);

		if (!scanf_s("%lf", &result) || getchar() != '\n') {
			printf("Error - The number is incorrect\n\n");
			while (getchar() != '\n');
		}
		else
			return result;
	}
}

name IsCharCorrect(char c, int index)
{
	if (!isalpha(c))									// checks if character isn't from alphabet
		return name_notAlphaError;

	if (index == 0 && !(c >= 'A' && c <= 'Z'))			// Checks if first character isn't capital
		return name_capitalError;

	if (index > 0 && !(c >= 'a' && c <= 'z'))			// Checks if other characters aren't small
		return name_smallError;

	return name_correct;
}

void PrintError(name typeOfError)
{
	switch (typeOfError) {
	case name_notAlphaError:
		printf("Name should only be made out of letters\n\n");
		break;
	case name_capitalError:
		printf("Name should start with capital letter\n\n");
		break;
	case name_smallError:
		printf("Name should only have capital letters at the begining\n\n");
		break;
	default:
		printf("Error - Something with the name isn't right...\n\n");
		break;
	}
}

long long NumPower(int base, int pow)
{
	long long result = 1;
	for (int i = 0; i <= pow; i++) {
		printf("%d powered to %d = %lld\n", base, i, result);
		result *= base;
	}
	putchar('\n');

	return result;
}


void Zad62()
{
	printf("Program which takes Name input\n");
	printf("Author:% s\n\n", g_author);

	while (my_true) {												// main loop
		int counter = 0;
		name nameError = name_correct;

		printf("Please enter a name: ");
		char c = getchar();
		printf("Your name is ");
		while (my_true) {											// Checking loop

			if (c == '\n')											// Exit condition
				break;

			// checks and sets condition if not correct
			if ((nameError = IsCharCorrect(c, counter)) != name_correct)
				break;
			

			putchar(c);												//	Prints character

			c = getchar();											//
			++counter;												//	itteration of char and counter
		}

		if (nameError != name_correct) {
			printf("...?\n");
			PrintError(nameError);									// prints different error messages
			while (getchar() != '\n');
		}
		else {
			putchar('\n');
			break;
		}
	}
	printf("Koniec Programu\n\n\n");
}

void Zad63()
{
	const double start = 0.0;
	const double end = 0.125;
	const int howMuch = 33;

	double krok = (end - start) / (howMuch - 1);//odl. miedzy pkt. int i=0; 
	printf("Program oblicza bledy przyblizenia");
	printf(" funkcji sin(x) przez x\ndla %d",howMuch); 
	printf(" rownoodleglych punktow z przedzial"); 
	printf("u [%.g,%g].\n\n%-14s",start, end,"x"); 
	printf("%-13s%-12s","sin(x)","x-sin(x)"); 
	printf("%-12s\n","|(x-sin(x))/x|");

	for (int i = 0; i <= howMuch; ++i) {
		double x = start + i * krok;
		double sin_x = sin(x);

		double bl_b = x - sin(x);
		double bl_w;
		if (x != 0.0)
			bl_w = fabs(bl_b / x);
		else
			bl_w = -1.0;

		printf("\n%11.9f%14.9f%12.3e", x, sin_x, bl_b);

		if(bl_w != -1.0)
			printf("%12.3e", bl_w);
	}
	printf("\nKoniec Programu\n\n\n");
}

void Zad64()
{
	printf("Program which prints 10 numbers starting from (INT_MAX - 5)\n");
	printf("Author:% s\n\n", g_author);

	// Prints next numbers of (INT_MAX - 5)
	for (int i = 1; i <= 10; i++)
		printf("%d. %d\n", i, (INT_MAX - 5) + i);	// After 5 itteration The shown number goes out of range
	putchar('\n');

	printf("Koniec Programu\n\n\n");

}

void Zad65()
{
	printf("Program which takes the number n from user and shows every power of 2 until n\n");
	printf("Author:% s\n\n", g_author);

	const int base = 2;
	int pow = 1;

	// Gets Positive Integer
	while (my_true) {
		pow = GetInteger("Please enter power of the number: ");
		if (pow > 0)
			break;

		printf("Error - Number need to be positive\n\n");
	}
	NumPower(base, pow);		// Prints every power of 2 until pow

	printf("Koniec programu\n\n\n");
}

void Zad66()
{
	printf("Program which takes 10 floating point numbers and prints their art. avarage\n");
	printf("Author: %s\n\n", g_author);

	double average = 0.0;

	int counter = 0;
	const int maxRange = 10;
	for (int counter = 0; counter < maxRange; counter++) {
		printf("Number no.%d \n", counter + 1);
		average += GetDouble("Enter a double value: ");
		putchar('\n');
	}
	average /= maxRange;	// takes art. avarage by dividing it by the number count

	printf("The average of 10 floating point numbers is equal to: %lf\n\n", average);
	printf("Koniec Programu\n\n\n");
}

int main()
{
	// Labolatorium 9
	// Zad 62 - 66
	// Autor: Karol Warda

	Zad62();
	Zad63();
	Zad64();
	Zad65();
	Zad66();
}