//This program is for implementation of Double ended queue
#include<stdio.h>
#include<conio.h>
void insert_front();//Function for perform insertion from front
void insert_last();//Function for perform insertion from back side
void del_front();//Function for deletion from front side
void del_last();//Function for perform deletion from back side
void display();//Function for display all the content in array
data[5],front=-1,last=-1;
void main()
{
    int ip;
    while(1)
    {
        printf("================ENTER YOUR CHOICE================\n");
        printf("1.For Insert in Front\n");
        printf("2.For Insert in Last\n");
        printf("3.For Delete in Front\n");
        printf("4.For Delete in Last\n");
        printf("5.For Display\n");
        scanf("%d",&ip);
        switch(ip)
        {
            case 1:
                insert_front();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                del_front();
                break;
            case 4:
                del_last();
                break;
            case 5:
                display();
                break;
            default :
                exit(0);
        }
    }

}
void insert_front()
{
    int no;
    if(front==0)
    {
        printf("================QUEUE IS OVERFLOW FROM FRONT SIDE================\n\n\n");
    }
    else
    {
        if(front==-1)
        {
            printf("Enter a no >>>>>>>> : ");
            scanf("%d",&no);
            front=0;
            last=0;
            data[front]=no;
        }
        else
        {
            front--;
            printf("Enter a no >>>>>>>> : ");
            scanf("%d",&no);
            data[front]=no;
        }
    }
}
void insert_last()
{
    int no;
    if(last==4)
    {
        printf("================QUEUE IS OVERFLOW FROM BACK SIDE================\n\n\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
            last=0;
            printf("Enter a no >>>>>>>> : ",no);
            scanf("%d",&no);
            data[front]=no;
        }
        else
        {
            last++;
            printf("Enter a no >>>>>>>> : ",no);
            scanf("%d",&no);
            data[last]=no;
        }
    }
}
void del_front()
{
    if(front==-1)
    {
        printf("================QUEUE IS UNDERFLOW FROM FRONT================\n\n\n");
    }
    else
    {
        if(front==0)
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
void del_last()
{
    if(last==-1)
    {
        printf("================QUEUE IS UNDER FLOW================\n\n\n");
    }
    else
    {
        if(last==0)
        {
            data[last]=NULL;
            front=-1;
            last=-1;
        }
        else
        {
            data[last]=NULL;
            last--;
        }
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("================QUEUE IS UNDER FLOW================\n\n\n");
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
