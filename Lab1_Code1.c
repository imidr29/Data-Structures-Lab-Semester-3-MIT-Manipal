//Lab 1
//Code 1
//Q1.Given an array of n integers and a key element, write a C program to search the element using linear search.
#include <stdio.h>
int LinearSearch(int arr[],int n,int key)
    {
        for (int i=0;i<n;i++)
        {
            if (arr[i]==key)
            {
                return i;
            }
        }
        return -1;
    }
void main()
{
    int n,key;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search:");
    scanf("%d",&key);
    int check=LinearSearch(arr,n,key);
    if (check==-1)
    {
        printf("The given element is not in the array.");
    }
    else
    {
        printf("The element was found at position %d.",check+1);
    }
}
