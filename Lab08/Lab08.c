#include <stdio.h>
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

int main()
{
	Zad55();
}