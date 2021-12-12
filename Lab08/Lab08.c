#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef enum {my_false = 0, my_true = !my_false }bool;
char* g_author = "Karol Warda";

int GetInteger(char* text)
{
	int result = 0;
	printf(text);
	while (my_true) {

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

void Zad55()
{
	printf("Program which takes sequence of positive integer input and prints a min from them.\n");
	printf("Author:% s\n\n", g_author);

	int input = 0;
	unsigned counter = 1;
	unsigned min = UINT_MAX;
	while (my_true) {
		// prints previous input if it wasnt wrong
		if (!(input <= 0))
			printf("%u.\t%d\t", counter++, input);
		input = GetInteger(("Please enter a positive intager (enter 0 to end proccess): "));

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


			base2_num = (base2_num * 10) + ((long long)base2_char - '0');
			counter++;
		}

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

int main()
{
	//Zad55();
	//Zad56();
	//Zad57();
	Zad58();

}