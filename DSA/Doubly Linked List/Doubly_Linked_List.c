//Implementation of Doubly Linked list
#include<stdio.h>
#include<conio.h>
typedef struct node
{
    int data;//Data will take the data from user
    struct node *nxtAddress,*preAddress;//nxtAddress will point to the address of next Node and preAddress point to the address of previous node
}node;
node *start=NULL;//Head of the linked list
void createFirst();
void createLast();
void createLoc();
void deleteFirst();
void deleteLast();
void deleteLoc();
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
            case 3 :
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
            case 7:
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
    newNode=(node*) malloc(sizeof(node));//get new memory allocation for new node
    if(start==NULL)//Condition for first Node
    {
       start=newNode;
       printf("Enter Data  :  ");
       scanf("%d",&data);
       printf("\n");
       newNode->data=data;
       newNode->preAddress=NULL;//Update previous address and next address wit NULL
       newNode->nxtAddress=NULL;
    }
    else
    {
        newNode->nxtAddress=start;//update next address of previous Node and set the address of next node to NULL
        newNode->preAddress=NULL;
        preNode=start;
        preNode->preAddress=newNode;
        start=newNode;//Update address of the head of linked list

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
    if(start==NULL)//condition for first node same as create first function
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
        while(preNode->nxtAddress!=NULL)//get the address of the last node
        {
            preNode=preNode->nxtAddress;
        }
        preNode->nxtAddress=newNode;//updating next node address of the last node
        newNode->preAddress=preNode;//updating previous address of the new node
        newNode->nxtAddress=NULL;//updating next address of the new node
        printf("Enter a New Data >>> : ");
        scanf("%d",&data);
        printf("\n");
        newNode->data=data;
    }
}
void createLoc()
{
    int data,nodes=1,location,i=1;//nodes represent no of nodes are available and location for get the location of new Node
    node *newNode,*preNode,*temp;;
    newNode=(node*) malloc(sizeof(node));
    if(start==NULL)//if we have not created any node than by node will created at first position
    {
        printf("Only First Position is Available\n\n");
        start=newNode;
        printf("Enter a New Data >>> : ");
        scanf("%d",&data);
        newNode->data=data;
        newNode->nxtAddress=NULL;
        newNode->preAddress=NULL;
    }
    else
    {
        preNode=start;
        while(preNode->nxtAddress!=NULL)//To know the no of nodes are available
        {
            nodes++;
            preNode=preNode->nxtAddress;
        }
        printf("There are %d nodes Are Available \n",nodes);
        display();//display all the available nodes data
        printf("Enter Location where you want to create a new Node : ");
        scanf("%d",&location);
        printf("\n\n");
        if(location<=nodes)//Condition for valid Location
        {
            preNode=start;
            if(location==1)
            {
                //Update th address of first node and also update head of the linked list
                newNode->nxtAddress=start;
                newNode->preAddress=NULL;
                printf("Enter a New Data >>> : ");
                scanf("%d",&data);
                newNode->data=data;
                start=newNode;
            }
            else
            {
                while(i!=location-1)
                {
                    preNode=preNode->nxtAddress;//get the address of node just before the given ocation
                    i++;
                }
                printf("Enter a New Data >>> : ");
                scanf("%d",&data);
                printf("\n");
                //update the address of the new node
                temp=preNode->nxtAddress;
                preNode->nxtAddress=newNode;//Update the next node address of the previous node
                newNode->preAddress=preNode;//update the previous node address of the new node
                newNode->data=data;
                newNode->nxtAddress=temp;//update the nest node address of the new node
                temp->preAddress=newNode;//update the previous node address of the node just after the newNode
            }
        }
        else
        {
            printf("Given Location is Not a Valid Location Please Enter a Valid Location\n\n");
        }
    }
}
//To perform deletion operation from front of the last Node
void deleteFirst()
{
    node *addPointer;//addPointer will always point to first node of the linked list
    if(start==NULL)
    {
        printf("THERE ARE NOTHING TO DELETE\n\n");
    }
    else
    {
        addPointer=start;
        start=addPointer->nxtAddress;
        free(addPointer);//free the memory occupied by the first Node node
    }
}
void deleteLast()
{
    node *addPointer,*preNode;
    if(start==NULL)
    {
        printf("Linked List Is Empty\n\n");
    }
    else
    {
        addPointer=start;
        preNode=NULL;
        while(addPointer->nxtAddress!=NULL)
        {
            preNode=addPointer;//get the address of the node just before the last node
            addPointer=addPointer->nxtAddress;//get the address of the last node
        }
        if(preNode==NULL)
        {
            free(addPointer);
            start=NULL;
        }
        else
        {
            preNode->nxtAddress=NULL;
            free(addPointer);
        }

    }
}
//to perform deletion operation at any given location
void deleteLoc()
{
    int location,nodes=1,i=1;
    node *preNode,*locNode,*temp;
    if(start==NULL)// Condition if have empty list
    {
        printf("There are no any Data Available \n\n ");
    }
    else
    {
        locNode=start;
        while(locNode->nxtAddress!=NULL)//just count the nos of node available
        {
            nodes++;
            locNode=locNode->nxtAddress;
        }
        display();
        printf("Thre are %d Nodes Are Available \n",nodes);
        printf("Enter Location Which you want to Delete >>> : ");
        scanf("%d",&location);
        printf("\n");
        if(location<=nodes)//check for valid location
        {
            locNode=start;//initialize locNode with start and preNode with null
            preNode=NULL;
            if(location==1)
            {
                start=locNode->nxtAddress;//update head of the linked list with next node
                free(locNode);
            }
            else
            {
                while(i!=location)//getting the address of the node for a particular  position and address of node just before this node
                {
                    preNode=locNode;
                    locNode=locNode->nxtAddress;
                    i++;
                }
                preNode->nxtAddress=locNode->nxtAddress;//updating address of the nodes or filling the gap between the nodes
                temp=locNode->nxtAddress;
                if(temp==NULL)//if have last or first node
                {
                    free(locNode);
                }
                else
                {
                    temp->preAddress=preNode;
                    free(locNode);
                    printf("After while Loop\n\n");
                }
            }
        }
        else
        {
            printf("Please Enter a Valid Location ");
        }
    }
}
//display all the content avilable in linked list
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
