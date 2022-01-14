#include <stdlib.h>
#include <time.h>
#include <stdio.h>

const char* g_author = "Karol Warda";
typedef enum { my_false = 0, my_true = !my_false }bool;

void StartInfo(char* text)
{
	printf(text);
	printf("Author: %s\n\n", g_author);
}
void EndInfo() { printf("Koniec Programu\n\n\n"); }


// Use NULL for the argument "condition" if you dont want extra condition to check
int GetInteger(char* text, bool(*condition)(int n))
{
	int num = 0;
	while (my_true) {
		printf(text);
		
		if (!scanf_s("%d", &num) || (condition != NULL && !condition(num)) || getchar() != '\n') {
			printf("Error - Wrong format or not correct\n\n");
			while (getchar() != '\n');
		}
		else
			return num;
	}
}
bool isPositive(int n) { return n > 0; }
bool isInRangeM(int n) { return n > 0 && n < 100; }		// 100 is defined M value in Zad76()


void FillArrayWithInput(int *tab, int start, int end, bool(*condition)(int n))
{
	for (int index = start; index < end; index++)
		tab[index] = GetInteger("Please enter an integer: ", condition);
}

void PrintArray(int *tab, int start, int end, bool isIncreasing)	// bool is for for loop itteration (+/-)
{
	if (isIncreasing) {										
		for (int index = start; index < end; ++index)				// for the array going through L->R
			printf("%d ", tab[index]);
	}
	else {
		for (int index = start - 1; index >= end; --index)			// for the array going through R->L
			printf("%d ", tab[index]);
	}
	printf("\n\n");
}		


bool IsSumOfCubeElementsEqualToNumber(int number, int *tab, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += tab[i] * tab[i] * tab[i];
	return (sum == number);
}

int FibbonaciSequenceNumber(int n)
{
	if (n == 0 || n == 1)
		return 1;

	return FibbonaciSequenceNumber(n - 1) + FibbonaciSequenceNumber(n - 2);
}


// Bubble type sort algorithm
void SortArray(int *tab, int length)
{
	for (int i = 0; i <  length - 1; i++) {		// Sort for the duration of length - 1
		for (int j = 0; j < length - 1; j++) {	
			if (tab[j + 1] < tab[j]) {			// Switch the current and next element if next < current
				int temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
}


void Zad75()
{
#ifndef N
#define N 10
#endif

	StartInfo("Program which takes 10 Integer inputs and prints them in reverse");

	int tab[N] = { 0 };

	FillArrayWithInput(tab, 0, N, NULL);
	PrintArray(tab, N, 0, my_false);
	EndInfo();
}

void Zad76()
{
#ifndef M
#define M 100
#endif

	StartInfo("Program which prints a sum and multiplication of an array with n length (n cannot be greater than 100)\n");
	int n = GetInteger("Please enter the size of the array: ", &isInRangeM);

	int tab[M] = { 0 };
	FillArrayWithInput(tab, 0, n, &isPositive);

	int sum = 0;
	long long multi = 1;
	for (int i = 0; i < n; i++) {
		sum += tab[i];
		multi *= tab[i];
	}

	printf("The Sum of the elements is equal to: %d\n", sum);
	printf("The multiplication of the elements is equal to: %lld\n\n", multi);
	EndInfo();


}

void Zad77()
{
#ifndef O
#define O 3			// number of all three digit numbers
#endif // !O


	StartInfo("Program which prints all three digit numbers which are the sum of cubes of their numbers\n");

	for (int n = 100; n <= 999; ++n) {
		int tab[O] = { 0 };

		// Fill array with the digits
		int multi = 10;
		int temp = n;
		for (int index = O - 1; index >= 0; --index) {
			tab[index] = temp % multi;
			temp /= 10;	
		}

		if(IsSumOfCubeElementsEqualToNumber(n, tab, O))
			printf("%d ", n);
	}
	printf("\n\n");
	EndInfo();

}

void Zad78()
{
	StartInfo("Program which prints the fibbonaci sequance numbers from n to 0\n");

	int n = GetInteger("Please enter a positive integer: ", &isPositive);
	
	for (int i = n - 1; i >= 0; i--) {
		printf("%d ", FibbonaciSequenceNumber(i));			// Prints numbers from highest to lowest
	}
	printf("\n\n");

	EndInfo();
}

void Zad79()
{
#ifndef P
#define P 10
#endif
	StartInfo("Program which takes 10 integare inputs into array and sorts them out\n");

	int tab[P] = { 0 };
	FillArrayWithInput(tab, 0, P, NULL);
	SortArray(tab, P);
	PrintArray(tab, 0, P, my_true);
	EndInfo();
}

void Zad80()
{
#ifndef R
#define R 10
#endif // !R


	StartInfo("Program which takes 10 random elements and print them sorted from lowest to highest\n");

	srand(time(NULL));							// get the seed for rand()
	int tab[R] = { 0 };

	for (int i = 0; i < R; i++)					// Fill array with random positive integers
		tab[i] = rand();

	SortArray(tab, R);							// Sort Array from the lowest to the highest value
	PrintArray(tab, 0, R, my_true);				// Print array from start to the end (0, R)
	EndInfo();
}

void Zad81()
{
#ifndef S
#define S 10
#endif // !S

	StartInfo("Program which gets 10 random numbers from range [1, 2] and prints them in order from lowest to highest\n");
	srand(time(NULL));
	
	int tab[S] = { 0 };

	for(int i = 0; i < S; ++i)					// fills array with random numbers from range [0, 1] + 1 (so [1, 2])
		tab[i] = rand() % 2 + 1;				

	SortArray(tab, S);
	PrintArray(tab, 0, S, my_true);
	EndInfo();
}

int main()
{
	// Labolatorium 11
	// Zad 75 - 81
	Zad75();
	Zad76();
	Zad77();
	Zad78();
	Zad79();
	Zad80();
	Zad81();

	return 0;
}