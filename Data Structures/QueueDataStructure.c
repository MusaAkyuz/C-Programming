#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front;
    int rear;
    int numberOfElements; //sıradaki eleman sayısı
    int capacity; //sıranın maksimum büyüklüğü
    int* array;
}Queue;

Queue* createQueue(int size);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);

int main()
{
    Queue* myQueue = createQueue(5);
    
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    
    printf("dequeue : %d\n", dequeue(myQueue));
	printf("dequeue : %d\n", dequeue(myQueue));
	printf("dequeue : %d\n", dequeue(myQueue));    
    
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 50);
    
    printf("dequeue : %d\n", dequeue(myQueue));
    printf("dequeue : %d\n", dequeue(myQueue));
}

Queue* createQueue(int size)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = size;
    queue->front = 0;
    queue->numberOfElements = 0;
    queue->rear = 0;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue)
{
    return (queue->numberOfElements == queue->capacity);
}

int isEmpty(Queue* queue)
{
    return (queue->numberOfElements == 0);
}

void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
    {
        printf("Ekleme yapilamaz, sira dolu!\n");
        return;
    }
    queue->array[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->numberOfElements = queue->numberOfElements + 1;
    printf("%d siraya eklendi\n", item);
}

int dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Sira bos! Program sonlandiriliyor!\n");
        exit(-1);
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->numberOfElements = queue->numberOfElements - 1;
    return item;
}
