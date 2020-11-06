#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack{
int item[MAX];
int TOP;
};
typedef struct stack st;
void creatstack(st *s)
{
    s->TOP=-1;
}
int isfull(st *s)
{
    if(s->TOP==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(st *s)
{

    if(s->TOP==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void push(st *s)
{
    int newitem;
    printf("Enter item to be added");
    scanf("%d",&newitem);
    if(isfull(s)){
        printf("stack is full");
    }
    else{
        s->TOP++;
        s->item[s->TOP]=newitem;
    }
}
void pop(st *s)
{
    if(isempty(s))
    {
        printf("stack is empty");

    }
    else
    {
        s->TOP--;
    }
}
void main()
{
    int ch;
    int loop=1;
    st *s = (st*)malloc(sizeof(st));

    creatstack(s);
    do{
        printf("\n ***STACK OPERATIONS");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. EXIT");
        printf("\n ***************");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
         printf("THANK YOU");
            loop=0;
            exit(0);
        default:
             printf("Invalid choice");
             break;
        }

    }while(loop);

}
