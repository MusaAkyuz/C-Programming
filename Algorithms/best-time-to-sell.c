#include <stdio.h>
#include <limits.h>

int main() {
    int price[10] = {12, 2, 3, 78, 2, 5, 67, 12, 3, 8};
    int min = INT_MAX;
    int profit;
    int maxProfit = 0;

	int i;
    for(i = 0; i<10; i++) {
        if(price[i] < min) {
            min = price[i];
        }
        else {
            profit = price[i] - min;
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
    }
    
    printf("%d", maxProfit);
    return 0;
}
