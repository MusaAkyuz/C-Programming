#include <stdio.h>
#include <limits.h>


int main() 
{
	int array[10] = {12,10,6,7,8,9,2,4,5,56};
	
	int i;
	for(i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	
	MERGESORT(array, 0, 9);
	printf("\n");
	
	for(i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
}

void MERGE(int A[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int left[n1];
	int right[n2];
	
	int i;
	for(i = 0; i < n1; i++)
	{
		left[i] = A[l + i];
	}
	
	int j;
	for(j = 0; j < n1; j++)
	{
		right[j] = A[m + j + 1];
	}
	
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	
	i = 0;
	j = 0;
	int k;
	for(k = l; k <= r; k++)
	{
		if(left[i] <= right[j])
		{
			A[k] = left[i];
			i++;
		}
		else
		{
			A[k] = right[j];
			j++;
		}
	}	
}

void MERGESORT(int A[], int l, int r)
{
	if(l < r)
	{
		int m = (l + r)/2;
		MERGESORT(A, l ,m);
		MERGESORT(A, m+1, r);
		MERGE(A, l, m, r);
	}
	
	
	
	
	
	
	
}
