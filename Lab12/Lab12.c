#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defined lengths for exercises
#define L_82 100
#define L_83 100


typedef enum {my_false = 0, my_true = !my_false } bool;
const char* g_author = "Karol Warda";

void StartInfo(char* text)
{
	printf(text);
	printf("Author: %s\n\n", g_author);
}
void EndInfo() { printf("Koniec Programu\n\n\n"); }



// Function which gets integer number if its correct
// put NULL at condition argument if you dont want specified conditions
int GetInteger(char* text, bool(*condition)(int num))
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
bool isInRange_L_82(int num) { return (num > 0 && num <= L_82); }
bool isPositive(int num) { return num > 0; }

void FillArrayWithInput(int* tab, int length, bool(*condition)(int num))
{
	for (int i = 0; i < length; i++)
		tab[i] = GetInteger("Please enter the number: ", condition);
}

void FillArrayWithRandom(int* tab, int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		tab[i] = rand();
}

void PrintArray(int* tab, int start, int end, bool isRising)
{
	if (isRising) {
		for (int i = start; i < end; ++i)
			printf("%d ", tab[i]);
	}
	else {
		for (int i = end - 1; i >= start; --i)
			printf("%d ", tab[i]);
	}
	printf("\n\n");
}

bool areIdentical(int first, int second) { return first == second; }
bool isPairInArray(int* array, int length)
{
	for (int i = 0; i < length - 1; ++i) {
		for (int j = 1; j < length; ++j) {
			if (areIdentical(array[i], array[j])) {
				return my_true;
			}
		}
	}

	return my_false;
}



int GetPolynomialValue(int* values, int length, int x)
{
	int w = values[0];					// first value

	for (int i = 1; i < length; ++i)	// Every itteration the w is multiplied by x making its previous x power + 1 
		w = w * x + values[i];			// after that the new value gets added

	return w;
}



int NWD(int a, int b)
{
	if (a == 0)
		return b;

	if (b > a)
		NWD(b, a);
	else
		NWD(a % b, b);
}


int CNB(int n, int k)	
{								
	int multi = 1;
	int div = 1;
	const int size = n - k;

	for (int i = 1; i <= size; ++i) {
		multi *= k + i;
		div *= i;

		int nwd = NWD(multi, div);
		if (nwd > 1) {
			multi /= nwd;
			div /= nwd;
		}
	}

	return multi / div;
}

int Multi_CNB(size_t n, size_t k)
{
	if (n <= k || k == 1 || n == 1)
		return 1;
	else {
		Multi_CNB(n - 1, k) + Multi_CNB(n - 1, k - 1);
	}
	
	return CNB(n, k);
}


void Zad82()
{
	StartInfo("Program which checks if there is an identical pair in n integer numbers (n is an input)\n");
	int n = GetInteger("Please enter the length (cannot be higher than 100): ", &isInRange_L_82);

	int tab[L_82] = { 0 };

	FillArrayWithRandom(tab, n);

	if (isPairInArray(tab, n))
		printf("Found a pair!");
	else
		printf("There are no identical pairs...");

	printf("\n\n");
	EndInfo();
}


void Zad83()
{
	StartInfo("Program which gets value of n power polynomial for input argument x\n");
	int n = GetInteger("Plese enter positive n value: ", &isPositive);
	int x = GetInteger("Please enter x value: ", NULL);

	int values[L_83] = { 0 };
	printf("Please enter polinomial values\n");
	FillArrayWithInput(values, n + 1, NULL);

	printf("The value of polynomial is equal to %d", GetPolynomialValue(values, n + 1, x));
}

void Zad84()
{
	StartInfo("Program which prints 35 rows of Pascal triangle using binomial coefficient formula\n");

	const int size = 16;

	for (int n = 0; n < size; ++n) {
		for (int k = 0; k < size; ++k) {
			if (k > n)
				break;

			printf("%d ", CNB(n, k));
		}
		putchar('\n');
	}
	printf("\n\n");

	EndInfo();
}

int main()
{
	/*Zad82();
	Zad83();*/
	printf("%d", CNB(29, 14));

}