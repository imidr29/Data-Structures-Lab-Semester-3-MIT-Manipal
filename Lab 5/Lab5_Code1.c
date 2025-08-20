//Lab 5
//Code 1
//Q1.Write a menu-driven C program using structures to implement the following operations on a Doubly Linked List.
//1.Insert an element at the rear end of the list(Append a new node to the end of the list)
//2.Delete an element from the rear end of the list(Remove the last node in the list)
//3.Insert an element at a given position in the list(e.g., Insert at position 3. Positioning starts from 1.)
//4.Delete an element from a given position in the list.
//5.Insert an element after a node containing a specific value(e.g., Insert 40 after 25)
//6.Insert an element before a node containing a specific value(e.g., Insert 10 before 25)
//7.Traverse the list in forward direction(From head to tail)
//8.Traverse the list in reverse direction(From tail to head – i.e., reverse traversal)
#include <stdio.h>
#include <stdlib.h>
typedef struct Node //Definition of a Doubly Linked List.
{
    int data;
    struct Node* fptr;
    struct Node* bptr;
}NodeVar;
NodeVar* NewNode(int data) //Creation of a Doubly Linked List Node.
{
    NodeVar* assignptr=(NodeVar*)malloc(sizeof(NodeVar));
    if (!assignptr)
    {
        printf("Memory allocation has failed.");
        exit(1);
    }
     assignptr->data=data;
     assignptr->fptr=NULL;
     assignptr->bptr=NULL;
     return assignptr;
}
NodeVar* AppendNode(NodeVar* headptr) //Appending at the Rear End.
{
    printf("Enter the element you want to append to the Doubly Linked List:");
    int append_element;
    scanf("%d",&append_element);
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
NodeVar* DeleteRearNode(NodeVar* headptr)
{
    NodeVar* current=headptr;
    NodeVar* prev=NULL;
    if (headptr==NULL) //If the Linked List is empty.
    {
        printf("Cannot delete from an empty linked list.");
        return headptr;
    }
    if (headptr->fptr==NULL && headptr->bptr==NULL) //If the linked list only has one node.
    {
        free(headptr);
        return NULL;
    }
    while (current->fptr!=NULL) //General Case.
    {
        prev=current;
        current=current->fptr;
    }
    //Here, I am at the last node,with its fptr and bptr being available to me.Okay then, I need to free this node up.But, I also need to remove its backptr.Before that, I set the previous fptr to Null.
    prev->fptr=NULL;
    free(current);
    printf("Successfully deleted the rear node.\n");
    return headptr;
}
NodeVar* PositionSpecificInsertion(NodeVar* headptr)
{
    int position,element,counter=1;
    printf("Enter the position where you want to insert the element:");
    scanf("%d",&position);
    printf("Enter the value of the element you want to insert:");
    scanf("%d",&element);
    NodeVar* newnodeptr=NewNode(element);
    NodeVar* current=headptr;
    NodeVar* prev=NULL;
    NodeVar* temp=NULL;
    if (position==1 && headptr==NULL) //If the linked list is empty.
    {
        headptr=newnodeptr;
        return headptr;
    }
    while (current->fptr!=NULL && counter!=position)
    {
        prev=current;
        current=current->fptr;
        counter++;
    }
    prev->fptr=newnodeptr; //Connect previous to new.
    newnodeptr->bptr=prev; //Connect new to previous.
    newnodeptr->fptr=current;//Connect new to current.
    current->bptr=newnodeptr;//Connect current to new.
    return headptr;
}
NodeVar* PositionSpecificDeletion(NodeVar* headptr)
{
    int position,counter=1;
    printf("Enter the position of the element you want to delete:");
    scanf("%d",&position);
    NodeVar* current=headptr;
    NodeVar* prev=NULL;
    if (position==1 && headptr==NULL) //If the linked list is empty.
    {
        printf("Cannot delete from an empty linked list.");
        return headptr;
    }
    while (current->fptr!=NULL && counter!=position)
    {
        prev=current;
        current=current->fptr;
        counter++;
    }
    prev->fptr=current->fptr; //Connecting previous to the one after
    current->fptr->bptr=prev; //One after to the previous one.
    free(current);
    return headptr;
}
NodeVar* ElementInsertionAfterNode(NodeVar* headptr)
{
    int afterele,ele;
    printf("Enter the element after which you want to insert an element:");
    scanf("%d",&afterele);
    printf("Enter the element you want to insert:");
    scanf("%d",&ele);
    NodeVar* current=headptr;
    NodeVar* after=NULL;
    NodeVar* newnodeptr=NewNode(ele);
    if (headptr==NULL)
    {
        headptr=newnodeptr;
        return headptr;
    }
    if (headptr->fptr==NULL && headptr->data==afterele)
    {
        headptr->fptr=newnodeptr;
        return headptr;
    }
    while (current->fptr!=NULL && current->data!=afterele)
    {
        current=current->fptr;
    }
    newnodeptr->fptr=current->fptr; //new to after
    current->fptr->bptr=newnodeptr; //after to new
    current->fptr=newnodeptr; //current to new
    newnodeptr->bptr=current;//new to current
    return headptr;
}
NodeVar* ElementInsertionBeforeNode(NodeVar* headptr)
{
    int beforeele,ele;
    printf("Enter the element before which you want to insert an element:");
    scanf("%d",&beforeele);
    printf("Enter the element you want to insert:");
    scanf("%d",&ele);
    NodeVar* current=headptr;
    NodeVar* prev=NULL;
    NodeVar* newnodeptr=NewNode(ele);
    if (headptr==NULL)
    {
        headptr=newnodeptr;
        return headptr;
    }
    if (headptr->fptr==NULL && headptr->data==beforeele)
    {
        headptr->fptr=newnodeptr;
        return headptr;
    }
    while (current->fptr!=NULL && current->data!=beforeele)
    {
        prev=current;
        current=current->fptr;
    }
    //Okay,grunt work done. Now, I have to insert the newnode.
    prev->fptr=newnodeptr; //Previous to New
    newnodeptr->bptr=prev; //New to Previous
    newnodeptr->fptr=current; //New to Forward
    current->bptr=newnodeptr; //Forward to new
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
NodeVar* BackwardTraverse(NodeVar* tailptr)
{
    int pos=1;
    NodeVar* current=tailptr;
     if (tailptr==NULL) //If the Linked List is empty.
    {
        printf("The linked list is empty.");
        return tailptr;
    }
    while (current!=NULL)
    {
        printf("The element at position %d is %d.\n",pos,current->data);
        current=current->bptr;
        pos++;
    }
    return tailptr;
}
int main()
{
    NodeVar* headptr=NULL;
    NodeVar* temp=NULL;
    int choice,data,loopbreaker=1;
    printf("Enter 1 to append an element into the doubly linked list.\n");
    printf("Enter 2 to delete the rear element from the doubly linked list.\n");
    printf("Enter 3 to insert an element at a given position in the doubly linked list.\n");
    printf("Enter 4 to delete an element at a given position in the doubly linked list.\n");
    printf("Enter 5 to insert an element after the node containing a specific value.\n");
    printf("Enter 6 to insert an element before the node containing a specific value.\n");
    printf("Enter 7 to traverse the doubly linked list in forward direction.\n");
    printf("Enter 8 to traverse the doubly linked list in backward direction.\n");
    printf("Enter 9 to successfully exit.\n");
    while (loopbreaker)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                headptr=AppendNode(headptr);
                break;
            }
            case 2:
            {
                headptr=DeleteRearNode(headptr);
                break;
            }
            case 3:
            {
                headptr=PositionSpecificInsertion(headptr);
                break;
            }
            case 4:
            {
                headptr=PositionSpecificDeletion(headptr);
                break;
            }
            case 5:
            {
                headptr=ElementInsertionAfterNode(headptr);
                break;
            }
            case 6:
            {
                temp=ElementInsertionBeforeNode(headptr);
                break;
            }
            case 7:
            {
                temp=ForwardTraverse(headptr);
                break;
            }
            case 8:
            {
                temp=BackwardTraverse(ForwardTraverse(headptr));//I need to get the tail pointer,otherwise I cannot run the backward traversal.This will also give the
                //forward order.
                break;
            }
            case 9:
            {
                loopbreaker=0;
                printf("Successfully exited.");
                break;
            }
            default:
            {
                printf("Invalid Choice.\n");
                break;
            }
        }
    }
    return 0;
}
