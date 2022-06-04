/*
2.11.2020
By Musa Akyuz
Learn to continue
*/
#include <stdio.h>

int main() //main called
{
	unsigned int x;
	
	for(x = 1; x <= 10; ++x)
	{
		if(x == 5)
		{
			continue; //only if x=5, out of the loop and continue
		}
		
		printf(" %d ", x);	
	}
	
	return 0;
}//end of main
