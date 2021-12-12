#include <stdio.h>
#include <math.h>
#include <limits.h>
#define M_PI 3.14159265358979323846

typedef enum {my_false = 0, my_true = !my_false }bool;
typedef enum { menu_exit, menu_input, menu_add, menu_subtract, menu_multi, menu_div, menu_error }menu;
typedef enum { area_exit, area_sidex3, area_sideHeight, area_angleSide2x, area_error }area;
char* g_author = "Karol Warda";

int GetInteger(char* text)
{
	int result = 0;
	while (my_true) {

		printf(text);
		if (!scanf_s("%d", &result) || getchar() != '\n') {
			printf("Error - Wrong format or number isn't integer\n\n");
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
			printf("Error - Wrong format or number isn't double\n\n");
			while (getchar() != '\n');
		}
		else 
			return result;
	}
}

bool isBase2Char(char c){ return (c == '1' || c == '0'); }

long long ToBase10(long long baseNum, int base)
{
	long long result = 0;
	int multi = 1;
	while (baseNum > 0) {
		int current = baseNum % 10;
		result += (long long)current * multi;

		multi *= base;
		baseNum /= 10;
	}

	return result;
}




/*
	Functions to Zad59() 
*/

menu GetCommand()
{
	char* text = "0. Zakoncz programn\n1. Wczytaj liczby\n2. Dodaj\n3. Odejmij\n4. Pomnoz\n5. Podziel\n\nYour input: ";
	int input = GetInteger(text);

	switch (input)
	{
		case 0:
			return menu_exit;
		case 1:
			return menu_input;
		case 2:
			return menu_add;
		case 3:
			return menu_subtract;
		case 4:
			return menu_multi;
		case 5:
			return menu_div;
		default:
			return menu_error;
	}
}

void Input(int* a, int* b)
{
	*a = GetInteger("Please enter first number: ");
	*b = GetInteger("Please enter second number: ");
	putchar('\n');
}

int Add(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }
int Multiply(int a, int b) { return a * b; }
int Divide(int a, int b) { return a / b; }

void Calculate(int a, int b, int(*operation)(int a, int b))
{
	if (a == NULL && b == NULL) {
		printf("Error - variables are empty\n\n");
		return;
	}
	else
		printf("Selected operation gives value of: %d\n\n", operation(a, b));
}

bool CommandCheck(menu command, int* a, int* b)
{
	switch (command)
	{
		case menu_input:
			Input(a, b);
			return my_true;
		case menu_add:
			Calculate(*a, *b, &Add);
			return my_true;
		case menu_subtract:
			Calculate(*a, *b, &Subtract);
			return my_true;
		case menu_multi:
			Calculate(*a, *b, &Multiply);
			return my_true;
		case menu_div:
			Calculate(*a, *b, &Divide);
			return my_true;
		case menu_error:
			printf("Error - wrong command\n\n");
			return my_true;

		case menu_exit:
			return my_false;
	}
}






/*
	
	Functions for Zad60()

*/

bool IsCorrectTriangle(double a, double b, double c){ return (a + b > c && b + c > a && a + c > b); }
void SideSideSideTriangleArea()
{
	printf("Please enter\n");
	double a = GetDouble("First side: ");
	double b = GetDouble("Second side: ");
	double c = GetDouble("Third side: ");

	if (!IsCorrectTriangle(a, b, c)) {
		printf("Error - triangle with chosen sides doesn't exist\n\n");
		return;
	}

	double s = (a + b + c) / 2.0;
	double field = sqrt(s * (s - a) * (s - b) * (s - c));

	printf("The triangle area is equal to %.3lf\n\n", field);
}

void SideHeightTriangleArea()
{
	printf("Please enter\n");
	double side = GetDouble("Side value: ");
	double height = GetDouble("Height value: ");

	if (side <= 0 || height <= 0) {
		printf("Error - height or side cannot be negative or equal 0\n\n");
		return;
	}

	printf("The triangle area is equal to %.3lf\n\n", side * height / 2);
}


void SideSideAngleTriangleArea()
{
	printf("Please enter\n");
	double side = GetDouble("First side value: ");
	double secondSide = GetDouble("Second side value: ");
	double angle = GetDouble("Angle value: ");

	printf("The triangle area is equal to %.3lf\n\n", side * secondSide * sin(angle * M_PI / 180) / 2);
}

area GetTriangleCommand()
{
	char* text = "Obliczanie pola trojkata\n\n0. Zakoncz program\n1. Bok-Wysokosc\n2. Kat-bokX2\n3. BokX3\n\nYour input: ";
	int input = GetInteger(text);

	switch (input)
	{
		case 0:
			return area_exit;
		case 1:
			return area_sideHeight;
		case 2:
			return area_angleSide2x;
		case 3:
			return area_sidex3;
		default:
			return area_error;
	}
}

bool TriangleCommandCheck(area command)
{
	switch (command)
	{
		case area_sideHeight:
			SideHeightTriangleArea();
			return my_true;

		case area_angleSide2x:
			SideSideAngleTriangleArea();
			return my_true;

		case area_sidex3:
			SideSideSideTriangleArea();
			return my_true;

		case area_error:
			printf("Error - Wrong command\n\n");
			return my_true;
		
		case area_exit:
			return my_false;
	}
}





/*

	Exercise Functions

*/

void Zad55()
{
	printf("Program which takes sequence of positive integer input and prints a min from them.\n");
	printf("Author:% s\n\n", g_author);

	int input = 0;
	unsigned counter = 0;
	unsigned min = UINT_MAX;
	while (my_true) {
		printf("Number no.%d \n", ++counter);
		input = GetInteger("Please enter a positive intager (enter 0 to end proccess): ");

		// initial check (exit)
		if (input == 0) {
			putchar('\n');
			break;
		}

		// check for correct input
		if (input < 0) {
			printf("Error - number is not positive\n");
			continue;												// after continue it doesn't compare with min
		}
		else {
			if (input < min)										// compare with min value
				min = input;
		}
	}

	printf("The minimal number from the sequence is: %u\n\n", min);	// Prints min value
	printf("Koniec Zadania\n\n\n");
}

void Zad56()
{
	printf("Program which takes 10 floating point numbers and prints their art. avarage\n");
	printf("Author: %s\n\n", g_author);
	
	double average = 0.0;

	int counter = 0;
	const int maxRange = 10;
	while (counter < maxRange) {
		printf("Number no.%d \n", ++counter);
		average += GetDouble("Enter a double value: ");
		putchar('\n');
	}
	average /= maxRange;	// takes art. avarage by dividing it by the number count

	printf("The average of 10 floating point numbers is equal to: %lf\n\n", average);
	printf("Koniec Programu\n\n\n");

}

void Zad57()
{
	printf("Program which takes sequence of int numbers and prints their art. and geo. avarage\n");
	printf("Author: %s\n\n", g_author);

	double artAverage = 0.0;
	double geoAverage = 0.0;
	int counter = 0;
	int input = 0;

	while (my_true) {
		input = GetInteger("Please enter a positive integer (Press 0 to exit proccess): ");

		// Exit condition
		if (input == 0)
			break;

		// extra try again condition
		if (input < 0) {
			printf("Error - Number is not positive\n\n");
			continue;
		}

		// give Averages an input
		artAverage += input;
		geoAverage += log(input);

		// itterate the counter
		counter++;
	}
	artAverage = artAverage / counter;
	geoAverage = exp((1.0 / counter)*(geoAverage));

	printf("Geo Average: %lf\n", geoAverage);
	printf("Art Average: %lf\n\n", artAverage);
	printf("Koniec Programu\n\n\n");
}


// To make base change from string to numeric variable I need an access to the least number (most right)
// Problem is that getchar() works from left to right which makes it imposible to do this correctly
// 
// I have done this exercise by filling long long with number representation of charcters 
// and then using it to fill another variable with it but base changed
//
// The way I have took doesn't work correctly (long long cannot hold number with 32 characters)
// I could have done it the correct way if use of char* was allowed
void Zad58()
{
	printf("Program which takes a string of \'0\' and \'1\' as base2 representation and prints the number in base10\n");
	printf("Author:% s\n\n", g_author);
	
	const int maxRange = 32;
	while (my_true) {
		int counter = 0;			//
		bool isCorrect = my_true;	// Conditions

		char base2_char = ' ';		//
		long long base2_num = 0;	//
		long long base10_num = 0;	// Variables

		printf("Base2 char representation: ");
		while (my_true) {
			base2_char = getchar();
			
			if (base2_char == '\n')
				break;

			if (!isBase2Char(base2_char)) {
				isCorrect = !isCorrect;
				break;
			}


			base2_num = (base2_num * 10) + ((long long)base2_char - '0');		// fills base2_longLong var (would have been char*)
			counter++;		
		}

		// condition check
		if (counter <= maxRange && isCorrect)
		{
			printf("Base10 num representation: %lld\n\n", ToBase10(base2_num, 2));
			printf("Koniec Programu\n\n\n");
			return;
		}
		else {
			printf("Error - more than 32 characters or wrong characters\n\n");
			while (getchar() != '\n');		// Buffer cleaning
		}
	}

}

void Zad59()
{
	printf("Program which makes calculations depending on user choice\n");
	printf("Author:% s\n\n", g_author);

	menu command = menu_error;
	int a = 0;
	int b = 0;
	do {
		command = GetCommand();
	} while (CommandCheck(command, &a, &b));

	printf("Koniec Programu\n\n\n");
}

void Zad60()
{
	printf("Program which makes triangle calculations depending on user choice\n");
	printf("Author:% s\n\n", g_author);

	area command = area_error;
	do {
		command = GetTriangleCommand();
	} while (TriangleCommandCheck(command));

	printf("Koniec Programu\n\n\n");
}


void Zad61()
{
	printf("Program which takes time string input (hh:mm) and tells what time it is\n");
	printf("Author:% s\n\n", g_author);

	char c;											//
	while (my_true) {
		int hour = 0;								//
		int minute = 0;								// 
		int counter = 1;							// variables

		printf("Please enter the time string (format hh:mm): ");
		c = getchar();								// initial string and first char inicialization
		while (my_true) {
			if (c == '\n')							// ENTER (exit condition)
				break;

			if (counter == 1 || counter == 2) {		// hours condition
				if (!isalnum(c))
					break;
				else {
					hour = hour * 10 + (c - '0');
				}
			}

			if (counter == 4 || counter == 5) {		// minutes condiotion
				if (!isalnum(c))
					break;
				else {
					minute = minute * 10 + (c - '0');
				}
			}

			if (counter == 3) {						// : condition
				if (c != ':')
					break;
			}

			if (counter > 6)						// Too many characters condition
				break;

			c = getchar();							// Next character from buffer
			counter++;								// counter itteration
		}

		if (counter != 6 || (hour > 23 || hour < 1) || (minute > 59 || minute < 0)) {
			printf("Error - Wrong format or hour and minute values are incorrect\n\n");
			if(c != '\n')								//
				while (getchar() != '\n');				// Clear of the buffer if c wasnt ended by ENTER
		}

		else {
			printf("Oto wczytana godzina:\n%d minut po %d\n\n", minute, hour);
			return;
		}
	}
	printf("Koniec Programu\n\n\n");
}

int main()
{
	// Laboratorium 8
	// Zad 55 - 61
	// Autor: Karol Warda

	Zad55();
	Zad56();
	Zad57();
	Zad58();
	Zad59();
	Zad60();
	Zad61();
}