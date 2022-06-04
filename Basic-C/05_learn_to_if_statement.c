 /*
28.10.2020
By Musa Akyüz
learn to while code
*/



#include <stdio.h>

int main (void)  //called main function
{
	int grade = 0;
	
	puts("Enter to Grade : ");
	scanf("%d", &grade);
	
	if (grade <=55)  //min grade requirement is 55
	{
		puts("Your grade is not enough to pass :( ");
	}
	puts("Well Done You passed");
	
	return 0;
	
}  // end of main
