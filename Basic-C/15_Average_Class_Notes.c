/*
Musa Akyüz
20.02.2021  10:13AM

Calculate average mark for student and calculate average mark that under the general average
*/

#include<stdio.h> // input/output library added

int main()//main function
{
	int studentNumber = 5, loop = 1, referance = 0;
	float average, totalMark = 0, averageForLowMark, totalMarkForLowMark = 0;
	int students[4];
	
	for(loop; loop<=studentNumber; loop++)  //Student marks request from the user and send to array
	{
		printf("How many point did %d.student score? : ", loop);
		scanf("%d", &students[loop-1]);
		totalMark = totalMark + students[loop-1];
	}//end of for
	
	average = totalMark / studentNumber;  //general average
	printf("Total Average is %3.2f \n", average);
	
	loop = 1;
	for(loop; loop<=studentNumber; loop++)
	{
		if(students[loop-1] < average)
		{
			totalMarkForLowMark = totalMarkForLowMark + students[loop-1];
			referance++;
		}
	}//end of for
	
	averageForLowMark = totalMarkForLowMark / referance;  //average for low marks
	printf("Total Average for Low Marks is %3.2f \n", averageForLowMark);
}//end of main
