/*
2.11.2020
By Musa Akyuz
Learn to logic operators
*/
#include <stdio.h>

int main()//main called 
{
	unsigned int low = 5, high = 10;
	
	if(low < high && low < high)
		puts(" 1 AND 1");
		
	if(low > high && low < high)
		puts(" 0 AND 1");
		
	if(low < high && low > high)
		puts(" 1 AND 0");
		
	if(low > high && low > high)
		puts(" 0 AND 0");
		
	if(low < high || low < high)
		puts(" 1 OR 1");
		
	if(low < high || low > high)
		puts(" 1 OR 0");
		
	if(low < high || low > high)
		puts(" 0 OR 1");
		
	if(low > high || low > high)
		puts(" 0 OR 0");
	///////////////////////////////////	
	if(!(low < high && low < high))
		puts(" NOT 1 AND 1");
		
	if(!(low > high && low < high))
		puts(" NOT 0 AND 1");
		
	if(!(low < high && low > high))
		puts(" NOT 1 AND 0");
		
	if(!(low > high && low > high))
		puts(" NOT 0 AND 0");
		
	if(!(low < high || low < high))
		puts(" NOT 1 OR 1");
		
	if(!(low < high || low > high))
		puts(" NOT 1 OR 0");
		
	if(!(low < high || low > high))
		puts(" NOT 0 OR 1");
		
	if(!(low > high || low > high))
		puts(" NOT 0 OR 0");
		
	return 0;
}//end of main
