/*
2.11.2020
By Musa Akyüz
Learn to for loop
*/

#include <stdio.h>

int main()  // main funciton called
{
	unsigned int sum = 0, sum2;
	unsigned int number = 0, number2;
	
	for(number; number <= 100; ++number)   //standart using
	{
		sum += number;
	}
	printf(" %d\n", sum);
	
	//more readable
	for(sum2 = 0, number2 = 0; number2 <= 100; sum2 += number2, number2++){}  //more useful using
	printf(" %d\n", sum2);
	
	return 0;
} //end of main
