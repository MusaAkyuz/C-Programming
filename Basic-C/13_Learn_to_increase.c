/*
2.11.2020
By Musa Akyuz
Learn to increase, decrease, multiplicate, chamber
*/
#include <stdio.h>

int main() // main called
{
	int example;
	
	example = 5;
	printf(" This is example : %d\n", example);
	printf(" Time to example++ : %d\n", example++);
	printf(" After example++ : %d\n", example);
	
	example = 5;
	printf(" This is example : %d\n", example);
	printf(" Time to ++example : %d\n", ++example);
	printf(" After ++example : %d\n", example);
	
	example = 10;
	printf(" This is example : %d\n", example);
	printf(" This is example = example + 5 : %d\n", example = example + 5);
	
	example = 10;
	printf(" This is example : %d\n", example);
	printf(" This is example+=5 : %d\n", example+= 5);
	
	example = 10;
	printf(" This is example : %d\n", example);
	printf(" This is example = example - 5 : %d\n", example = example - 5);
	
	example = 10;
	printf(" This is example : %d\n", example);
	printf(" This is example-=5 : %d\n", example-= 5);
	
	example = 10;
	printf(" This is example : %d\n", example);
	printf(" This is example = example / 5 : %d\n", example = example / 5);
	
	example = 10;
	printf(" This is example : %d\n", example);
	printf(" This is example/=5 : %d\n", example/= 5);
	
	example = 10;
	printf(" This is example : %d\n", example);
	printf(" This is example = example * 5 : %d\n", example = example * 5);
	
	example = 10;
	printf(" This is example : %d\n", example);
	printf(" This is example*= 5 : %d\n", example*= 5);
	
	return 0;
}//main end
