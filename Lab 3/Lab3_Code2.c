//Lab 3
//Code 2
//Q2.Write a C program to define a student structure with the data members to store name, roll no and grade of the student. Also write the required functions
//to read, display, and sort student information according to the roll number of the student. All the member functions will have array of objects as arguments.
#include <stdio.h>
#include <string.h>
struct Student
{
    char Name[50];
    int Roll_No;
    char Grade;
};
void Read(struct Student arr[],int n)
{
   for(int i=0;i<n;i++)
    {
        printf("Enter the Roll Number for Student %d:",i+1);
        scanf("%d",&arr[i].Roll_No);
        getchar();
        printf("Enter the Name for Student %d:",i+1);
        gets(arr[i].Name);
        printf("Enter the Grade for Student %d:",i+1);
        scanf(" %c",&arr[i].Grade);
    }
}
void Display(struct Student arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("The information of student %d is as follows:\n",i+1);
        printf("Student %d's Roll Number is %d.\n",i+1,arr[i].Roll_No);
        printf("Student %d's Name is %s.\n",i+1,arr[i].Name);
        printf("Student %d's Grade is %c.\n",i+1,arr[i].Grade);
    }
}
void Sort(struct Student arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (arr[j].Roll_No>arr[j+1].Roll_No)
            {
                struct Student temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void main()
{
    int n;
    printf("Enter the number of students:");
    scanf("%d",&n);
    struct Student arr[n];
    Read(arr,n);
    Display(arr,n);
    Sort(arr,n);
    printf("The sorted information according to the Roll Number of the Students is:\n");
    Display(arr,n);
}
