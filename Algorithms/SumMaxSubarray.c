/* Calisma 3 - Yapiacaklar
1. Asagidaki dosyada subArray yapisini kullanarak maksimum altdizi problemini asagidaki fonksiyonlari kullanarak cozunuz.
- Kaba kuvvet ile (BruteFore fonksiyonu)
- Bol ve yonet yontemi ile (FIND_MAX_CROSSING_SUBARRAY, FIND_MAXIMUM_SUBARRAY fonksiyonlari ile)
2. Daha sonra iki farkli yontemi farkli girdi boyutlari ile karsilastiriniz. */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 199999 // toplam fiyat sayisi


    
typedef struct subArray // baslangic, bitis ve toplam deger bilgisini bir arada tutmak icin kullandigimiz yapi
{
    int maxBasla;
    int maxSon;
    int maxToplam;
}subArray;

subArray FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high);
subArray FIND_MAXIMUM_SUBARRAY(int A[], int low, int high);
subArray BruteForce(int A[]);

int main()
{
    int i;
    int fiyatlar[ARRAYSIZE];
    int degisim[ARRAYSIZE];
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < ARRAYSIZE; i++)
    {
        fiyatlar[i] = (rand() % 120) + 1; // fiyatlari olusturalim
    }
    for(i = 1; i < ARRAYSIZE; i++)
    {
        degisim[i] = fiyatlar[i] - fiyatlar[i-1]; // fiyat degisimlerini hesaplayalim
    }
    
    clock_t start_t, end_t;
    double cpu_time_used;
    start_t = clock();
    subArray res = FIND_MAXIMUM_SUBARRAY(degisim,1,ARRAYSIZE-1); // bol ve yonet yontemi
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure Recursive: %f saniyedir.\n", cpu_time_used);
    
//    for(i = 0; i < ARRAYSIZE; i++)
//    {
//        printf("%d: %d\n", i, fiyatlar[i]);
//    }
    printf("Al: %d\n", res.maxBasla - 1); // bulunan degerleri yazdiralim
    printf("Sat: %d\n", res.maxSon);
    printf("Kar: %d\n", res.maxToplam);
    
//    subArray res2 = BruteForce(fiyatlar); // bulunan degerleri yazdiralim
//    printf("Al: %d\n", res2.maxBasla);
//    printf("Sat: %d\n", res2.maxSon);
//    printf("Kar: %d\n", res2.maxToplam);

	clock_t start_t2, end_t2;
    double cpu_time_used2;
    start_t2 = clock();
	MusasMethod(fiyatlar);
	end_t2 = clock();
    cpu_time_used2 = (double)(end_t2 - start_t2) / CLOCKS_PER_SEC;
    printf("\nToplam gecen sure MusasMethod: %f saniyedir.\n", cpu_time_used2);
	
	
	
	return 0;
}

subArray BruteForce(int A[])
{
    subArray res;
    
    int i, j;
    int max = 0;
    res.maxToplam = 0;
    for(i = 0; i<ARRAYSIZE; i++)
    {
    	for(j = i+1; j<ARRAYSIZE; j++)
    	{
    		max = A[j] - A[i];
    		if(max > res.maxToplam)
    		{
    			res.maxToplam = max;
    			res.maxBasla = i;
    			res.maxSon = j;
			}
		}
	}
    return res;
}

subArray FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high)
{
    subArray res;
    int leftSum = INT_MIN;
    int sum = 0;
    
    int i;
    for(i = mid; i>=low; i--)
    {
    	sum += A[i];
    	if(sum > leftSum)
    	{
    		leftSum = sum;
    		res.maxBasla = i;
		}
	}
	
	int rightSum = INT_MIN;
	sum = 0;
	
	for(i = mid + 1; i <= high; i++)
	{
		sum += A[i];
		if(sum > rightSum)
		{
			rightSum = sum;
			res.maxSon = i;
		}
	}
	res.maxToplam = rightSum + leftSum;
	
    return res;
}

subArray FIND_MAXIMUM_SUBARRAY(int A[], int low, int high)
{
    subArray res;
    
    if(high == low)
    {
    	res.maxBasla = low;
    	res.maxSon = high;
    	res.maxToplam = A[low];
    	return res;
	}
    else
    {
    	int mid = (low + high) / 2;
    	subArray left = FIND_MAXIMUM_SUBARRAY(A, low, mid);
    	subArray right = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
    	subArray midl = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high);
    	if(left.maxToplam >= right.maxToplam && left.maxToplam >= midl.maxToplam)
    	{
    		res.maxBasla = left.maxBasla;
    		res.maxSon = left.maxSon;
    		res.maxToplam = left.maxToplam;
		}
		
		if(right.maxToplam >= left.maxToplam && right.maxToplam >= midl.maxToplam)
    	{
    		res.maxBasla = right.maxBasla;
    		res.maxSon = right.maxSon;
    		res.maxToplam = right.maxToplam;
		}
		
		if(midl.maxToplam >= right.maxToplam && midl.maxToplam >= right.maxToplam)
    	{
    		res.maxBasla = midl.maxBasla;
    		res.maxSon = midl.maxSon;
    		res.maxToplam = midl.maxToplam;
		}
	}
    return res;
}

int MusasMethod(int A[])
{
	int min = INT_MAX;
	int profit;
	int maxProfit = 0;
	int alGun;
	int satGun;
	
	int i;
	for(i = 0; i < ARRAYSIZE; i++)
	{
		if(A[i] < min)
		{
			min = A[i];
			alGun = i;
		}
		else
		{
			profit = A[i] - min;
			if(profit > maxProfit)
			{
				maxProfit = profit;
				satGun = i;
			}
		}
	}
	printf("Al: %d", alGun);
	printf("Sat: %d", satGun);
	printf("Kar: %d", maxProfit);
	return 0;
}
