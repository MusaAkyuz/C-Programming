/* Calisma 2 - Yapilacaklar
1- Oncelikle asagida uygun yerlere birlestirmeli sıralama algoritmasini yaziniz. Algoritmanin dogru calistigindan emin olunuz.
2- Daha sonra iki farkli siralama algoritmasinin performansini farkli girdi boyutlari ile karsilastiriniz - Ornegin 100, 1000, 10000, 100000 sayi gibi.
3- Sonuclarinizi ve yazdiginiz kodu e-posta ile bana gonderebilirsiniz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 1000                                              BBBB

void InsertionSort(int A[]);
void Merge(int A[], int p, int q, int r);
void MergeSort(int A[],int p, int r);

int main()
{
    int A1[ARRAYSIZE];
    int A2[ARRAYSIZE];
    int i;
    int num;
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < ARRAYSIZE; i++)
    {
        num = rand();
        A1[i] = num;
        A2[i] = num;
    }

    /*for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A2[i]);
    }*/

    clock_t start_t, end_t;
    double cpu_time_used;
    start_t = clock();
    InsertionSort(A1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Eklemeli Siralama): %f saniyedir.\n", cpu_time_used);

    start_t = clock();
    // MergeSort cagirilma seklini degistirebilirsiniz.
    MergeSort(A2,0,ARRAYSIZE - 1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Birlestirmeli Siralama): %f saniyedir.\n", cpu_time_used);

    /*for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A2[i]);
    }
	*/
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
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int leftArr[n1 + 1];
	int rightArr[n2 + 1];
	
	int i;
	for(i = 0; i < n1; i++)
	{
		leftArr[i] = A[p + i];
	}
	
	int j;
	for(j = 0; j < n2; j++)
	{
		rightArr[j] = A[q + j + 1];
	}
	
	leftArr[n1] = INT_MAX;
	rightArr[n2] = INT_MAX;
	
	i = 0;
	j = 0;
	int k;
	for(k = p; k <= r; k++)
	{
		if(leftArr[i] <= rightArr[j])
		{
			A[k] = leftArr[i];
			i++;
		}
		else
		{
			A[k] = rightArr[j];
			j++;
		}
	}
	
//	while(i < r)
//	{
//		A[k] = leftArr[i];
//		i++;
//		k++;
//	}
//	
//	while(j < r)
//	{
//		A[k] = rightArr[j];
//		j++;
//		k++;
//	}
//	
}

void MergeSort(int A[], int p, int r)
{
    int q = (r + p)/2;
	if (p < r)
	{
		MergeSort(A, p, q);
    	MergeSort(A, q + 1, r);
    	Merge(A, p, q, r);
	}

}
