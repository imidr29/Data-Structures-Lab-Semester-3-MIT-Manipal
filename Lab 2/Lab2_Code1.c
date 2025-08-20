//Lab 2
//Code 1
//Q1.Write a small function to find the smallest element in an array using pointers.In the main function, create a dynamically allocated array, read the values from the
//keyboard, and pass the array to the function.Display the result (smallest element) in the main function.
#include <stdio.h>
#include <stdlib.h>
int SmallestUsingPointers(int *arr,int n)
{
    int smallest=*arr;
    for (int i=0;i<n;i++)
    {
        if (smallest>=(*(arr+i)))
        {
            smallest=*(arr+i); // smallest element in an array.compare across the array with first element,whatever is smaller put it as that element variable.
        }
    }
    return smallest;
}
void main()
{
    int n,*arr;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    if (arr==NULL)
    {
        printf("Memory not allocated.");
    }
    else
    {
        printf("Enter the elements of the array:");
        for (int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
    int temp=SmallestUsingPointers(arr,n);
    printf("The smallest element in the array is %d.",temp);
}
