#include <stdio.h>
#include <math.h>
#include <ctype.h> // for isdigit(type) && isalpha(type)
#include <limits.h>
#include <string.h>
#define M_PI 3.14159265359
#define TIME_LENGTH 6
#define DATE_LENGTH 9

const char* g_author = "Karol Warda";

typedef enum {my_false = 0, my_true = !my_false} bool;
typedef enum { side_Height, side2x_angle, side3x, fieldCalc_error }fieldCalcType;
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

typedef struct
{
	double a;
	double b;
	double c;
} Triangle;

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

char GetCharacter(char* text, bool (*condition)(char c))
{
	char c;
	while (my_true) {
		printf("%s", text);
		c = getchar();
		while (getchar() != '\n');		// to clear out the buffer

		if (condition != NULL) {
			if (condition(c))		// checks condition inside a function which was passed by argument
				return c;
			printf("Error - %c is a wrong character\n", c);
		}
		else
			return c;
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

	int counter = 0;
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


	return CreateVector(first, second);
}

bool AreVectorsPerpendicular(Vector first, Vector second){ return (first.a * second.a + first.b * second.b) == 0; }
bool AreVectorsParallel(Vector first, Vector second){ return (first.a * second.b - first.b* second.a) == 0; }
bool AreVectorsZero(Vector first, Vector second) 
{
	return (first.a == 0 && first.b == 0) && (second.a == 0 && second.b == 0);
}

void PrintVectorsPerpendicularOrParallel(Vector first, Vector second)
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





// Checks if sum of two sides are higher then the third one. 
// If any of three sums is incorrect return false
bool isTriangleCorrect(Triangle tr){ return ((tr.a + tr.b > tr.c) && (tr.b + tr.c > tr.a) && (tr.a + tr.c > tr.b)); }

Triangle CreateTriangle()
{
	Triangle tr = {0.0, 0.0, 0.0};
	while (my_true) {
		printf("Please enter\n");
		for (int side = 0; side <= 2; ++side) {
			if (side == 0)
				tr.a = GetDoubleNumber("Side a: ");
			else if (side == 1)
				tr.b = GetDoubleNumber("Side b: ");
			else
				tr.c = GetDoubleNumber("Side c: ");
			putchar('\n');
		}

		if (!isTriangleCorrect(tr))
			printf("Error - Triangle doesn't exist\n\n");
		else
			break;
	}

	return tr;
}

bool FieldCharacterCheck(char c) { return (c == '1' || c == '2' || c == '3'); }
fieldCalcType GetFieldCalcType(char c)
{
	switch (c)
	{
		case '1':
			return side_Height;
		case'2':
			return side2x_angle;
		case '3':
			return side3x;
		default:
			return fieldCalc_error;
	}
}

void SideSideSideTriangleField()
{
	Triangle tr = CreateTriangle();
	double s = (tr.a + tr.b + tr.c) / 2.0;
	double field = sqrt(s * (s - tr.a) * (s - tr.b) * (s - tr.c));
	
	printf("The triangle field is equal to %.3lf\n\n", field);
}

void SideHeightTriangleField()
{
	printf("Please enter\n");
	double side = GetDoubleNumber("Side value: ");
	double height = GetDoubleNumber("Height value: ");

	if (side <= 0 || height <= 0) {
		printf("Error - height or side cannot be negative or equal 0\n\n");
		return;
	}

	printf("The triangle field is equal to %.3lf\n\n", side * height / 2);
}


void SideSideAngleTriangleField()
{
	printf("Please enter\n");
	double side = GetDoubleNumber("First side value: ");
	double secondSide = GetDoubleNumber("Second side value: ");
	double angle = GetDoubleNumber("Angle value: ");

	printf("The triangle field is equal to %.3lf\n\n", side * secondSide * sin(angle * M_PI/180) / 2);
}

int GetMin(int* array, int length)
{
	int min = INT_MAX;

	for (int i = 0; i < length; ++i) {
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

int StringToInt(char* str, int value, int start, int end)
{
	int result = value;			// initial value
	for (int i = start; i <= end; i++) {
		result = (result * 10) + (int)(str[i] - '0');
	}
	return result;
}

char* GetMonthName(int monthNumber)
{
	switch (monthNumber)
	{
		case 1:
			return "Stycznia";
		case 2:
			return "Lutego";
		case 3:
			return "Marca";
		case 4:
			return "Kwietnia";
		case 5:
			return "Maja";
		case 6:
			return "Czerwca";
		case 7:
			return "Lipca";
		case 8:
			return "Sierpienia";
		case 9:
			return "Wrzesienia";
		case 10:
			return "Pazdziernika";
		case 11:
			return "Listopada";
		case 12:
			return "Grudnia";
		default:
			return "Error - Wrong month";
	}
}

void Zad41()
{
	printf("Program which gets 4 points from user, determines 2 vectors\n");
	printf("and tells if they are parallel or perpendicular\n");
	printf("Author:% s\n\n", g_author);

	printf("First Vector\n\n");
	Vector first = GetPointsAndCreateVector();

	printf("Second Vector\n\n");
	Vector second = GetPointsAndCreateVector();

	PrintVectorsPerpendicularOrParallel(first, second);

	printf("Koniec Zadania\n\n\n");


}

void Zad42()
{
	printf("Program which calculate field of the triangle based on user choice\n");
	printf("1. Field calculated by side - height\n");
	printf("2. Field calculated by side - side - angle between\n");
	printf("3. Field calculated by side - side - side\n");
	printf("Author:% s\n\n", g_author);

	printf("Please enter type of calculation (1, 2, 3)\n");
	fieldCalcType type = GetFieldCalcType(GetCharacter("Your choice: ", &FieldCharacterCheck));
	putchar('\n');

	switch (type)
	{
		case side_Height:
			SideHeightTriangleField();
			break;
		case side2x_angle:
			SideSideAngleTriangleField();
			break;
		case side3x:
			SideSideSideTriangleField();
			break;
	}

	printf("Koniec programu\n\n\n");
}

void Zad43()
{
	printf("Program which takes 3 integer inputs from user and determine which one of them is min.\n");
	printf("Author:% s\n\n", g_author);

	const int length = 3;
	int val[3] = { 0, 0, 0 };

	printf("Please enter\n");
	val[0] = GetIntNumber("First value: ", "%d");
	val[1] = GetIntNumber("Second value: ", "%d");
	val[2] = GetIntNumber("Third value: ", "%d");
	putchar('\n');
	

	printf("The minimal value is equal to %d\n\n", GetMin(val, length));
	printf("Koniec Programu\n\n\n");
}

void Zad44()
{
	printf("Program which takes char input and prints its ASCII value\n");
	printf("Author:% s\n\n", g_author);

	char c = GetCharacter("Your character choice: ", NULL);

	printf("The character ASCII value is equal to %d\n\n", (unsigned)(c));

	printf("Koniec Programu\n\n\n");
}

void Zad45()
{
	printf("Program which takes int value prints coresponding ASCII character\n");
	printf("Author:% s\n\n", g_author);

	int input;
	printf("Please enter positive int value\n");
	while (my_true) {
		input = GetIntNumber("Your int value: ", "%d");
		if (input < 0)
			printf("Error - number need to be greater then 0\n\n");
		else
			break;
	}
	putchar('\n');

	if (isdigit(input) || isalpha(input)) {
		printf("Input %d is printable character\n", input);
		printf("The value of it is equal to ASCII character %c\n\n", (char)(input));
	}
	else
		printf("Input %d is control character\n\n", input);

	printf("Koniec Zadania\n\n\n");
}

void Zad46()
{
	printf("Program which takes time string input (hh:mm) and tells what time it is\n");
	printf("Author:% s\n\n", g_author);

	char str[TIME_LENGTH];				// length one more then needed (because of '\0' at the end) 
	printf("Please enter the time string (format hh:mm): ");
	fgets(str, sizeof(str), stdin);		// function which takes input and push it to the string

	// check if format is correct
	if ((!isdigit(str[0]) || !isdigit(str[1])) || str[2] != ':' || (!isdigit(str[3]) || !isdigit(str[4])) || getchar() != '\n') {
		printf("Error - wrong format\n\n");
		while (getchar() != '\n');			// Clears every other useless input
		return;
	}

	// Changning string into int number
	int hour = StringToInt(str, 0, 0, 1);
	int minute = StringToInt(str, 0, 3, 4);
	
	// Check for range conditions
	if ((hour <= 0 || minute <= 0) || (hour > 23 || minute > 59)) {
		printf("Error - time isn't right (out of range)\n\n");
		return;
	}

	printf("Oto wczytana godzina:\n");
	printf("%d minut po %d\n\n", minute, hour);
	
}

void Zad47()
{
	printf("Program which takes date string input (dd.mm.rr) and prints the date (if it is correct)\n");
	printf("Author:% s\n\n", g_author);

	char str[DATE_LENGTH];				// length one more then needed (because of '\0' at the end) 
	printf("Please enter the date string (format dd.mm.rr): ");
	fgets(str, sizeof(str), stdin);


	// Checking initial format conditions
	bool isCorrect = my_true;
	if (str[2] != '.' || str[5] != '.')
		isCorrect = my_false;
	else if (!isdigit(str[0]) || !isdigit(str[1]))
		isCorrect = my_false;
	else if (!isdigit(str[3]) || !isdigit(str[4]))
		isCorrect = my_false;
	else if (!isdigit(str[6]) || !isdigit(str[7]))
		isCorrect = my_false;
	else if (getchar() != '\n')
		isCorrect = my_false;


	if (!isCorrect) {
		printf("Error - wrong format\n\n");
		while (getchar() != '\n');			// Clears every other useless input
		return;
	}

	// Changing string into the int number
	int day = StringToInt(str, 0, 0, 1);
	int month = StringToInt(str, 0, 3, 4);
	int year = StringToInt(str, 20, 6, 7);

	// Initial range conditions
	if (day <= 0 || month <= 0 || year <= 2000) {
		printf("Error - date cannot be less than 01.01.2001\n\n");
		return;
	}
	else if (month > 12 || year > 2050) {
		printf("Error - date cannot be more than 31.12.2050");
		return;
	}

	// Conditions for months other than February
	if (month != 2 && month % 2 == 0 && day > 30) {
		printf("Error - There cannot be more than 30 days in even month\n\n");
		return;
	}
	else if (month != 2 && month % 2 != 0 && day > 31) {
		printf("Error - There cannot be more than 31 days in odd month\n\n");
		return;
	}


	// Conditions for leap/normal year February
	if (year % 4 != 0 && month == 2 && day > 28) {
		printf("Error - There cannot be more then 28 days in normal year February\n\n");
		return;
	}
	else if (year % 4 == 0 && month == 2 && day > 29) {
		printf("Error - There cannot be more then 29 days in leap year February\n\n");
		return;
	}



	printf("Oto wczytana data\n");
	printf("%d ", day); 
	printf("%s ", GetMonthName(month)); 
	printf("%d", year);

}

int main()
{
	//Zad41();
	Zad42();
	Zad43();
	Zad44();
	Zad45();
	Zad46();
	Zad47();

	return 0;
}