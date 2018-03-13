//Here we are implementing Linked list
#include<stdio.h>
#include<stdlib.h>  // library which can be used for malloc and calloc functions
#include<conio.h>
void createFirst();  //Function to create node in first
void createLast();//function to create node in last
void createLoc();// Function to create node at any location
//void deleteFirst();// Function to delete node from front
//void deleteLast();//Function to delete node from last
//void deleteLoc();//function to delete node at any location
void display();// function to display nodes
typedef struct node
{
    int n;
    struct node *add;
}node;
node *start=NULL;
void main()
{
    int ip;
    printf("================YOU HAVE FOLLOWING CHOICES================\n");
    while(1)
    {
        printf("1. Create Node at First.\n");
        printf("2. Create Node at Last.\n");
        printf("3. Create Node at Location.\n");
        printf("4. Delete Node at First.\n");
        printf("5. Delete Node at Last.\n");
        printf("6. Delete Node at Location.\n");
        printf("7 Display.\n");
        printf("8. Exit.\n\n");
        printf("Enter Your Choice Here : ");
        scanf("%d",&ip);
        switch(ip)
        {
            case 1 :
                createFirst();
                break;
            case 2:
                createLast();
                break;
            case 3 :
                createLoc();
                break;
            /*case 4 :
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
                printf("Wrong Choice Please Try Again\n");

        }
    }

}
createFirst()
{
    int data;//Variable which store data into the linked list
    node *newnode;//Creating a new node
    newnode=(node*) malloc(sizeof(node));// Location of new node is given here
    if(start==NULL)// If we have not stored anything in linked list
    {
        start=newnode;// start always point to first node
        printf("Enter data : ");
        scanf("%d",&data);
        printf("\n");
        newnode->n=data;//storing data into new node
        newnode->add=NULL;// Address of next node blank for first node
    }
    else
    {
        newnode->add=start;//creating first node  before if we have already nodes are avilable in front nodes
        start=newnode;// Setting start pointer to the first node
        printf("Enter data : ");
        scanf("%d",&data);
        printf("\n");
        newnode->n=data;
    }
}
void createLast()
{
    int data; // Data which we have to store
    node *newNode,*preNode; //newNode for creating new node and preNode for previous node
    newNode=(node*) malloc(sizeof(node));// Location of new node
    if(start==NULL)//if we do not have any data in linked list
    {
        start=newNode;//Initialize start with first node
        printf("Enter Data : ");
        scanf("%d",&data);
        printf("\n");
        newNode->n=data;
        newNode->add=NULL;
    }
    else
    {
        preNode=start;//Initialize previous node with first node
        while(preNode->add!=NULL)// Pointing to the address of all avilable nodes
        {
            preNode=preNode->add;// Finding address of last node or getting address of last node
        }
        preNode->add=newNode;//storing of next node address to the last node
        printf("Enter Data : ");
        scanf("%d",&data);
        printf("\n");
        newNode->n=data;// storing data into last node
        newNode->add=NULL;// Address of newly created last node
    }
}
void createLoc()
{
    int location,data,nodes=1,i=1;//location is for get the position where we want to add node
    node *newNode, *preNode;
    newNode=(node*) malloc(sizeof(node));
    if(start==NULL)//when we does not have any node than by default location will be first
    {
        printf("There are only First Location Avilable\n");
        start=newNode;
        printf("Enter Data : ");
        scanf("%d",&data);
        printf("\n");
        newNode->n=data;
        newNode->add=NULL;
    }
    else
    {
        preNode=start;//for find no of avilable nodes in linked list
        while(preNode->add!=NULL)
        {
            nodes++;
            preNode=preNode->add;
        }
        printf("There are %d Nodes avilable \n",nodes);
        display();// display all the data for convenince
        printf("Enter Location where you want to create node : ");
        scanf("%d",&location);// Get the location where we want to add node
        if(location<=nodes)
        {
            preNode=start;
            while(i!=location-1)
            {
                preNode=preNode->add;// Get the address of the node avilable before the given location
                i++;
            }
            newNode->add=preNode->add;//Now address of new node will be the address of the avilable node after location
            preNode->add=newNode;
            printf("Enter Data : ");
            scanf("%d",&data);
            printf("\n");
            newNode->n=data;

        }
        else
        {
            printf("Location is not a valid Location Please Enter Carefully\n");
        }

    }
}
void display()
{
    node *addPointer;// addPointer is variable which is used for pointing the address of all avilable nodes
    if(start==NULL)//if we do not have any data in linked list
    {
        printf("There are no any data to Display\n");
    }
    else
    {
        addPointer=start;//Initialize addPointer with the address of first node
        printf("================YOUR DATA================\n");
        while(addPointer!=NULL)//Pointing to address of all avilable nodes
        {
            printf("%d  ",addPointer->n);
            addPointer=addPointer->add;//Updating addPointer with address of avilable nodes
        }
        printf("\n\n");
    }
}
