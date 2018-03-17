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
int findMin(node *root);
int findMax(node *root);
void main()
{
    node *root=NULL;//declare as local variable store the address of the roots of the tree
    int ip,data,min,max;//ip is used for switch the operation and data will take all the data from the user for which we have to perform the operation
    bool result;//boolean variable which hold the result of search operation
    while(1)
    {
        printf("================Following Operations are Available================\n\n");
        printf("1. Insertion\n");
        printf("2. Search\n");
        printf("3. Deletion\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Exit\n\n");
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
                scanf("%d",&data);//get data from the user
                printf("\n");
                printf("Searching elements in tree...................\n");
                result=search(root,data);//call to search function which will return true or false
                if(result==true)
                {
                    printf("%d Found in given BST\n",data);
                }
                else
                {
                    printf("%d Not Found in Given BST\n");
                }
                break;
            case 4://to find minimum no is available in tree
                printf("Finding Minimum.....................\n");
                min=findMin(root);
                printf("Minimum element in tree is : %d\n\n",min);
                break;
            case 5://to find maximum no is available in tree
                printf("Finding Maximum.....................\n");
                max=findMax(root);
                printf("Maximum no in this BST is : %d\n",max);
                break;
            case 6://to exit all operations
                exit(0);
            default :
                printf("Wrong Choice Please Try Again\n\n");
        }
    }
}
node *insert(node *root,int data)//insert function in which argument root is for getting address of node and data stores the value which is given by the users
{
    if(root==NULL)//to create first node as well as to create every new node
    {
        root=getNewNode(data);//make a new node with left node and right node address equal to NULL
    }
    else
    {
        if(data<=root->data)//all the element which is smaller or equal to the data will store at left side of the node
        {
            root->leftNode=insert(root->leftNode,data);//due to recursion it will point till the left address of the node becomes null after that node will created
        }
        else
        {
            root->rightNode=insert(root->rightNode,data);//all the element which is smaller or equal to the data will store at left side of the node
        }
    }
    return root;
}
node *getNewNode(int data)//to create a new node
{
    node *newNode;
    newNode=(node*) malloc(sizeof(node));
    newNode->data=data;//store data into the newly created node
    newNode->leftNode=NULL;//set left node address and right node address to the null
    newNode->rightNode=NULL;
    return newNode;//return address of the new node;
}
bool search(node *root,int data)//to perform search operation
{
    if(root==NULL)//point to the first node to the all available nodes with given address of the node
    {
        return false;
    }
    else
    {
        if(data==root->data)//if data found return true
        {
            return true;
        }
        else if(data<=root->leftNode)//if data is smaller than continue search operation in left side of the node
        {
            return search(root->leftNode,data);
        }
        else//if data is larger than continue search operation in right side of the tree
        {
            return search(root->rightNode,data);
        }
    }

}
int findMin(node *root)//to find the minimum element available in tree
{
    if(root==NULL)//if we have a empty tree
    {
        printf("Error : BST is empety right now\n\n");
    }
    else
    {
        if(root->leftNode==NULL)//point to the left child of the tree because all the smallest elements are presents here
        {
            return root->data;//
        }
    }
    return findMin(root->leftNode);//find till the last node available in left side of the tree
}
int findMax(node *root)//to find maximum element available in the tree
{
    if(root==NULL)//if we have any empty list
    {
        printf("Error : BST is empty right now\n\n");
    }
    else
    {
        if(root->rightNode==NULL)//point to the right side of the node till last node set null if found
        {
            return root->data;
        }
        else
        {
            findMax(root->rightNode);//keep pointing to the next node available in the right side of the node
        }
    }
}
