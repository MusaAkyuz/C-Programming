
//  First Program on C

/*
This program teach us how to works basicly command and some escape directories (\n , \t , \\ , \")

-----  \n  -----   go to a battom line
-----  \t  -----   coursor moves the next tab point
-----  \\  -----   if we want use \ in command, so
-----  \"  -----   if we want use " in command, so
*/

#include <stdio.h>   //  Add input/output Library

int main(void)   //  called main function
{
	printf("Hello C!\n");             //print and puts write(output) on screen 
	printf("------------------\n");   
	puts("Hello C!");
	printf("------------------\n");
	printf("Hello ");
	printf("C!");
	printf("------------------\n");
	printf("Hello C!\t");
	printf("Hello C!\n");
	printf("------------------\n");
	puts("Hello \\ C!");
	printf("------------------\n");
	printf("\"Hello C!\"\n");
	printf("------------------\n");
	printf("H\ne\nl\nl\no\nC\n!\n");
	printf("------------------\n");
	printf("H\te\tl\tl\to\tC\t!\n");
	printf("------------------\n");
	
}   // en of main function
