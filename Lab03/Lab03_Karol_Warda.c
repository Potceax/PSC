#include <stdio.h>
#include <math.h>


#define true 1
#define fase 0

typedef enum { my_false = 0, my_true = !my_false } bool;

int GetIntNumber()
{
	int num;
	while (my_true) {
		printf("Please enter a number: ");
		if (!scanf_s("%d", &num) && getchar() != '\n') {
			while (getchar() != '\n');
			continue;
		}
		else
			return num;
	}
}


void* GetInput(char* text, char* format)
{
	void* value;

	while (my_true) {
		bool isCorrect = my_true;

		printf("%s", text);
		if (!scanf_s(format, &value) && getchar() != '\n') {
			isCorrect = !isCorrect;
		}

		while (getchar() != '\n');
		
		if(isCorrect)
			return value;
	}
}

void PrintOutput(char* text, char* format){
	void* value = GetInput(text, format);
	printf("The value of input is equal to : ");
	printf(format, value);
	putchar('\n');
}

int main()
{
	printf("Labolatorium nr 3\n");
	printf("Zadania 17-24\n\n");
	printf("Autor: Karol Warda\n\n");

	// Zad 17

	//printf("Exercise 17\n\n");
	//printf("Autor: Karol Warda\n");
	//printf("This program prints an integer number you are going to type.\n\n");

	PrintOutput("Please write an integer: ", "%d"); //to test if variable is int type
	//// But this VVVV is the answer

	//int num;
	//printf("Please enter an integer number: ");
	//scanf_s("%d", &num);
	//printf("The number value is equal to: %d\n", num);

	//while (getchar() != '\n');	// To clear out the buffer

	///*
	//	if scanf_s is set to get only int type variables it will only work properly for that type

	//	So lets say that variable which will get result from scan_f is: int number then:

	//	1. User types int variable - It will work properly
	//	2. User types other type variable (char[], char) - It will print out of range number
	//	(lets say -423562) which isn't what we wanted
	//	3. User types mix of int and other type - same like in 2. it will give out of range number
	//	4. User types floating point type variable - it will print this value rounded to floor
	//	5. User types int number but it's too large - it will print specific number for int type (for windows its -1395630315)

	//*/

	//printf("End of the exercise 17\n\n");


	// Zad 18

	//printf("Exercise 18\n\n");
	//printf("Autor: Karol Warda\n");
	//printf("This program prints float number you are going to type.\n\n");

	//float f_num = {0.f};
	//printf("Please write a floating point number: ");
	//scanf_s("%f", &f_num);
	//printf("The number is equal to %f\n", f_num);

	//while (getchar() != '\n');	// To clear out the buffer


	///*
	//	if scanf_s is set to get only float type variables it will only work properly for that type

	//	So lets say that variable which will get result from scanf_s is: float number then:

	//	1. User types float type number - there are two scenarios:
	//		I. Program will print number properly
	//		II. Program will mess up the precision printing proper number but with wrong floating point
	//	All of this comes down to the set precision

	//	2. User types int type number - then program will print this number in floating point format

	//	3. User types other variable type - then program will print number which was set to the variable before scanf_s
	//		and it will also be stored in the buffer which can lead to the unwanted behavior 
	//		(next scanf_s() or getchar() will print stuff stored in the buffer)
	//	
	//	4. User types float type number but its too large - Same as in the exercise above it will give the number which
	//		isn't what we wanted
	//
	//*/

	//printf("End of the exercise 18.\n\n");

	
	// Zad 19
	printf("Exercise 19\n\n");
	printf("Autor: Karol Warda\n");
	printf("This program prints two int number you are going to type.\n");
	printf("To write a second one please use space in betweeen\n\n");

	int number01;
	int number02;
	printf("Please write two int numbers: ");
	scanf_s("%d%d", &number01, &number02);
	printf("The numbers are equal to %d and %d\n", number01, number02);

	while (getchar() != '\n');	// To clear out the buffer


	/*
		if scanf_s is set to get two int type variables it will only work properly for that type

		So lets say that variable which will get result from scanf_s are: int num01, int num02 then:

		 1. User types first variable as char or char[] type and second one correctly -
			then first number print will give random number and second also
			because the first given value to scanf_s will give the rest of the first answer to the buffer
			which will mess up the second variable

		2. User types first variable as floating point type and second one correctly -
			then the first number print will be changed to int type and second one will give random number
		

	*/

	printf("End of the exercise 19.\n\n");




}