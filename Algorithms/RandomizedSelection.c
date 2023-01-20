#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 100


int PARTITION(int A[], int p, int r);
int RANDOMIZED_PARTITION(int A[], int p, int r);

int RANDOMIZED_SELECT(int A[], int p, int r, int i);
void InsertionSort(int A[]);

int main()
{
    int A1[ARRAYSIZE];

    int i;
    int num;
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < ARRAYSIZE; i++)
    {
        num = rand();
        A1[i] = num;
    }

    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A1[i]);
    }

    printf("Sonuc: %d\n",RANDOMIZED_SELECT(A1,0,ARRAYSIZE-1,10));

    InsertionSort(A1);

    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A1[i]);
    }

    return 0;
}

void InsertionSort(int A[])
{
	printf("Insertion Sort starts!\n");
	int i,j;
	int key;
	for(j = 1; j < ARRAYSIZE; j++)
	{
		key = A[j];
		i = j-1;
		while(i >= 0 && A[i] > key)
		{
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
}

int PARTITION(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    int j, temp;
    for(j = p; j < r; j++)
    {
        if(A[j] <= x)
        {
            i = i + 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i + 1;
}

int RANDOMIZED_PARTITION(int A[], int p, int r)
{
	int i = (rand() % (r - p + 1)) + p;
	int temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	return PARTITION(A,p,r);
}

int RANDOMIZED_SELECT(int A[], int p, int r, int i)
{
    if(p == r)
    {
    	return A[p];
	}
	
	int q = RANDOMIZED_PARTITION(A, p, r);
	int k = q - p + 1;
	
	if(i == k)
		return A[q];
	else if(i < k)
		return RANDOMIZED_SELECT(A, p, q-1, i);
	else
		return RANDOMIZED_SELECT(A, q+1, r, i-k);
}
