#include<stdio.h>
#include<conio.h>
typedef struct node
{
    int data;
    struct node *nxtAddress,*preAddress;
}node;
node *start=NULL;
void createFirst();
void createLast();
//void createLoc();
//void deleteFirst();
//void deleteLast();
//void deleteLoc();
void display();
void main()
{
    int ip;
    while(1)
    {
        printf("================YOU HAVE FOLLOWING OPETIONS================\n\n");
        printf("1. Create First\n");
        printf("2. Create Last\n");
        printf("3. Create at Loc\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete at Loc\n");
        printf("7. Display the Data\n");
        printf("8. Exit\n");
        printf("Enter Your Choice here >>> : ");
        scanf("%d",&ip);
        switch(ip)
        {
            case 1:
                createFirst();
                break;
            case 2:
                createLast();
                break;
            /*case 3 :
                createLoc();
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                deleteLoc();
                break;
            */case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Wrong Choice Please Try Again\n\n");

        }
    }
}
void createFirst()
{
    int data;
    node *newNode,*preNode;
    newNode=(node*) malloc(sizeof(node));
    if(start==NULL)
    {
       start=newNode;
       printf("Enter Data  :  ");
       scanf("%d",&data);
       printf("\n");
       newNode->data=data;
       newNode->preAddress=NULL;
       newNode->nxtAddress=NULL;
    }
    else
    {
        newNode->nxtAddress=start;
        newNode->preAddress=NULL;
        preNode=start;
        preNode->preAddress=newNode;
        start=newNode;

        printf("Enter New Data : ");
        scanf("%d",&data);
        printf("\n");
        newNode->data=data;
    }
}
void createLast()
{
    int data;
    node *newNode,*preNode;
    newNode=(node*) malloc(sizeof(node));
    if(start==NULL)
    {
        start=newNode;
        printf("Enter a New Data in  >>> : ");
        scanf("%d",&data);
        printf("\n");
        newNode->preAddress=NULL;
        newNode->data=data;
        newNode->nxtAddress=NULL;
    }
    else
    {
        preNode=start;
        while(preNode->nxtAddress!=NULL)
        {
            preNode=preNode->nxtAddress;
        }
        preNode->nxtAddress=newNode;
        newNode->preAddress=preNode;
        newNode->nxtAddress=NULL;
        printf("Enter a New Data >>> : ");
        scanf("%d",&data);
        printf("\n");
        newNode->data=data;
    }
}
void display()
{
    node *addPointer;
    if(start==NULL)
    {
        printf("There are no any data to Display\n");
    }
    else
    {
        addPointer=start;
        printf("================Your Linked List Data================\n\n");
        while(addPointer!=NULL)
        {
            printf("%d  ",addPointer->data);
            addPointer=addPointer->nxtAddress;

        }
        printf("\n\n\n");
    }

}
