#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
//Definition of a single node
typedef struct node
{
    int data;//Store all the data provided by the user
    struct node *leftNode,*rightNode;//left Node for pointing left child and rightNode for pointing right child
}node;
node *insert(node *root,int data);//to insert element in tree
node *getNewNode(int data);//to create new node with give data
bool search(node *root,int data);//to perform search operation
void main()
{
    node *root=NULL;//declare as local variable store the address of the roots of the tree
    int ip,data;//ip is used for switch the operation and data will take all the data from the user for which we have to perform the operation
    bool result;//boolean variable which hold the result of search operation
    while(1)
    {
        printf("================Following Operations are Available================\n\n");
        printf("1. Insertion\n");
        printf("2. Search\n");
        printf("3. Deletion\n");
        printf("4. Exit\n\n");
        printf("Enter Your Choice : ");
        scanf("%d",&ip);
        printf("\n");
        switch(ip)
        {
            case 1://to perform insertion operation
                printf("Enter a New Data : ");
                scanf("%d",&data);
                printf("\n");
                root=insert(root,data);
                break;
            case 2://to perform search operation
                printf("Enter No which you want to find : ");
                scanf("%d",&data);
                printf("\n");
                result=search(root,data);
                if(result==true)
                {
                    printf(">>>>>>>>>>> %d Found\n",data);
                }
                else
                {
                    printf(">>>>>>>>>>>> %d Not Found\n");
                }
                break;
            case 4:
                exit(0);
            default :
                printf("Wrong Choice Please Try Again\n\n");
        }
    }
}
node *insert(node *root,int data)
{
    if(root==NULL)
    {
        root=getNewNode(data);
    }
    else
    {
        if(data<=root->data)
        {
            root->leftNode=insert(root->leftNode,data);
        }
        else
        {
            root->rightNode=insert(root->rightNode,data);
        }
    }
    return root;
}
node *getNewNode(int data)
{
    node *newNode;
    newNode=(node*) malloc(sizeof(node));
    newNode->data=data;
    newNode->leftNode=NULL;
    newNode->rightNode=NULL;
    return newNode;
}
bool search(node *root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else
    {
        if(data==root->data)
        {
            return true;
        }
        else if(data<=root->leftNode)
        {
            return search(root->leftNode,data);
        }
        else
        {
            return search(root->rightNode,data);
        }
    }

}

