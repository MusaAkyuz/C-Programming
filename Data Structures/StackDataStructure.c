#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int capacity;
    int top;
    int* items;
}stack;

stack* NewStack(int size);
int StackEmpty(stack* pt);
int StackFull(stack* pt);
void Push(int element, stack* pt);
int Pop(stack* pt);

int main()
{
	stack* myStack = NewStack(5);
	int i = 1;
	while(i < 5)
	{
		//sleep(1);
		Push(i*10, myStack);
		//printf("Pushing %d\n", i*10);
		//sleep(1);
		i++;
	}
	
	for(i = 0; i < 3; i++)
	{
		Pop(myStack);
		//printf("Popping %d\n", Pop(myStack));
	}
	i = 1;
	while(i<6)
	{
		Push(i*10, myStack);
		//printf("Pushing %d\n", i*10);
		i++;
	}
	
	for(i = 0; i < 2; i++)
	{
		Pop(myStack);
		//printf("Popping %d\n", Pop(myStack));
	}

//	Push(10, myStack);
//	Push(20, myStack);
//	Push(30, myStack);
//	Push(40, myStack);
//	
//	Pop(myStack);
//	Pop(myStack);
//	Pop(myStack);
//	
//	Push(10, myStack);
//	Push(20, myStack);
//	Push(30, myStack);
//	Push(50, myStack);
//	
//	Pop(myStack);
//	Pop(myStack);
	
}

stack* NewStack(int size)
{
	stack *pt = (stack*)malloc(sizeof(stack));

	pt->capacity = size;
	pt->top = -1;
	pt->items = (int*)malloc(sizeof(int) * size);

	return pt;
}

int StackEmpty(stack *pt)
{
	return (pt->top == -1);
}

int StackFull(stack *pt)
{
    return (pt->top == pt->capacity-1);
}

void Push(int element, stack* pt)
{
    if(StackFull(pt))
    {
        printf("Stack doldu! Yeni eleman eklenemez!\n");
    }
    else
    {
        pt->top++;
        pt->items[pt->top] = element;
        printf("%d elemani eklendi\n",element);
    }
}

int Pop(stack* pt)
{
    if(StackEmpty(pt))
    {
        printf("Stack bos!\n");
        exit(-1);
    }
    else
    {
        pt->top--;
        printf("%d elemani siliniyor.\n",pt->items[pt->top+1]);
        return pt->items[pt->top+1];
    }
}


