#include <stdio.h>
#include <math.h>
#include <string.h>

// Wiekszosc zrobionych zadan pisalem po angielsku, poniewaz jest to dla mnie wygodniejsze
// Jesli nie jest to forma jaka powinienem stosowac to prosze o odpowiedz


int main()
{
	printf("Labolatorium nr 2\n");
	printf("Zadania 8-16\n\n");
	printf("Autor: Karol Warda\n\n");

	// Zad 8

	printf("Exercise 8\n\n");

	printf("Columns:\n\n");
	printf("%10d%10d%10d\t%s\n", -11, 0, 11111, "Without flags");
	printf("%-10d%-10d%-10d\t%s\n", -11, 0, 11111, "With flag \"-\"");
	printf("%+10d%+10d%+10d\t%s\n\n", -11, 0, 11111, "With flag \"+\"");

	printf("Flag \"+\" prints character of the number before it (ex. 10 is printed as +10)\n");
	printf("Flag \"-\" even out printed text to the left side\n\n");

	printf("End of the Exercise 12.\n\n\n");


	// Zad 9
	printf("Exercise 9\n\n");
	
	printf("Columns:\n\n");
	printf("%10d%10d%10d\t%s\n", -11, 0, 11111, "Without flags");
	printf("%010d%010d%010d\t%s\n", -11, 0, 11111, "With flag \"0\"");
	printf("% 10d% 10d% 10d\t%s\n\n", -11, 0, 11111, "With flag \" \"");

	printf("Flag \"0\" fills all the gaps with 0 (works like that for %%d and some of the other formats)\n");
	printf("Flag \" \" gives extra space for negative numbers\n\n");

	printf("End of the Exercise 9.\n\n\n");


	// Zad 10
	printf("Exercise 10:\n\n");

	// I put each of the character in one line until I needed to use special character

	// If all of this was put into one printf it would look like this:
	//printf("%s%s%s%s", "x:\t", "f(x):\n", "3\t", "5\n\n");

	putchar('x'); putchar(':'); putchar('\t'); 
	putchar('f'); putchar('('); putchar('x'); putchar(')'); putchar(':'); putchar('\n');
	putchar('3'); putchar('\t');
	putchar('5'); putchar('\n'); putchar('\n');

	printf("End of the Exercise 10.\n\n\n");
	


	// Zad 11
	printf("Exercise 11\n\n");

	printf("%d\t\t%s\n", -5, "%%d");			// Everything is fine here

	printf("%o\t%s\n", -5, "%o");				// Both of this formats need values which should be unsigned
	printf("%u\t%s\n", -5, "%u");				// If the value is negative program prints garbage value

	printf("%lf\t%s\n", -5/*.f*/, "%lf");		// All of those formats need values which should be floating point
	printf("%le\t%s\n", -5/*.f*/, "%le");		// It can be done by typing .f after the value
	printf("%lg\t%s\n\n", -5/*.f*/, "%lg");		//

	//printf("%s\t%s\n", -5, "%%s");			// Gives an error (-5 should be in " ")
	printf("End of the Exercise 11.\n\n\n");


	// Zad 12
	printf("Exercise 12\n\n");

	//printf("%d\t\t%s\n", -5.0, "%%d");		// %d accept only int values

												// %o and %u accept only unsigned int values
	//printf("%o\t\t%s\n", -5.0, "%o");			// Both of this formats need values which should be unsigned
	//printf("%u\t\t%s\n", -5.0, "%u");			// If the value is negative program prints garbage value

	printf("%lf\t%s\n", -5.0, "%lf");			// All of those functions work fine
	printf("%le\t%s\n", -5.0, "%le");			// 
	printf("%lg\t\t%s\n\n", -5.0, "%lg");		//

	//printf("%s\t%s\n", -5.0, "%%s");			// Gives an error (-5.0 should be in " ")

	printf("End of the Exercise 12.\n\n\n");


	// Zad 13
	printf("Exercise 13\n\n");

	// 1.
	printf("Floating point values (with format %%lg)\n");
	printf("2.0 + 3.0 = %lg\n", 2.0 + 3.0);
	printf("2.0 - 3.0 = %lg\n", 2.0 - 3.0);
	printf("2.0 * 3.0 = %lg\n", 2.0 * 3.0);
	printf("2.0 / 3.0 = %lg\n\n", 2.0 / 3.0);

	// 2.
	printf("Integer values (with format %%d)\n");
	printf("2 + 3 = %d\n", 2 + 3);
	printf("2 - 3 = %d\n", 2 - 3);
	printf("2 * 3 = %d\n", 2 * 3);
	printf("2 / 3 = %d\n\n", 2 / 3);

	// 3.
	printf("Floating point and integer values (with format %%lg)\n");
	printf("2.0 + 3 = %lg\n", 2.0 + 3);
	printf("2.0 - 3 = %lg\n", 2.0 - 3);
	printf("2.0 * 3 = %lg\n", 2.0 * 3);
	printf("2.0 / 3 = %lg\n\n", 2.0 / 3);

	// 4.
	printf("Integer and floating point values (with format %%d)\n");
	printf("2 + 3.0 = %d\n", /*(int)*/(2 + 3.0));			// All of them print wrong answers
	printf("2 - 3.0 = %d\n", /*(int)*/(2 - 3.0));			// That's because format for floating point values should be %f or %g
	printf("2 * 3.0 = %d\n", /*(int)*/(2 * 3.0));			// The (2 + 3.0) changes to the floating point value and cannot be printed as %d
	printf("2 / 3.0 = %d\n\n", /*(int)*/(2 / 3.0));			// To get the correct answer the value requires to be casted to (int)

	printf("End of the Exercise 13.\n\n\n");


	// Zad 14
	printf("Exercise 14\n\n");
	printf("Cale rozwiazanie jest w komentarzu\n\n");

	// Ok - Compiles, Nope - Error

	/*printf("%s\n", "ala");		// Ok - "ala" is a string which is fine for %s format
	printf("%s\n", 'ala');			// Nope - argument is in ' ' which is used for characters only (%c format)
	printf("%s\n", ala);			// Nope - argument is passed without "" or '' so it means nothing 
	printf("%s\n""ala");			// Nope - there is no , between formating which will print garbage and the "ala" will go to the next printf function
	printf("%s\n", "5");			// Ok - "5" is printed as ASCII symbol with %s fromating
	printf("%s\n", '5');			// Nope - although '5' is ok the formating should be %c
	printf("%s\n", 5);*/			// Nope - 5 is written as an integer and formating is for strings

	printf("End of the Exercise 14.\n\n\n");


	// Zad 15
	printf("Exercise 15\n\n");

	printf("Sekwencja specjalna\ntekst za nia.\n");
	/*
		\n - moves next part to the new line
		\t - puts tab in the place of sequence
		\v, \f - changed sequence into random symbol (???)
		\b - cuts character before this sequence
		\r - flipped part after sequence with part before it
		\a - makes a beep sound? (can't really tell)
		\\, \?, \",\' - places \, ?, ", ' in the place of the sequence 		
	*/
	printf("\nEnd of the Exercise 15.\n\n\n");


	// Zad 16
	printf("Exercise 16\n\n");

	printf("%s%s", "Uzywanie sekwencji specjalnych.", "\n\n");

	printf("%s%c", "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\", '\n');
	printf("%s%c", "Czy \"a\" oznacza w C to samo co \'a\'\?", '\n');
	printf("%s%s", "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\", "\n\n");
	putchar('\a');		// To play the sound			

	printf("%s%s", "Koniec.", "\n\n");	
	
	printf("End of the Exercise 16.\n\n\n");

	return 0;
}
