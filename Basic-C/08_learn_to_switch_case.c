/*
2.11.2020
By Musa Akyüz
Learn to switch case 
*/
#include <stdio.h>

int main(void)  //main function called
{
	unsigned int day;
	
	puts(" Enter a number 1 to 7");
	scanf("%d", &day);
	
	switch(day)
	{
		case 1:
			puts(" Monday");
			break;
		case 2:
			puts(" Tuesday");
			break;
		case 3:
			puts(" Wednesday");
			break;
		case 4:
			puts(" Thursday");
			break;
		case 5:
			puts(" Friday");
			break;
		case 6:
			puts(" After Friday :) ");
			break;
		case 7:
			puts(" Sunday");
			break;
		default:                              //if user enter a number but not 1-7
			puts(" Incorrect Number");
			break;
	}
	return 0;
} // end of main
