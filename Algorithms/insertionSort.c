// Musa Akyüz 
// Algorithm Analysis
// 10.10.2022
// Insertion Sort


#include <stdio.h>

int main()
{
	// inserting sort on this array
	int unsorted[8] = {2,6,9,4,5,9,3,8};
	
	// show starting array
	int counter;
	printf("Unsorted array : ");
	for (counter = 0; counter < (sizeof(unsorted)/sizeof(int)); counter++)
	{
		printf("%d, ", unsorted[counter]);
	}
	
	// creating loop for loop every element on array
	// starting 1. index because 0. index already sorted which we accepted
	int j;
	for (j = 1; j < (sizeof(unsorted)/sizeof(int)); j++)
	{
		// key which we will look and change its place if min aor max situation
		int key = unsorted[j];
		
		// looping back from last index 
		// if key bigger than any others, keep their position
		// if not, key is replacing 1 index back every time
		int i = j - 1;
		while (i >= 0 && key < unsorted[i])
		{
			unsorted[i + 1] = unsorted[i];
			i--;
		}
		// replacing after all 
		unsorted[i + 1] = key;
	}
	
	// reshowing array
	printf("\nSorted array   : ");
	for (counter = 0; counter < (sizeof(unsorted)/sizeof(int)); counter++)
	{
		printf("%d, ", unsorted[counter]);
	}
}
