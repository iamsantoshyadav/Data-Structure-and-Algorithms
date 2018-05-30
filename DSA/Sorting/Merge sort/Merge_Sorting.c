#include<stdio.h>
#include<conio.h>
int split(int *data,int noElement);
int sort(int *data,int *leftArray,int leftCount,int *rightArray, int rightCount);
void main()
{
    int noElement,i,*data;
    printf("Enters Numbers of Element you want to Sort : ");
    scanf("%d",&noElement);
    printf("Enter Here all The %d elements \n\n",noElement);
    data=(int*)malloc(noElement*sizeof(int));
    for(i=0;i<noElement;i++)
    {
        printf("%d Element : ",i+1);
        scanf("%d",&data[i]);
    }
    split(data,noElement);
    printf("================Your Sorted Data================\n\n");
    for(i=0;i<noElement;i++)
    {
        printf("%d  ",data[i]);
    }
    printf("\n\n");

}
int split(int *data,int noElement)
{
    int mid,*leftArray,*rightArray,i;
    if(noElement<2)
    {
        return;
    }
    else
    {
        mid =noElement/2;
        leftArray=(int*)malloc(mid*sizeof(int));
        rightArray=(int*)malloc((noElement-mid)*sizeof(int));
        for(i=0;i<mid;i++)
        {
            leftArray[i]=data[i];
        }
        for(i=mid;i<noElement;i++)
        {
            rightArray[i-mid]=data[i];
        }
        split(leftArray,mid);
        split(rightArray,noElement-mid);
        sort(data,leftArray,mid,rightArray,noElement-mid);

    }
}
int sort(int *data, int *leftArray, int leftCount,int *rightArray,int rightCount)
{
    int i=0,j=0,k=0;
    while(i<leftCount&&j<rightCount)
    {
        if(leftArray[i]<rightArray[j])
        {
            data[k]=leftArray[i];
            i++;
        }
        else
        {
            data[k]=rightArray[j];
            j++;
        }
        k++;
    }
    while(i<leftCount)
    {
        data[k]=leftArray[i];
        i++;
        k++;
    }
    while(j<rightCount)
    {
        data[k]=rightArray[j];
        j++;
        k++;
    }
    free(leftArray);
    free(rightArray);
}
