/*
Musa Akyüz
20.02.2021  11:10AM

Randomly vote for 5 applicant and show us on the line-graphic
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()//main function
{
	int studentNumber = 60, loop = 0, vote;
	int applicant[4] = { /* */ };
	
	srand(time(0));
	
	for(loop; loop<studentNumber; loop++)
	{
		vote = rand() % 5; //randomly give number between 0-5
		switch(vote)  //comparison a number with applicant
		{
			case 0:
				applicant[0]++;
				break;
			
			case 1:
				applicant[1]++;
				break;
			
			case 2:
				applicant[2]++;
				break;
		
			case 3:
				applicant[3]++;
				break;
			
			case 4:
				applicant[4]++;
				break;
		}//end of switch
	}//end of for
	
	loop = 0;
	
	for(loop; loop<5; loop++) //show with line graphic
	{
		printf(" %d applicant votes number is : %d : ", loop+1, applicant[loop]);
		if(applicant[loop]<10)
			printf(" ");
			
		while(applicant[loop]>0)
		{
			printf("-");
			applicant[loop]--;
		}
		puts("");
	}//end of for
	
}//end of main
