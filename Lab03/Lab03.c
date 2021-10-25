#include <stdio.h>
#include <math.h>

typedef enum { my_false = 0, my_true = !my_false } bool;

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

		if(isCorrect)
			return num;
	}
}


int main()
{
	printf("Labolatorium nr 3\n");
	printf("Zadania 17-24\n\n");
	printf("Autor: Karol Warda\n\n");
	
	// Zad 17
	//{
	//	printf("Exercise 17\n\n");
	//	printf("Autor: Karol Warda\n");
	//	printf("This program prints an integer number you are going to type.\n\n");

	//	/*printf("The value of input is equal to: %d\n", GetIntNumber());*/ //to test if variable is int type

	//	int num;
	//	printf("Please enter an integer number: ");
	//	scanf_s("%d", &num);
	//	printf("\nThe number value is equal to: %d\n\n", num);
	//	while (getchar() != '\n');	// To clear out the buffer

	//	/*
	//		if scanf_s is set to get only int type variables it will only work properly for that type

	//		So lets say that variable which will get result from scan_f is: int number then:

	//		1. User types int variable - It will work properly
	//		2. User types other type variable (char[], char) - It will print out of range number
	//		(lets say -423562) which isn't what we wanted
	//		3. User types mix of int and other type - same like in 2. it will give out of range number
	//		4. User types floating point type variable - it will print this value rounded to floor
	//		5. User types int number but it's too large - it will print specific number for int type (for windows its -1395630315)

	//	*/

	//	printf("End of the exercise 17\n\n\n");
	//}



	// Zad 18
	//{
	//	printf("Exercise 18\n\n");
	//	printf("Autor: Karol Warda\n");
	//	printf("This program prints float number you are going to type.\n\n");


	//	float f_num = {0.f};
	//	printf("Please write a floating point number: ");
	//	scanf_s("%f", &f_num);
	//	printf("\nThe number is equal to %f\n\n", f_num);
	//	while (getchar() != '\n');	// To clear out the buffer

	//	/*
	//		if scanf_s is set to get only float type variables it will only work properly for that type

	//		So lets say that variable which will get result from scanf_s is: float number then:

	//		1. User types float type number - there are two scenarios:
	//			I. Program will print number properly
	//			II. Program will mess up the precision printing proper number but with wrong floating point
	//		All of this comes down to the set precision

	//		2. User types int type number - then program will print this number in floating point format

	//		3. User types other variable type - then program will print number which was set to the variable before scanf_s
	//			and it will also be stored in the buffer which can lead to the unwanted behavior 
	//			(next scanf_s() or getchar() will print stuff stored in the buffer)
	//	
	//		4. User types float type number but its too large - Same as in the exercise above it will give the number which
	//			isn't what we wanted
	//
	//	*/

	//	printf("End of the exercise 18.\n\n");
	//}


	
	// Zad 19
	//{
	//	printf("Exercise 19\n\n");
	//	printf("Autor: Karol Warda\n");
	//	printf("This program prints two int number you are going to type.\n");
	//	printf("To write a second one please use space in betweeen\n\n");

	//	int number01;
	//	int number02;
	//	printf("Please write two int numbers: ");
	//	scanf_s("%d%d", &number01, &number02);
	//	printf("\nThe numbers are equal to %d and %d\n\n", number01, number02);

	//	while (getchar() != '\n');	// To clear out the buffer

	//	/*
	//		if scanf_s is set to get two int type variables it will only work properly for that type

	//		So lets say that variable which will get result from scanf_s are: int num01, int num02 then:

	//		 1. User types first variable as char or char[] type and second one correctly -
	//			then first and second number print will give random number
	//			because the first given value to scanf_s will give the rest of the first answer to the buffer
	//			which will mess up the second variable

	//		2. User types first variable as floating point type and second one correctly -
	//			then the first number print will be changed to int type and second one will give random number
	//	

	//	*/

	//	printf("End of the exercise 19.\n\n\n");
	//}



	// Zad 20
	/*{
		printf("Exercise 20\n\n");
		printf("Autor: Karol Warda\n");
		printf("This program prints two int numbers which you are going to type\n");
		printf("(Prints values when they are typed correctly)\n\n");

		int number01 = GetIntNumber("Please type first integer: ");
		int number02 = GetIntNumber("Please type the second integer: ");

		printf("Int values:\nFirst: %d\nSecond: %d\n\n", number01, number02);

		printf("End of the exercise 20\n\n\n");
	}*/


	// Zad 21
	{
		printf("Exercise 21\n\n");
		printf("Autor: Karol Warda\n");
		printf("This program prints int number in base10 which you are going to type in base8\n\n");

		int number = GetIntNumber("Please write a number in base8 format: ", "%o");
		printf("The number in base 10 is equal to: %d\n\n", number);	// Program prints garbage value if number is  < 0

		printf("End of The exercise 21\n\n\n");
	}

	// Zad 22
	{
		printf("Exercise 22\n\n");
		printf("Autor: Karol Warda\n");
		printf("This program prints int number in base16 which you are going to type in base10\n\n");

		int number = GetIntNumber("Please write a number in base10 format: ", "%d");
		printf("The number in base 16 is equal to: %x\n\n", number);	// Program prints garbage value if number is  < 0

		printf("End of The exercise 22\n\n\n");
	}

	// Zad 23
	{
		printf("Exercise 23\n\n");
		printf("Autor: Karol Warda\n");
		printf("This program prints int number in base16 which you are going to type in base10\n\n");


		int number = 0;

		while (number <= 0) {
			number = GetIntNumber("Please write a number in base10 format (need to be positive): ", "%d");
			if (number <= 0)
				printf("Error - Number need to be positive\n\n");		// Program prints garbage value if number is  < 0
		}

		//int number = GetIntNumber("Please write a number in base10 format (need to be positive): ", "%d");
		//if (number < 0)
		//	printf("Error - Number need to be positive\n\n");		// Program prints garbage value if number is  < 0
		printf("The number in base 16 is equal to: %x\n\n", number);

		printf("End of the exercise 23\n\n\n");
	}


	// Zad 24
	{
		printf("Exercise 24\n\n");
		printf("Autor: Karol Warda\n");
		printf("This program prints positive int value and tell you if it's positive or negative.\n\n");

		int number = GetIntNumber("Please write a positive int type value: ", "%d");
		if (number < 0)
			printf("Number %d is not positive\n\n", number);
		else
			printf("Number %d is positive\n\n", number);

		printf("End of The exercise 22\n\n\n");
	}
}
