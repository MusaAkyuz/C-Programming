/*
31.10.2020
By Musa Akyüz
Learn to do-while 
*/

#include <stdio.h>

int main()  //called main function
{
	unsigned int counter = 1;
	
	do  //before do 
	{
		printf(" %d\n", counter);
	}   
	while(++counter <= 10); //after while
	
	return 0;
}//end of main
