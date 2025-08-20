//Lab 5
//Code 2
//Q2.Write a program to concatenate two doubly linked lists X1 and X2.After Concatenation,X1 should point to the first node of the resulting list.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* fptr;
    struct Node* bptr;
}NodeVar;
NodeVar* NewNode(int data)
{
    NodeVar* tempptr=(NodeVar*)malloc(sizeof(NodeVar));
    if (!tempptr)
    {
        printf("Memory allocation has failed.");
        exit(1);
    }
    tempptr->data=data;
    tempptr->fptr=NULL;
    tempptr->bptr=NULL;
    return tempptr;
}
NodeVar* AppendNode(NodeVar* headptr,int append_element) //Appending at the Rear End.
{
    NodeVar* newnodeptr=NewNode(append_element);
    NodeVar* current=headptr;
    if (headptr==NULL) //If the Linked List is empty.
    {
        headptr=newnodeptr;
        return headptr;
    }
    while (current->fptr!=NULL) //General Case.
    {
        current=current->fptr;
    }
    current->fptr=newnodeptr;
    newnodeptr->bptr=current;
    return headptr;
}
NodeVar* ForwardTraverse(NodeVar* headptr)
{
    int pos=1;
    NodeVar* current=headptr;
    if (headptr==NULL) //If the Linked List is empty.
    {
        printf("The linked list is empty.");
        return headptr;
    }
    while (current!=NULL) //General Case.
    {
        printf("The element at position %d is %d.\n",pos,current->data);
         if (current->fptr==NULL)
        {
            return current;
        }
        current=current->fptr;
        pos++;
    }
    return headptr;
}
NodeVar* Concatenator(NodeVar* headptr1,NodeVar* headptr2)
{
    int pos=1;
    NodeVar* current=headptr1;
    if (headptr1==NULL && headptr2!=NULL) //If the Linked List is empty.
    {
        printf("The first linked list is empty.");
        return headptr2;
    }
    else if (headptr1!=NULL && headptr2==NULL) //If the Linked List is empty.
    {
        printf("The second linked list is empty.");
        return headptr1;
    }
    else if (headptr1==NULL && headptr2==NULL)
    {
        printf("Both the linked lists are empty.");
    }
    else
    {
        while (current->fptr!=NULL)
        {
            current=current->fptr;
        }
        current->fptr=headptr2;
        headptr2->bptr=current;
    }
    return headptr1;
}
int main()
{
    NodeVar* x1=NULL;
    NodeVar* x2=NULL;
    NodeVar* temp=NULL;
    int choice,element;
    printf("Enter 1 to append into the first doubly linked list.\nEnter 2 to append into the second doubly linked list.\nEnter 0 to stop.\n");
    while (1)
    { 
        printf("Enter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            printf("Enter the element you want to append into the first doubly linked list:");
            scanf("%d",&element);
            x1=AppendNode(x1,element);
        }
        else if (choice==2)
        {
            printf("Enter the element you want to append into the second doubly linked list:");
            scanf("%d",&element);
            x2=AppendNode(x2,element);
        }
        else if (choice==0)
        {
            printf("Successfully exited.\n");
            break;
        }
        else
        {
            printf("Invalid choice.Please enter again.\n");
        }
    }
    printf("The elements of the first doubly linked list are:\n");
    temp=ForwardTraverse(x1);
    printf("The elements of the second doubly linked list are:\n");
    temp=ForwardTraverse(x2);
    printf("The elements of the concatenated doubly linked list are:\n");
    temp=ForwardTraverse(Concatenator(x1,x2));
    return 0;
}