//Lab 1
//Code 2
//Q2.Given an array of integers, implement binary search to find the position of a given key.
#include <stdio.h>
int BinarySearch(int arr[],int n,int key,int low,int high)
    {
        int mid;
        while (low<=high)
        {
            mid=(low+high)/2;
            if (arr[mid]==key)
            {
                return mid;
            }
            else if (key<arr[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
void main()
{
    int n,key,low=0,high,check;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    high=n-1;
    printf("Enter the array elements:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search:");
    scanf("%d",&key);
    check=BinarySearch(arr,n,key,low,high);
    if (check == -1)
    {
        printf("The given element is not in the array.");
    }
    else
    {
        printf("The element was found at position %d.",check+1);
    }
}
