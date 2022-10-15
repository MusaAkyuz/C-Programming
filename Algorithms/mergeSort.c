#include <stdio.h>
#include <limits.h>


int main() 
{
	int array[10] = {10,5,6,7,34,23,67,2,3,12};

	int a;
	
	for(a = 0; a < sizeof(array)/sizeof(int); a++)
	{
		printf("%d ", array[a]);
	}
	
	mergeSort(array, 0, 9);
	
	printf("\n");
	for(a = 0; a < sizeof(array)/sizeof(int); a++)
	{
		printf("%d ", array[a]);
	}
}

void mergeDivide(int arr[], int l, int m, int r) 
{
	//printf("\nMergeDivide");	
	// finding length of subarrays
	int leftArrayLen = m - l + 1;
	int rightArrayLen = r - m;
	//printf("\nLeft Array Len : %d    Right Array Len : %d", leftArrayLen, rightArrayLen);
	// Creating temp arrays for every divide
	int left[leftArrayLen + 1];
	int right[rightArrayLen + 1];
	
	// Copying from arr[]
	int i;
	for(i = 0; i < leftArrayLen; i++) 
	{
		left[i] = arr[l + i];
		//printf("\nleft[%d] : %d", i, left[i]);
	}
	printf("\n Left array : ");
	int index=0;
	for (index = 0; index < leftArrayLen; index++){
		printf("%d ", left[index]);
	}
	
	int j;
	for(j = 0; j < rightArrayLen; j++) 
	{
		right[j] = arr[m + j + 1];
		//printf("\nright[%d] : %d", j, right[j]);
	}
	printf("\n Right array : ");
	index=0;
	for (index = 0; index < rightArrayLen; index++){
		printf("%d ", right[index]);
	}
	
	// adding last to infinity
	left[leftArrayLen + 1] = INT_MAX;
	right[rightArrayLen + 1] = INT_MAX;
	
	i = 0;
	j = 0;
	int k = l;
//	for(k = l; k < r; k++) 
//	{
//		if (left[i] <= right[i])
//		{
//			arr[k] = left[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = right[j];
//			j++;
//		}
//	}

    while (i < leftArrayLen && j < rightArrayLen) {
    	if (left[i] <= right[j]){
    		arr[k] = left[i];
            i += 1;
		}
        else
        {
        	arr[k] = right[j];
            j += 1;
		}
        k += 1;
	}
        

    while (i < leftArrayLen)
    {
        arr[k] = left[i];
        i += 1;
        k += 1;
	}
 

    while (j < rightArrayLen)
    {
    	arr[k] = right[j];
        j += 1;
        k += 1;
	}
        
			
	printf("\n Array : ");
	index=0;
	for (index = 0; index < sizeof(arr)/sizeof(arr[0]); index++){
		printf("%d ", arr[index]);
	}
}

void mergeSort(int arr[], int l, int r) 
{
	//printf("\nl : %d   r : %d");
	if (l < r)
	{
		int m = (l+r-1)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		mergeDivide(arr, l, m, r);
	}
}