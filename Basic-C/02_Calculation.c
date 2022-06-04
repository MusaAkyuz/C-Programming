#include <stdio.h>

int main(void)
{

int a,b,x,z;    //a,b,x,z are an integer number (0,1,5,8,12342...)
float c,d,y,k;  //c,d,y,k are a decimal number (3.3,56.1,153124.0,...)

a = 5;
b = 100;
c = 4.3;
d = 99.9;

x = a+b;    //calculating x = 105
y = a+b;    //calculating y = 105
z = c+d;    //calculating z = 104 (but real 104.2)
k = c+d;    //calculating k = 104.2

printf("a + b = %d     \n",x);       
printf("a + b = %f     \n",x);
printf("a + b = %d     \n",y);
printf("a + b = %f     \n",y);
printf("a + b = %3.2f  \n",y);
printf("c + d = %d     \n",z);
printf("c + d = %f     \n",z);
printf("c + d = %d     \n",k);
printf("c + d = %f     \n",k);
printf("c + d = %3.2f  \n",k);






}


