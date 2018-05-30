#include<stdio.h>
#include<conio.h>
#include<time.h>
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void main()
{
    int data[15],temp,i,j,k;
    for(j=0;j<15;j++)
    {
        data[j]=0;
    }
    printf("================ENTER ELEMENT IN ARRAY================\n");
    for(i=0;i<15;i++)
    {
        printf("%d >>> : ",i+1);
        scanf("%d",&data[i]);
        printf("\n");
    }
    printf("================GIVEN DATA FOR SORTING IS================\n");
    for(i=0;i<15;i++)
    {
        printf("%d  ",data[i]);
    }
    printf("\n================YOU CAN SEE ALL THE CHANGES HERE================\n");
    for(i=0;i<15;i++)
    {
        temp=data[i];
        for(k=i;k>=0;k--)
        {
            if(data[k]>temp)
            {
                data[k+1]=data[k];
                data[k]=temp;
            }
        }
        for(j=0;j<15;j++)
        {
            printf("%d  ",data[j]);
        }
        printf("\n");
        delay(500);
    }
    printf("\n================FINAL SORTED DATA IS HERE================\n");
    for(i=0;i<15;i++)
    {
        printf("%d  ",data[i]);
    }
}
