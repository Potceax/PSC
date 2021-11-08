#include <stdio.h>
#include <math.h>

typedef enum { my_false = 0, my_true = !my_false } bool;

typedef enum  {is_in, is_equal, is_out} circle_enum;
typedef enum {I_quarter, II_quarter, III_quarter, IV_quarter, origin_quarter } quarter_enum;
typedef enum {x_axis, y_axis, xy_axis} axis_enum;

typedef struct 
{
	int x;
	int y;

}Point;

char ToSmaller(char c) 
{
	if (c <= 'Z' && c >= 'A')
		return (c + (abs('a' - 'A')));
	else
		return c;
}

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

int DistanceFromTheCircle(Point point)
{
	return(pow(point.x, 2) + pow(point.y, 2));
}

circle_enum IsInTheCircle(Point point, int radious)
{
	int distance = DistanceFromTheCircle(point);

	if (distance < radious)
		return is_in;

	if (distance == radious)
		return is_equal;

	if (distance > radious)
		return is_out;
}


/*
	x > 0, y > 0 I
	x < 0, y > 0 II
	x < 0, y < 0 III
	x > 0, y < 0 IV
*/

quarter_enum GetPointQuarter(Point point)
{

	// Made to nullify any wrong result for 0,0 points
	if (point.x == 0 && point.y == 0)
		return origin_quarter;

	if (point.x >= 0 && point.y >= 0)
		return I_quarter;

	if (point.x <= 0 && point.y >= 0)
		return II_quarter;

	if (point.x <= 0 && point.y <= 0)
		return III_quarter;

	if (point.x >= 0 && point.y <= 0)
		return IV_quarter;
}

void PrintPointQuarter(Point point)
{
	quarter_enum quarter = GetPointQuarter(point);

	switch (quarter) {
	case origin_quarter:
		printf("Point (%d,% d) belong to the origin quarter\n", point.x, point.y);
	case I_quarter:
		printf("Point (%d,% d) belong to the I quarter\n", point.x, point.y);
		break;
	case II_quarter:
		printf("Point (%d,% d) belong to the II quarter\n", point.x, point.y);
		break;
	case III_quarter:
		printf("Point (%d,% d) belong to the III quarter\n", point.x, point.y);
		break;
	case IV_quarter:
		printf("Point (%d,% d) belong to the IV quarter\n", point.x, point.y);
		break;
	}
}

axis_enum GetPointAxis(const Point point)
{
	if (point.x == 0 && point.y == 0)
		return xy_axis;
	if (point.x == 0 && point.y != 0)
		return x_axis;
	if (point.x != 0 && point.y == 0)
		return y_axis;
}

void PrintPointAxis(Point point)
{
	axis_enum axis = GetPointAxis(point);

	switch (axis) {
	case x_axis:
		printf("Point (%d,% d) belong to the x axis\n\n", point.x, point.y);
		break;
	case y_axis:
		printf("Point (%d,% d) belong to the y axis\n\n", point.x, point.y);
		break;
	case xy_axis:
		printf("Point (%d,% d) belong to the x and y axis\n\n", point.x, point.y);
		break;
	}
}

void PrintPointQuarterAndAxis(Point point)
{
	PrintPointQuarter(point);
	PrintPointAxis(point);
}

void Zad25(char c)
{
	// Checks if c is a letter
	if ((c < 'a' && c > 'z') || (c < 'A' && c > 'Z'))
		return;
	
	c = ToSmaller(c);

	printf("Program which requiers input and tells if the imput is = %c\n", c);
	printf("Autor: Karol Warda\n\n");

	printf("Please enter an character: ");
	char input = getchar();
	while (getchar() != '\n');
	
	input = ToSmaller(input);

	if (input == c)
		printf("Input is equal to %c\n\n", c);
	else
		printf("Input is not equal to %c\n\n", c);

	printf("Koniec Programu\n\n\n");
}

void Zad26(const Point initPoint, const int radious)
{
	printf("Program which tells user if point he wrote belongs to the point (%d,% d) and radious %d.\n",
		initPoint.x, initPoint.y, radious);
	printf("Autor: Karol Warda\n\n");

	Point input;

	printf("Please enter\n");
	input.x = GetIntNumber("Point x value: ", "%d");
	input.y = GetIntNumber("Point y value: ", "%d");

	circle_enum result = IsInTheCircle(input, 1);

	if (result == is_in || result == is_equal)
		printf("Point (%d,% d) belong to the circle\n\n", input.x, input.y);
	else
		printf("Point (%d,% d) does not belong to the circle\n\n", input.x, input.y);

	printf("Koniec Programu\n\n\n");
}

void Zad27(const Point initPoint, const int radious)
{
	printf("Program which tells user if point he wrote belongs to the point (%d,% d) and radious %d.\n",
		initPoint.x, initPoint.y, radious);
	printf("Autor: Karol Warda\n\n");

	Point input;

	printf("Please enter\n");
	input.x = GetIntNumber("Point x value: ", "%d");
	input.y = GetIntNumber("Point y value: ", "%d");

	circle_enum result = IsInTheCircle(input, 1);

	switch (result) {
	case is_in:
		printf("Point (%d,% d) is in the circle\n\n", input.x, input.y);
		break;
	case is_equal:
		printf("Point(%d,% d) is on the circle\n\n", input.x, input.y);
		break;
	case is_out:
		printf("Point(%d,% d) does not belong to the circle\n\n", input.x, input.y);
		break;
	}

	printf("Koniec Programu\n\n\n");
}

void Zad28()
{
	printf("Program which tells user in what quarter his imput point belongs\n");
	printf("Autor: Karol Warda\n\n");

	Point input;

	printf("Please enter\n");
	input.x = GetIntNumber("Point x value: ", "%d");
	input.y = GetIntNumber("Point y value: ", "%d");

	PrintPointQuarter(input);

	printf("Koniec Programu\n\n\n");
}

void Zad29()
{
	printf("Program which tells user in what quarter and axis his imput point belongs\n");
	printf("Autor: Karol Warda\n\n");

	Point input;

	printf("Please enter\n");
	input.x = GetIntNumber("Point x value: ", "%d");
	input.y = GetIntNumber("Point y value: ", "%d");

	PrintPointQuarterAndAxis(input);

	printf("Koniec Programu\n\n\n");
}

void Zad30()
{

}

int main()
{
	/*Zad25('c');*/

	const Point initPoint = { 0,0 };
	const int initRad = 1;
	/*Zad26(initPoint, initRad);
	Zad27(initPoint, initRad);*/
	Zad28();
	Zad29();
	
}