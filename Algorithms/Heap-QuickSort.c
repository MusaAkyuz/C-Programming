#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 100

typedef struct Heap
{
    int size;
    int *A;
}Heap;

void InsertionSort(int A[]);
void Merge(int A[], int p, int q, int r);
void MergeSort(int A[],int p, int r);

void Max_Heapify(Heap myHeap, int i);
void Build_Max_Heap(Heap myHeap);
void Heap_Sort(Heap myHeap);

void QUICKSORT(int A[], int p, int r);
int PARTITION(int A[], int p, int r);
int RANDOMPARTITION(int A[], int p, int r);

int main()
{
    int A1[ARRAYSIZE];
    int A2[ARRAYSIZE];
    int A3[ARRAYSIZE];
    int A4[ARRAYSIZE];
    int i;
    int num;
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < ARRAYSIZE; i++)
    {
        num = rand();
        A1[i] = num;
        A2[i] = num;
        A3[i] = num;
        A4[i] = num;
    }

    /*for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A4[i]);
    }*/

    clock_t start_t, end_t;
    double cpu_time_used;
    start_t = clock();
    InsertionSort(A1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Eklemeli Siralama): %f saniyedir.\n", cpu_time_used);

    start_t = clock();
    MergeSort(A2,0,ARRAYSIZE-1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Birlestirmeli Siralama): %f saniyedir.\n", cpu_time_used);

    start_t = clock();
    Heap myHeap;
    myHeap.A = A3;
    myHeap.size = ARRAYSIZE;
    Heap_Sort(myHeap);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Yigin Siralama): %f saniyedir.\n", cpu_time_used);
    
    start_t = clock();
    QUICKSORT(A4,0,ARRAYSIZE-1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Hizli Siralama): %f saniyedir.\n", cpu_time_used);

    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A4[i]);
    }

    return 0;
}

void InsertionSort(int A[])
{
    int i,j,key;
    for(j = 1; j < ARRAYSIZE; j++)
    {
        key = A[j];
        i = j - 1;
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

void Merge(int A[], int p, int q, int r)
{
    int i,j,k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = (int *)malloc((n1+1)*sizeof(int));
    int *R = (int *)malloc((n2+1)*sizeof(int));

    for(i = 0; i < n1; i++)
    {
        L[i] = A[p+i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = A[q+j+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for(k = p; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[],int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r) / 2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

void Max_Heapify(Heap myHeap, int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;
    int temp;
    if(l < myHeap.size && myHeap.A[l] > myHeap.A[i])
        largest = l;
    else
        largest = i;
    if(r < myHeap.size && myHeap.A[r] > myHeap.A[largest])
        largest = r;
    if(largest != i)
    {
        temp = myHeap.A[i];
        myHeap.A[i] = myHeap.A[largest];
        myHeap.A[largest] = temp;
        Max_Heapify(myHeap,largest);
    }
}

void Build_Max_Heap(Heap myHeap)
{
    int i;
    for(i = ARRAYSIZE/2; i >= 0; i--)
    {
        Max_Heapify(myHeap,i);
    }
}

void Heap_Sort(Heap myHeap)
{
    Build_Max_Heap(myHeap);
    int i, temp;
    for(i = ARRAYSIZE - 1; i > 0; i--)
    {
        temp = myHeap.A[i];
        myHeap.A[i] = myHeap.A[0];
        myHeap.A[0] = temp;
        myHeap.size = myHeap.size - 1;
        Max_Heapify(myHeap,0);
    }
}

void QUICKSORT(int A[], int p, int r)
{
	if (p < r)
	{	
		int q = RANDOMPARTITION(A, p, r);
		//int q = PARTITION(A, p, r);
		QUICKSORT(A, p, q - 1);
		QUICKSORT(A, q + 1, r);
	}
}

int PARTITION(int A[], int p, int r)
{
	int pivot = A[r];
	int i = p - 1;
	int count;
	for (count = p; count < r; count++)
	{
		if (A[count] <= pivot)
		{
			i++;
			int temp = A[i];
			A[i] = A[count];
			A[count] = temp;
		}
	}
	int swap = A[i + 1];
	A[i + 1] = A[r];
	A[r] = swap;
	
	return i+1;
}

int RANDOMPARTITION(int A[], int p, int r)
{
	int diff = r - p;
	int random = (rand() % diff) + p;
	int temp = A[r];
	A[r] = A[random];
	A[random] = temp;
	return PARTITION(A, p, r);
}
