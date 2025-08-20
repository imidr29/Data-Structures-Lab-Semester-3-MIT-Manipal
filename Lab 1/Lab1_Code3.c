//Lab 1
//Code 3
//Q3.Write a C program to sort a given list of elements using:
//i.)Bubble Sort
//ii.)Selection Sort
//iii.)Insertion Sort
#include <stdio.h>
void main()
{
    int n,temp;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    /*for (int i=0;i<n;i++) //Bubble Sort
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
        }
    }*/
    /*for (int i=0;i<n;i++) //Selection Sort
    {
        for (int j=i+1;j<n;j++)
        {
            if (arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }*/
    for (int i = 1; i < n; i++) //Insertion Sort
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j + 1]=arr[j];
            j-=1;
        }
        arr[j + 1]=key;
    }
    printf("The sorted array is:");
    for (int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

