/*
Created by -Santosh Yadav
Problem - Select sorting Algorithm
*/
//This program is just an simple implimentation of Select sorting algorithm
#include<stdio.h>
#include<conio.h>
void main()
{

    int data[15],i,j=0,k,small,position,temp,l,swap;
    for(i=0;i<15;i++)
    {
        data[i]=0;
    }
    printf("================ENTER 15 ELEMENTS FOR SORTING================\n");
    for(i=0;i<15;i++)
    {
        printf("%d >>>> : ",i+1);
        scanf("%d",&data[i]);
        printf("\n");
    }
    printf("================Given data is================\n");
    for(i=0;i<15;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n\n================YOU CAN SEE ALL THE CHANGES HERE================\n");
    for(i=j;i<15;i++)
    {
        small=data[j];//assigning one by one data of the element small initiasialy by using j
        k=j;//k is used for finding the smallest value of the element which will start from first element
        while(k!=15)
        {
            if(data[k]<=small)
            {
                small=data[k];
                position=k;//to get exact position for swaping the values with each other
            }
            k++;
        }
        //interchanging the all value using temp variable
        temp=data[position];
        data[position]=data[j];
        data[j]=small;
        j++;
        //Comment This section if you not want to see all the changes ocured every time
        for(l=0;l<15;l++)
        {
            printf("%d  ",data[l]);
        }
        printf("\n");
    }
    printf("Final sorted list is\n ");
    for(i=0;i<15;i++)
    {
        printf("%d ",data[i]);
    }
}
