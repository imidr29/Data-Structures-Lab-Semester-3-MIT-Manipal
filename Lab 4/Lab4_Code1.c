//Lab 4
//Code 1
//Q1.Write a menu-driven C program using structures to implement the following operations on a singly linked list:
//1.Insert an element before another specified element in the list (Example: Insert 10 before 25)
//2.Insert an element after another specified element in the list(Example: Insert 40 after 25)
//3.Delete a specified element from the list (Example: Delete node containing 15)
//4.Traverse the list and display all elements
//5.Reverse the linked list (Modify the links such that the list is reversed)
//6.Sort the list in ascending order (Using Bubble Sort or any appropriate algorithm on linked list)
//7.Delete every alternate node in the list (Starting from the second node)
//8.Insert an element into a sorted linked list while maintaining the sorted order(Example: Insert 28 into a list that is already sorted)
//REQUIREMENTS:Use dynamic memory allocation (malloc/free) for node creation and deletion.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node //This is the definition of a Node of a Singly Linked List,ie a data member,and a pointer to the next Node.A Node is defined by a structure(obvious once you see it.)
{
    int data;
    struct Node* fptr;
}NodeVar; //Use typedef so that we don't have to use struct Node* again and again.
NodeVar* NewNode(int data) //This is the creation of a new node.Note the difference between definition and creation.We need the data member as a parameter,and inside,we define the node pointer to access
{                          //That node and assign the data member,and the next node's pointer.
    NodeVar* ptr_temp=(NodeVar*)malloc(sizeof(NodeVar));
    if (!ptr_temp)
    {
        printf("Memory allocation has failed.");
        exit(1);
    }
    ptr_temp->data=data;
    ptr_temp->fptr=NULL;
    return ptr_temp;
}
NodeVar* InsertNode(NodeVar* headptr,int data)  //This is inserting in order in a Linked List.
{
    NodeVar* newnodeptr=NewNode(data);
    if (headptr==NULL)
    {
        headptr=newnodeptr;
    }
    else
    {
        NodeVar* current=headptr;
        while (current->fptr!=NULL)
        {
            current=current->fptr;
        }
        current->fptr=newnodeptr;
    }
    return headptr;
}
NodeVar* InsertBeforeElement(NodeVar* headptr,int before_element,int new_element)
{
    int pos=1;
    NodeVar* temp=headptr;
    NodeVar* prevptr=NULL;
    if (temp==NULL)//If the linked list is empty.
    {
        printf("The linked list in question is empty.");
        return headptr;
    }
    if (temp->fptr==NULL) //If the linked list contains only the headptr. I create a node for the new element.Then I have to make it the head node.And head->next=temp.
    {
        NodeVar* newheadptr=NewNode(new_element);
        newheadptr->fptr=headptr;
        headptr=newheadptr; //Important.Otherwise Infinite loop.
    }
    //The linked list has more than one element.
    //I should keep track of the position using a variable.Then, when it reaches that position. I have to insert a new node and shift the pointers.
    while ( temp->fptr!=NULL && pos!=before_element)
    {
        prevptr=temp;
        temp=temp->fptr;
        pos++;
    }
    NodeVar* newheadptr=NewNode(new_element);
    prevptr->fptr=newheadptr;
    newheadptr->fptr=temp;
    return headptr;
}
NodeVar* InsertAfterElement(NodeVar* headptr,int after_element,int new_element)
{
    //If it has only one element.
    //More than one element.
    int pos=1;
    NodeVar* temp=headptr;
    NodeVar* afterptr=NULL;
    if (temp==NULL)//If the linked list is empty.
    {
        printf("The linked list in question is empty.");
        return headptr;
    }
    if (temp->fptr==NULL) //If the linked list contains only the headptr. I just set the fptr of head to new.
    {
        NodeVar* newheadptr=NewNode(new_element);
        temp->fptr=newheadptr;
        newheadptr->fptr=NULL;
    }
    //The linked list has more than one element.
    //I should keep track of the position using a variable(pos).Then, I keep track of the pointer and the one after it.
    while ( temp->fptr!=NULL && pos!=after_element)
    {
        temp=temp->fptr;
        afterptr=temp->fptr;
        pos++;
    }
    NodeVar* newheadptr=NewNode(new_element);
    temp->fptr=newheadptr;
    newheadptr->fptr=afterptr;
    return headptr;
}
NodeVar* DeleteNode(NodeVar* headptr)
{
    NodeVar* temp=headptr;
    NodeVar* prevptr=NULL; //To keep track of the previous element to the element to be deleted.
    if (temp==NULL) //If Linked List is empty.
    {
        printf("Cannot delete an element from an empty linked list.\n");
        return headptr;
    }
    int del_ele;
    printf("Enter the element you want to delete from the linked list:");
    scanf("%d",&del_ele);
    if (del_ele==temp->data) //Case 1:If the element to be deleted is the first element of the linked list.I just delete the element and free the pointer.
    {
        headptr=headptr->fptr;
        free(temp);
        return headptr;
    }
    while (temp!=NULL && temp->data!=del_ele)//Case 2:The element is in the middle of the linked list.
    {
        prevptr=temp; //Keeps track of this one.
        temp=temp->fptr;//And here we change this to the next one.
    } //After this loop, the temporary pointer points to the element after the deletion element.The previous pointer points to the current one.
    //So, if I need to delete this node, I need to free the temporary pointer, and before that make the previous pointer point to the one after the temp.
    if (temp==NULL) 
    {
        printf("The given element was not found in the linked list.\n");
        return headptr;
    }
    prevptr->fptr=temp->fptr;
    free(temp);
    return headptr;
}
void DisplayElements(NodeVar* headptr) //Lets see.I need to go through the list right?So,I need the head pointer.I will also need a current/temporary pointer to traverse through the list.
//If that pointer is null,I stop.Otherwise,I initialise it to head,and while not null,I display the data from the current pointer,then make it point to the forward pointer.
{
    if (headptr==NULL)
    {
        printf("The linked list in question is an empty one.\n");
        return;
    }
    NodeVar* current=headptr;
    int k=1;
    printf("The elements of the linked list are:\n");
    while (current!=NULL)
    {
        printf("The element at position %d is %d.\n",k,current->data);
        current=current->fptr;
        k++;
    }
}
NodeVar* ReverseLinkedList(NodeVar* headptr)
{
    NodeVar* temp=headptr;
    NodeVar* backptr=NULL;
    NodeVar* newfptr=NULL;
    if (temp==NULL)//If the linked list is empty.
    {
        printf("The linked list in question is empty.");
        return headptr;
    }
    if (temp->fptr==NULL) //If the linked list contains only one element.
    {
        printf("The linked list in question contains a single element, which is %d.\n",temp->data);
        return headptr;
    }
    while (temp!=NULL) // I define a new backptr and swap pointers using a temp, but I also need one pointer to move forward.
    {
        newfptr=temp->fptr;
        temp->fptr=backptr;
        backptr=temp;
        temp=newfptr;
    }
    printf("The Linked List is successfully reversed.");
    DisplayElements(backptr);
    return backptr;
}
void SortLinkedList(NodeVar* headptr)
{
    NodeVar* temp;
    NodeVar* endptr = NULL;
    int swapped;
    if (headptr == NULL)
        return;
    while (1)
    {
        swapped = 0;
        temp = headptr;
        while (temp->fptr != endptr)
        {
            if (temp->data > temp->fptr->data)
            {
                int tempData = temp->data;
                temp->data = temp->fptr->data;
                temp->fptr->data = tempData;
                swapped = 1;
            }
            temp = temp->fptr;
        }
        if (!swapped)
            break;
        endptr = temp;
    }
    DisplayElements(headptr);
}
NodeVar* DeleteAlternateNodes(NodeVar* headptr)
{
    NodeVar* temp = headptr;
    if (temp == NULL || temp->fptr == NULL)
        return headptr;
    NodeVar* prevptr = temp;
    temp = temp->fptr;
    while (temp != NULL && temp->fptr != NULL)
    {
        prevptr->fptr = temp->fptr;
        free(temp);
        prevptr = prevptr->fptr;
        temp = prevptr->fptr;
    }
    DisplayElements(headptr);
    return headptr;
}
NodeVar* InsertIntoSorted(NodeVar* headptr, int data)
{
    NodeVar* newnodeptr = NewNode(data);
    if (headptr == NULL || headptr->data >= data)
    {
        newnodeptr->fptr = headptr;
        headptr = newnodeptr;
        return headptr;
    }
    NodeVar* current = headptr;
    while (current->fptr != NULL && current->fptr->data < data)
        current = current->fptr;
    newnodeptr->fptr = current->fptr;
    current->fptr = newnodeptr;
    return headptr;
}
//To do: 5,6,7,8
int main()
{
    NodeVar* headptr=NULL;
    int choice,data,loopbreaker=1;
    printf("Enter 0 to append an element into the linked list.\n");
    printf("Enter 1 to insert an element into the linked list before a certain element.\n");
    printf("Enter 2 to insert an element into the linked list after a certain element.\n");
    printf("Enter 3 to delete an element from the linked list.\n");
    printf("Enter 4 to display all the elements in the linked list.\n");
    printf("Enter 5 to reverse the linked list and print the updated list.\n");
    printf("Enter 6 to sort the linked list in ascending order.\n");
    printf("Enter 7 to delete every alternate node from the linked list starting from the second node.\n");
    printf("Enter 8 to insert an element into an already sorted linked list.\n");
    printf("Enter 9 to successfully exit.\n");
    printf("\n");
    while (loopbreaker)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
            {
                printf("Enter the element you want to insert into the linked list:");
                scanf("%d",&data);
                headptr=InsertNode(headptr,data);
                break;
            }
            case 1: //Answer of Part 1.
            {
                printf("Enter the position of the node before which you want to enter the new element:");
                int before_element,new_element;
                scanf("%d",&before_element);
                printf("Enter the new element:");
                scanf("%d",&new_element);
                headptr=InsertBeforeElement(headptr,before_element,new_element);
                break;
            }
            case 2://Answer of Part 2.
            {
                printf("Enter the position of the node after which you want to enter the new element:");
                int after_element,new_element;
                scanf("%d",&after_element);
                printf("Enter the new element:");
                scanf("%d",&new_element);
                headptr=InsertAfterElement(headptr,after_element,new_element);
                break;
            }
            case 3: //Answer of Part 3.
            {
                headptr=DeleteNode(headptr);
                DisplayElements(headptr);
                break;
            }
            case 4: //Answer of Part 4.
            {
                DisplayElements(headptr);
                break;
            }
            case 5: //Answer of Part 5.
            {
                headptr=ReverseLinkedList(headptr);
                break;
            }
            case 6: //Answer of Part 6.
            {
                SortLinkedList(headptr);
                break;
            }
            case 7: //Answer of Part 7.
            {
                headptr=DeleteAlternateNodes(headptr);
                break;
            }
            case 8: //Answer of Part 8.
            {
                printf("Enter the element you want to insert in the sorted list:");
                int sortedelement;
                scanf("%d",&sortedelement);
                headptr=InsertIntoSorted(headptr,sortedelement);
                break;
            }
            case 9: //Exiting.
            {
                loopbreaker=0;
                printf("Successfully exited.");
                break;
            }
            default:
            {
                printf("Invalid Choice.\n");
            }
        }
    }
    return 0;
}

