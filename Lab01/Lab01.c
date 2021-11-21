#include <stdio.h>
#include <math.h>

const char* g_author = "Karol Warda";		// Your Name

int cube(int base) { return base * base * base; }

int main()
{
	printf("Labolatorium nr 1\n");
	printf("Zadania 1-7\n\n");
	printf("Autor: %s\n\n", g_author);

	// Zad 1

	printf("Zadanie 1\n");

	printf("Oto szesciany wybranych liczb:\n\n");
	printf("k\t\tk*k*k\n\n");
	printf("%d\t\t%d\n", 21, cube(21));
	printf("%d\t\t%d\n", 32, cube(32));
	printf("%d\t\t%d\n\n\n", -53, cube(-53));

	printf("Koniec programu.\n\n");


	// Zad 2

	printf("Zadanie 2\n");

	printf("Oto szesciany wybranych liczb:\n\n");
	printf("%3s%20s\n\n", "k", "k*k*k");
	printf("%3d%20d\n", 21, cube(21));
	printf("%3d%20d\n", 32, cube(32));
	printf("%3d%20d\n\n\n", -53, cube(-53));

	printf("Koniec Programu.\n\n");


	// Zad 3

	printf("Zadanie 3\n");

	printf("Oto szesciany wybranych liczb:\n\n");
	printf("%s%15s%s\n\n", "k", "k*k*k ", "(systemie osemkowy)");
	printf("%d%20o\n", 2, cube(2));
	printf("%d%20o\n", 3, cube(3));
	printf("%d%20o\n\n\n", 5, cube(5));

	printf("Koniec Programu.\n\n");


	// Zad 4

	printf("Zadanie 4\n");

	printf("Oto pierwiastki kwadratowe wybranych liczb:\n\n");
	printf("%2s%20s\n\n", "k", "sqrt(k)");
	printf("%d%20f\n", 21, sqrt(21.0));
	printf("%d%20f\n", 32, sqrt(32.0));
	printf("%d%20f\n\n\n", 53, sqrt(53.0));

	printf("Koniec Programu.\n\n");


	// Zad 5
	// Precyzja jest ustawiona do 18 miejsc po przecinku (miejsca po przecinku od 16 do 18 nie sa wyzerowane)

	printf("Zadanie 5\n");

	printf("Oto pierwiastki kwadratowe wybranych liczb:\n\n");
	printf("%2s%23s\n\n", "k", "sqrt(k)");
	printf("%d%23.18lf\n", 21, sqrt(21.0));
	printf("%d%23.18lf\n", 32, sqrt(32.0));
	printf("%d%23.18lf\n\n\n", 53, sqrt(53.0));

	printf("Koniec Programu.\n\n");


	// Zad 6

	printf("Zadanie 6\n");

	printf("Oto pierwiastki kwadratowe wybranych liczb:\n\n");
	printf("%5s%20s\n\n", "k", "sqrt(k)");
	printf("%5d%20le\n", 21, sqrt(21.0));
	printf("%5d%20le\n", 132, sqrt(132.0));
	printf("%5d%20le\n\n\n", 11153, sqrt(11153.0));

	printf("Koniec programu\n\n");


	// Zad 7

	printf("Zadanie 7\n");

	printf("Wybrane liczby i ich pierwiastki kwadratowe sformatowane za pomoca %%lg:\n\n");
	printf("%12s%20s\n\n", "k", "sqrt(k)");
	printf("%12lg%20lg\n", 0.000000001, sqrt(0.000000001));
	printf("%12lg%20lg\n", 0.000000001, sqrt(0.000000001));
	printf("%12lg%20lg\n", 9876543210123.f, sqrt(9876543210123.f));
	printf("%12lg%20lg\n\n\n", 987654321012.f, sqrt(987654321012.f));

	printf("Koniec Programu\n\n");
	

	return 0;
}
