//Lab 2
//Code 3
//Q3.Implement a C program to read, display, and find the product of two matrices using functions with appropriate parameters.
//1.The matrices must be created using dynamic memory allocation (malloc or calloc).
//2.Access matrix elements using array dereferencing (i.e., *(*(mat + i) + j) style).
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int m,n,p,q;
    printf("Enter the number of rows in the first matrix:");
    scanf("%d",&m);
    printf("Enter the number of columns in the first matrix:");
    scanf("%d",&n);
    int **arr1=malloc(m*sizeof(int*));
    for (int i=0;i<m;i++)
    {
        arr1[i]=malloc(n*sizeof(int));
    }
    printf("Enter the elements of the first matrix:");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter the number of rows in the second matrix:");
    scanf("%d",&p);
    printf("Enter the number of columns in the second matrix:");
    scanf("%d",&q);
    int **arr2=malloc(p*sizeof(int*));
    for (int i=0;i<p;i++)
    {
        arr2[i]=malloc(q*sizeof(int));
    }
    printf("Enter the elements of the second matrix:");
    for (int i=0;i<p;i++)
    {
        for (int j=0;j<q;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    int **arr_mul=malloc(m*sizeof(int*)); //Declaring the product matrix dynamically.
    for (int i=0;i<m;i++)
    {
        arr_mul[i]=malloc(q*sizeof(int));
    }
    int sum;
    for (int i=0;i<m;i++)
    {
        for (int j=0; j<n;j++)
        {
            sum=0;
            for (int k=0;k<n;k++)
            {
              sum+=((*(*(arr1+i)+k))*(*(*(arr2+k)+j)));
            }
            *(*(arr_mul+i)+j)=sum;
        }
    }
    printf("The product matrix is:\n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<q;j++)
        {
            printf("%d\t",*(*(arr_mul+i)+j));
        }
        printf("\n");
    }
}
