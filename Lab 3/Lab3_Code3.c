//Lab 3
//Code 3
//Q3.Define a structure Student with the following members:
//char name [50] – to store student name as a string
//int roll_no – to store roll number
//float marks – to store marks
//Write a C program that:
//i. Reads the details of ‘n’ students using a function that uses pointer to structure as an argument.
//ii. Displays the details of all students using a separate function.
//iii. Finds and displays the student with the highest marks using pointer-based access.
#include <stdio.h>
struct Student
{
    char name[50];
    int roll_no;
    float marks;
};
void Read(struct Student *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the Roll Number for Student %d:",i+1);
        scanf("%d",&(arr+i)->roll_no);
        getchar();
        printf("Enter the Name for Student %d:",i+1);
        gets((arr+i)->name);
        printf("Enter the Marks for Student %d:",i+1);
        scanf(" %f",&(arr+i)->marks);
    }
}
void Display(struct Student *arr,int n)
{
    for (int i=0;i<n;i++)
    {
        printf("The information of student %d is as follows:\n",i+1);
        printf("Student %d's Roll Number is %d.\n",i+1,(arr+i)->roll_no);
        printf("Student %d's Name is %s.\n",i+1,(arr+i)->name);
        printf("Student %d's Marks are %.2f.\n",i+1,(arr+i)->marks);
    }
}
void HighestMarks(struct Student *arr,int n)
{
    float *temp_marks=&(arr->marks);
    char temp_name[50];
    int temp_rollno=arr->roll_no;
    strcpy(temp_name,arr->name);
    for (int i=0;i<n;i++)
    {
        if (*temp_marks< (arr+i)->marks)
        {
            temp_marks=&((arr+i)->marks);
            strcpy(temp_name,(arr+i)->name);
            temp_rollno=(arr+i)->roll_no;
        }
    }
    printf("The student with the highest marks is:\n");
    printf("Name:%s\n",temp_name);
    printf("Roll Number:%d\n",temp_rollno);
    printf("Marks:%.2f",*temp_marks);
}
void main()
{
    int n;
    printf("Enter the number of students:");
    scanf("%d",&n);
    struct Student arr[n];
    Read(arr,n);
    Display(arr,n);
    HighestMarks(arr,n);
}
