#include<stdio.h>
#include<conio.h>
//this program is for develop stack
void push();//Function for push operation
void pop();//function for pop operation
void display();//function for display the item
int data[5],front=-1,last=0;
void main()
{
    int ip;
    while(1)
    {
        printf("========Enter Your Choice========\n");
        printf("1. For PUSH Operation\n");
        printf("2. For POP Operation\n");
        printf("3. For Display Operation\n");
        scanf("%d",&ip);
        switch(ip)
        {

            case 1:
                push();
                break;
            case 2 :
                pop();
                break;
            case 3:
                display();
                break;
            default :
                exit(0);

        }
    }
}
void push()
{
    int no;
    if(front==4)//overflow condition
    {
        printf("========Stack is Overflow========\n");
    }
    else
    {
        printf("Enter a no \n");
        scanf("%d",&no);
        front++;
        data[front]=no;
    }
}
void pop()
{
    if(front==-1)//under flow condition
    {
        printf("========Stack is underflow========\n");
    }
    else
    {
        data[front]=0;
        front--;
    }
}
void display()// to display the item in stack
{
    int i;
    if (front==-1)//if array is empty
    {
        printf("No item to Display\n")
    }
    else
    {
        for(i=0;i<=front;i++)
        {
            printf("%d\t",data[i]);
        }
    }

    printf("\n");
}
