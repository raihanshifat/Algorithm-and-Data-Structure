#include<stdio.h>
#define SIZE 5
int front=-1;
int rear=-1;
int items[SIZE];
void enQueue(int value)
{
 if(rear==SIZE-1)
    {
        printf("\nQueue is full");
    }
    else{
        if(front==-1)
        {
            front=0;
        }
        rear++;
        printf("\nThe added value is %d",value);
        items[rear]=value;
    }
}
void deQueue()
{
    if(rear==-1)
    {
        printf("\nQueue is empty");
    }
    else{
        front++;
        if(front>rear)
        {
            front=rear=-1;
        }
    }
}
void display()
{
    if(rear==-1)
    {
        printf("\nqueue is empty");
    }
    else{
        for(int i=front;i<=rear;i++)
        {
            printf("%d",items[i]);
        }
    }

}
int main()
{
    //deQueue is not possible on empty queue
    deQueue();

    //enQueue 5 elements
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

    //6th element can't be added to queue because queue is full
    enQueue(6);

    display();

    //deQueue removes element entered first i.e. 1
    deQueue();

    //Now we have just 4 elements
    display();

    return 0;

}
