#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

typedef enum { my_false = 0, my_true = !my_false } bool;

typedef enum  {is_in, is_equal, is_out} circle_enum;
typedef enum {I_quarter, II_quarter, III_quarter, IV_quarter, origin_quarter } quarter_enum;
typedef enum {x_axis, y_axis, xy_axis, none_axis} axis_enum;
typedef enum {is_higher, is_lower, is_func, is_notFunc } func_deter_enum;	// enum for function - point values

typedef struct 
{
	double x;
	double y;

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

Point GetPoint()
{
	Point p;

	printf("Please enter\n");
	p.x = GetDoubleNumber("Point x value: ");
	p.y = GetDoubleNumber("Point y value: ");

	return p;
}

double DistanceFromTheCircle(Point initPoint, Point point)
{
	return(sqrt(pow((point.x - initPoint.x), 2) + pow((point.y - initPoint.y), 2)));
}

circle_enum IsInTheCircle(Point initPoint, Point point, double radious)
{
	double distance = DistanceFromTheCircle(initPoint, point);

	if (distance < radious)
		return is_in;

	if (distance == radious)
		return is_equal;

	if (distance > radious)
		return is_out;
}

void PrintPointCircle(Point initPoint, Point point, double radious)
{
	circle_enum result = IsInTheCircle(initPoint, point, 1.0);

	switch (result) {
		case is_in:
			printf("Point (%.2f,% .2f) is in the circle\n\n", point.x, point.y);
			break;
		case is_equal:
			printf("Point(%.2f,% .2f) is on the circle\n\n", point.x, point.y);
			break;
		case is_out:
			printf("Point(%.2f,% .2f) does not belong to the circle\n\n", point.x, point.y);
			break;
	}
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
	else if ((point.x == 0 && point.y != 0) || (point.x != 0 && point.y == 0))
		return origin_quarter;

	if (point.x > 0 && point.y > 0)
		return I_quarter;

	if (point.x < 0 && point.y > 0)
		return II_quarter;

	if (point.x < 0 && point.y < 0)
		return III_quarter;

	if (point.x > 0 && point.y < 0)
		return IV_quarter;
}

void PrintPointQuarter(Point point)
{
	quarter_enum quarter = GetPointQuarter(point);

	switch (quarter) {
	case origin_quarter:
		printf("Point (%.2f,% .2f) belong to the origin quarter\n", point.x, point.y);
		break;
	case I_quarter:
		printf("Point (%.2f,% .2f) belong to the I quarter\n", point.x, point.y);
		break;
	case II_quarter:
		printf("Point (%.2f,% .2f) belong to the II quarter\n", point.x, point.y);
		break;
	case III_quarter:
		printf("Point (%.2f,% .2f) belong to the III quarter\n", point.x, point.y);
		break;
	case IV_quarter:
		printf("Point (%.2f,% .2f) belong to the IV quarter\n", point.x, point.y);
		break;
	}
}

axis_enum GetPointAxis(const Point point)
{
	if (point.x != 0 && point.y != 0)
		return none_axis;
	if (point.x == 0 && point.y == 0)
		return xy_axis;
	if (point.x == 0 && point.y != 0)
		return y_axis;
	if (point.x != 0 && point.y == 0)
		return x_axis;
}

void PrintPointAxis(Point point)
{
	axis_enum axis = GetPointAxis(point);

	switch (axis) {
	case none_axis:
		printf("Point (%.2f,% .2f) does not belong to any axis\n\n", point.x, point.y);
		break;
	case x_axis:
		printf("Point (%.2f,% .2f) belong to the x axis\n\n", point.x, point.y);
		break;
	case y_axis:
		printf("Point (%.2f,% .2f) belong to the y axis\n\n", point.x, point.y);
		break;
	case xy_axis:
		printf("Point (%.2f,% .2f) belong to the x and y axis\n\n", point.x, point.y);
		break;
	}
}

void PrintPointQuarterAndAxis(Point point)
{
	PrintPointQuarter(point);
	PrintPointAxis(point);
}

double f(double x)
{
	return sqrt(fabs(acos(x) + (exp(x) / log(x))));
}


// Determine criteria for the point argument in regards to f(point.x)
func_deter_enum GetFunctionDetermination(Point point)
{
	if (point.x <= 0 || point.x >= 1)	// case where x doesn't belong to field of f(x)
		return is_notFunc;

	Point function = { point.x, f(point.x) };
	if (point.y == function.y)
		return is_func;
	if (point.y > function.y)
		return is_higher;
	if (point.y < function.y)
		return is_lower;
}

// Prints in what criteria does the point argument fall under
void PrintFunctionDetermination(Point point)
{
	func_deter_enum fc_deter = GetFunctionDetermination(point);

	switch (fc_deter){
	case is_notFunc:
		printf("X value of point (%.2f,% .2f) doesn't belong to the function field\n\n", point.x, point.y);
		break;
	case is_func:
		printf("Point (%.2f,% .2f) is the point of function\n\n", point.x, point.y);
		break;
	case is_higher:
		printf("Point (%.2f,% .2f) is higher than function\n\n", point.x, point.y);
		break;
	case is_lower:
		printf("Point (%.2f,% .2f) is lower than function\n\n", point.x, point.y);
		break;
	}
}



void Zad25(char c)
{
	// Checks if c is a letter
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return;
	
	c = ToSmaller(c);

	printf("Program which requiers input and tells if the imput is = %c\n", c);
	printf("Autor: Karol Warda\n\n");

	printf("Please enter an character: ");
	char input = getchar();
	while (getchar() != '\n');
	
	//input = ToSmaller(input);		// When program requiers only small case letters

	if (input == c)
		printf("Input is equal to %c\n\n", c);
	else
		printf("Input is not equal to %c\n\n", c);

	printf("Koniec Programu\n\n\n");
}

void Zad26(const Point initPoint, const double radious)
{
	printf("Program which tells user if the point he wrote belongs to the circle with center point (%.2f,% .2f) and radious %.2f.\n",
		initPoint.x, initPoint.y, radious);
	printf("Autor: Karol Warda\n\n");

	Point input = GetPoint();

	circle_enum result = IsInTheCircle(initPoint, input, radious);

	if (result == is_in || result == is_equal)
		printf("Point (%.2f,% .2f) belong to the circle\n\n", input.x, input.y);
	else
		printf("Point (%.2f,% .2f) does not belong to the circle\n\n", input.x, input.y);

	printf("Koniec Programu\n\n\n");
}

void Zad27(const Point initPoint, double radious)
{
	printf("Program which tells user if the point he wrote belongs to the circle with center point (%.2f,% .2f) and radious %.2f.\n",
		initPoint.x, initPoint.y, radious);
	printf("Autor: Karol Warda\n\n");

	Point input = GetPoint();
	PrintPointCircle(initPoint, input, radious);

	printf("Koniec Programu\n\n\n");
}

void Zad28()
{
	printf("Program which tells user in what quarter his imput point belongs\n");
	printf("Autor: Karol Warda\n\n");

	Point input = GetPoint();
	PrintPointQuarter(input);

	printf("Koniec Programu\n\n\n");
}

void Zad29()
{
	printf("Program which tells user in what quarter and axis his imput point belongs\n");
	printf("Autor: Karol Warda\n\n");

	Point input = GetPoint();
	PrintPointQuarterAndAxis(input);

	printf("Koniec Programu\n\n\n");
}

void Zad30()
{
	printf("Program which gets float input:\n");
	printf("If it is an integer, it will tell about it to user.\n");
	printf("If not the number will be rounded to lower closest integer\n\n");
	printf("Autor: Karol Warda\n\n\n");

	double num = GetDoubleNumber("Please enter a number: ");

	num = roundf(num * 100) / 100;	// rounds input to 2 decimals

	if (num == floor(num))
		printf("The number %.2f is an integer\n\n", num);
	else
		printf("The number %.2f wasn't an integer. The rounded value is equal to %.2f\n\n", num, floor(num));

	printf("Koniec Programu\n\n\n");
}

void Zad31()
{
	printf("Program which gets point input from user and determine certain criteria about f(x):\n");
	printf("f(x) = sqrt(abs(arccos(x) + (exp(x)/ln(x)))\n\n");
	printf("Autor: Karol Warda\n\n\n");

	Point input = GetPoint();	
	PrintFunctionDetermination(input);

	printf("Koniec Programu\n\n\n");
}

void Zad32()
{
	printf("Autor: Karol Warda\n\n");

	int x;
	printf("Testowanie instr. przypisania.\n\n");
	x = 3;
	printf("Po x=3; wart. x jest: %d\n", x);
	x = 5;
	printf("Po x=5; wart. x jest: %d\n", x);
	x += 2;
	printf("Po x=x+2; wart. x jest: %d\n", x);
	x *= (x + 1);
	printf("Po x=x*(x+1); wart. x jest: %d\n", x);
	x += 1;
	printf("Po x=x+1; wart. x jest: %d\n", x);
	x -= (3 / 4);
	printf("Po x=x-(3/4); wart. x jest: %d\n", x);
	x /= (x + 1);
	printf("Po x=x/(x+1); wart. x jest: %d\n", x);
	x -= 1;
	printf("Po x--; wart. x jest: %d\n", x);
	printf("\n\nKoniec programu. \n\n\n");
}

void Zad33()
{
	printf("Program which loads values to the array and looks how many of them are equal\n");
	printf("Autor: Karol Warda\n\n");

	int x = { 0 };
	int y[5];

	//y[0] = (x++) + 7; 
	y[0] = x + 7;
	x += 1;				/*1*/

	//y[1] = (++x) + 7; 
	x += 1;
	y[1] = x + 7;		/*2*/

	//y[2] = 7 + (x++); 
	y[2] = 7 + x;
	x += 1;				/*3*/

	//y[3] = 7 + (++x);
	x += 1;
	y[3] = 7 + x;		/*4*/

	//y[4] = 7 + (x + 1); 
	y[4] = 7 + (x + 1);	/*5*/


	int length = { 5 };
	int equal = { 0 };
	for (int i = 0; i < length - 1; i++) {
		int current = y[i];
		for (int j = i + 1; j < length; j++) {
			int next = y[j];
			if (current == next)
				++equal;
		}
	}
	printf("There are %d pairs.\n\n", equal);

	printf("Koniec Programu\n\n\n");
}

int main()
{
	Zad25('T');

	const Point initPoint = { 0.0, 0.0 };
	const double initRad = 1.0;
	Zad26(initPoint, initRad);
	Zad27(initPoint, initRad);

	Zad28();
	Zad29();
	Zad30();
	Zad31();
	Zad32();
	Zad33();
	
	return 0;
}