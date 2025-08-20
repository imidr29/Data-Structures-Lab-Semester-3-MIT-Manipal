//Lab 2
//Code 2
//Q2.Write a recursive C program to implement Selection Sort using pointers.
//1.The recursive function should sort the array using the Selection Sort algorithm.
//2.Access and manipulate the array elements using pointers (i.e., avoid using arr[i] style directly).
//3.The program should read the array from the user in the main function, call the recursive sorting function, and display the sorted array.
#include <stdio.h>
#include <stdlib.h>
void Swap(int *a,int *b) //Function to swap two integers using pointers
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void RecursiveSelectionSortUsingPointers(int *arr, int start, int n) //Recursive function to perform selection sort using pointers
{
    if (start>=n-1)
    {
        return;
    }
    int minIndex=start; // Find the minimum element in the unsorted part
    for (int i=start+1;i<n;i++)
    {
        if (*(arr+i)<*(arr+minIndex))
        {
            minIndex=i;
        }
    }
    if (minIndex!=start)   // Swap if a smaller element is found
    {
        Swap(arr+start,arr+minIndex);
    }
    RecursiveSelectionSortUsingPointers(arr,start+1,n); // Recursive call for the remaining array
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
    RecursiveSelectionSortUsingPointers(arr,0,n);
    printf("The sorted array is:\t");
    for (int i=0;i<n;i++)
    {
        printf("%d\t",*(arr+i)); //Printing the array elements using the base pointer as reference.
    }
}
