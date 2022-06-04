/*
8.10.2020
By Musa Akyüz
learn to for code
*/

#include <stdio.h>

int main (void)//main function called
{
	int grade, howManyStudent, howManyExam;  //grade is grade each student //howManyStudent defined what how many studenet enter exam //howManyExam defined what how many make exam this summer
	float averageGrade;
	
	puts(" How many student in class? ");  //take a student number by user
	scanf("%d", &howManyStudent);
	
	puts(" How many exams what do this summer? "); //take a exam number by user
	scanf("%d", &howManyExam);
	
	int count;
	for(count = 1; count <= howManyExam; count++) //take a grade for first exam and other if maked
	{
		int totalGrade = 0, count2; // total grade resetting for other calculation
		for(count2 = 1; count2 <= howManyStudent; count2++)  //take a grade loop
		{
			printf("\n Enter %d. exam %d. student grade : ", count, count2);
			scanf("%d", &grade);
			totalGrade = totalGrade + grade;
		} //end for
		averageGrade = totalGrade / howManyStudent; //average grade 
		printf(" %d. exams average grade is %0.2lf ", count, averageGrade);
	}// end for
	
	return 0;
}//end main
