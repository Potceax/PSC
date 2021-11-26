#include <stdio.h>
#include <math.h>
#include <ctype.h> // for isdigit(type) && isalpha(type)

const char* g_author = "Karol Warda";

typedef enum {my_false = 0, my_true = !my_false} bool;
typedef struct
{
	double x;
	double y;
}Point;

typedef struct
{
	double a;
	double b;

} Vector;

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

Vector CreateVector(Point start, Point end)
{
	Vector result = {end.x - start.x, end.y - start.y };
	return result;
}

Point CreatePoint(double x, double y)
{
	Point result = { x, y };
	return result;
}

Vector GetPointsAndCreateVector()
{	
	Point first = {0,0};
	Point second = {0,0};

	static int counter = 0;
	while (counter <= 1) {
		printf("Please enter ");
		(counter == 0) ? printf("start point\n") : printf("end Point\n");	// Different message for both points
		double x = GetDoubleNumber("Point x value: ");
		double y = GetDoubleNumber("Point y value: ");
		putchar('\n');
		if (counter == 0)
			first = CreatePoint(x, y);
		else
			second = CreatePoint(x, y);
		counter++;
	}
	counter = 0;

	return CreateVector(first, second);
}

bool AreVectorsPerpendicular(Vector first, Vector second){ return (first.a * second.a + first.b * second.b) == 0; }
bool AreVectorsParallel(Vector first, Vector second){ return (first.a * second.b - first.b* second.a) == 0; }
bool AreVectorsZero(Vector first, Vector second) 
{
	return (first.a == 0 && first.b == 0) && (second.a == 0 && second.b == 0);
}

void PrintPerpendicularOrParallel(Vector first, Vector second)
{

	// First it checks if they are Perpendicular, parallel or non of them
	if (AreVectorsParallel(first, second))
		printf("Vectors a = [%.lf,% .lf] and b = [%.lf,% .lf] are Parallel.\n\n",
			first.a, first.b, second.a, second.b);
	else if(AreVectorsPerpendicular(first, second))
		printf("Vectors a = [%.lf,% .lf] and b = [%.lf,% .lf] are Perpendicular.\n\n",
			first.a, first.b, second.a, second.b);
	else
		printf("Vectors a = [%.lf,% .lf] and b = [%.lf,% .lf] are not parallel or Perpendicular.\n\n",
			first.a, first.b, second.a, second.b);

	// And then it check if the vectors are vectors zero
	if(AreVectorsZero(first, second))
		printf("Vectors a = [%.lf,% .lf] and b = [%.lf,% .lf] are Vectors zero.\n\n",
			first.a, first.b, second.a, second.b);
}


void Zad40()
{
	printf("Program which gets 4 points from user, determines 2 vectors\n");
	printf("and tells if they are parallel or perpendicular\n");
	printf("Author:% s\n\n", g_author);

	printf("First Vector\n\n");
	Vector first = GetPointsAndCreateVector();

	printf("Second Vector\n\n");
	Vector second = GetPointsAndCreateVector();

	PrintPerpendicularOrParallel(first, second);

	printf("Koniec Zadania\n\n");


}

int main()
{
	Zad40();
}