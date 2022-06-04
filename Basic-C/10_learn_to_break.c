/*
2.11.2020
By Musa Akyuz
Learn to break
*/
#include <stdio.h>

int main()  //main called 
{
	unsigned int x;
	
	for(x = 1; x <= 10; ++x)
	{
		if(x == 5)
		{
			break;   //completely out of the loop if x = 5
		}
		
		printf(" %d ", x);	
	}
	
	return 0;
}//end of main
