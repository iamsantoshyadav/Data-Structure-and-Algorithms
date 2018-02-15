#include<stdio.h>
#include<conio.h>
void main()
{
    int data[10],i,j,no,check;
    printf("================ENTER DATA IN ARRAY================\n\n\n");
    for(i=0;i<10;i++)
    {
        printf("Element %d : ",i+1);
        scanf("%d",&data[i]);
        printf("\n");
    }
    for (i=0;i<10;i++)
    {
        printf("%d\t",data[i]);
    }
    printf("Enter data which you want to search : ");
    scanf("%d",&no);
    for (i=0;i<10;i++)
    {
        if(data[i]==no)
        {
            check=1;

        }
    }
    if (check==1)
    {
        printf("%d found in given data \n",no);
    }
    else
    {
        printf("%d Not found in given data \n",no);
    }
}
