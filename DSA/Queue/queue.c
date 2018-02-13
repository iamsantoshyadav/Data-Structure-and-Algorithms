//This program is for single ended queue which is FIFO or first in first out process
#include<stdio.h>
#include<conio.h>
void insert();//insert function for queue
void del();//delete function
void display();//display function
int data[10],front=-1,last=-1
void main()
{
    int ip;
    while(1)
    {
        printf("================Enter Your Choice================\n");
        printf("1. For Insert\n");
        printf("2. For Delete\n");
        printf("3. For display\n");
        scanf("%d",&ip);
        switch(ip)
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            default :
                exit(0);

        }
    }
}
void insert()
{
    int no;
    if (front==0&&last==9)//condition for overflow
    {
        printf("Queue is overflow\n");
    }
    else
    {
        if (front==-1)
        {
            printf("Enter a no\n");
            scanf("%d",&no);
            front=0;
            last=0;
            data[front]=no;
        }
        else
        {
            printf("Enter a no\n");
            scanf("%d",&no);
            last++;
            data[last]=no;
        }
    }
}
void del()
{
    if(front==-1) //condition for under flow
    {
        printf("Queue is under flow\n");
    }
    else
    {
        if(front==0&&last==0)
        {
            data[front]=NULL;
            front=-1;
            last=-1;

        }
        else
        {
            data[front]=NULL;
            front++;
        }
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is Underflow\n");
    }
    else
    {
        for(i=front;i<=last;i++)
        {
            printf("%d\t",data[i]);
        }
        printf("\n");
    }
}
