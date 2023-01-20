#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10

typedef struct node
{
    int data;
    struct node *next;
}node;

node **head;

void SetTable();
int HashBolme(int key);
int HashCarpma(int key);
void HashInsert(int key);
void HashDelete(int key);
int HashSearch(int key);
void display();

int main()
{
	SetTable();
	
	HashInsert(7);
	HashInsert(5);
	HashInsert(4);
	HashInsert(3);
	HashInsert(12);
	HashInsert(12);
	HashInsert(12);
	HashInsert(15);
	HashInsert(16);
	HashInsert(17);
	HashInsert(18);
	HashInsert(19);
	HashInsert(20);
	HashInsert(21);
	HashInsert(22);
	HashInsert(23);
	HashInsert(24);
	
	display();
	
    return 0;
}

void SetTable()
{
    int i;
    head = (node**)malloc(sizeof(node*)*TABLE_SIZE);
    for(i = 0; i < TABLE_SIZE;i++)
    {
        head[i] = NULL;
    }
}

node* CreateNewNode(int key)
{
    node * newnode=(node *)malloc(sizeof(node));
    newnode->data=key;
    newnode->next = NULL;
    return newnode;
}

int HashBolme(int key)
{
	int hash = key%TABLE_SIZE;
	
	return hash;
}

int HashCarpma(int key)
{
	float A = (sqrt(5.0) - 1) / 2;
	//printf("A : %f\n", A);
	//float A = 4.12452;
	
	int kA = key * A;
	//printf("kA : %d\n", kA);
	
	//int hash = (TABLE_SIZE * (((float)key * A) - kA));
	int hash = TABLE_SIZE % (int)(A*key + A*A*key);  
	//printf("hash : %d\n", hash);
	
	return hash;
}

void HashInsert(int key)
{
    int pos;
    pos=HashCarpma(key);
    node * newnode=CreateNewNode(key);
    if(head[pos] == NULL)
    {
        head[pos] = newnode;
    }
    else
    {
        newnode->next = head[pos];
        head[pos] = newnode;
    }
}

void HashDelete(int key)
{
    int pos;
    pos=HashCarpma(key);
    node* c=head[pos];
    if(c == NULL)
        return;
    else if(c->data == key)
    {
        if(c->next != NULL)
            head[pos] = c->next;
        else
            head[pos] = NULL;
        free(c);
    }
    else
    {
        while(c->next != NULL && c->next->data != key)
            c = c->next;
        if(c->next != NULL)
        {
            node *t = c->next;
            c->next = c->next->next;
            free(t);
        }
    }
}

int HashSearch(int key)
{
    int pos;
    node *c;
    pos = HashCarpma(key);
    if(head[pos] == NULL)
        return -1;
    else
    {
        for(c=head[pos];c!=NULL;c=c->next)
        {
            if(c->data == key)
            {
                return pos;
            }
        }
        return -1;

    }
}

void display()
{
    printf("\n\nDisplay starts///////////////\n");
    int i;
    for(i=0;i<TABLE_SIZE;i++)
    {
        printf("\nentries at index %d\n",i);
        if(head[i] == NULL)
        {
            printf("No Hash Entry");

        }
        else
        {
            node* c;
            for(c=head[i];c!=NULL;c=c->next)
                printf("%d->",c->data);
        }
    }
    printf("\n\nDisplay ends////////////////\n");

}
