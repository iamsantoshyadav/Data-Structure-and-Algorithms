/*
Developed By - Santosh Yadav
Problem = Bubble Sort Algorithm
*/
//This program is Implimentation of Bubble shorting algorithms
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int data[15],i,j,large,small;
    for(i=0;i<15;i++)
    {
        data[i]=0;//Initialize Array data
    }
    printf("Enter 15 The data \n");
    for(i=0;i<15;i++)
    {
        printf("%d >>> : ",i+1);
        scanf("%d",&data[i]);  //Enter 15 element here to short
    }
    for(j=0;j<15;j++)//repeting all process for every no of data
    {

        large=data[0];//intitialise large with first element
        for(i=0;i<15;i++)
        {


            if(data[i]>=large)//condition for large BUBBlE
            {
                large=data[i];
            }
            else
            {
                if(data[i]<large) //Condition for Small BUBBlE
                {
                    data[i-1]=data[i];
                    data[i]=large;
                }
            }
        }
        //Repeating every time we have did iteration
        //Comment this if not want to see changes after every iteration
        for(i=0;i<15;i++)//to see every changes with data
        {
            printf("%d  ",data[i]);
        }
        printf("\n");
    }
    /*
    UNCOMMENT THIS IF WANT TO SEE ONLY FINAL OUTPUT
    printf("Sorted data\n");
    for(i=0;i<15;i++)
    {
        printf("%d  ",data[i]);
    }
    */


}
