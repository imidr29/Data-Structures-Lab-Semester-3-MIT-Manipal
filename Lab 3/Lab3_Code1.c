//Lab 3
//Code 1
//Q1.Write a program to perform following string operations without using string handling functions:
//a.) length of the string
//b.) string concatenation
//c.) string comparison
//d.) to insert a sub string
//e.) to delete a substring
#include <stdio.h>
#include <string.h>
int LengthofString(char string[])
{
    int len=0;
    while (string[len]!='\0')
    {
        len++;
    }
    return len;
}
void StringConcatenation(char string1[],char string2[])
{
    int len_s1=LengthofString(string1);
    int len_s2=LengthofString(string2);
    char string3[len_s1+len_s2];
    for (int i=0;i<len_s1;i++)
    {
        string3[i]=string1[i];
    }
    for (int i=0;i<len_s2;i++)
    {
        string3[len_s1+i]=string2[i];
    }
    string3[len_s1+len_s2]='\0';
    puts(string3);
}
void StringComparision(char string1[],char string2[])
{
    int len_s1=LengthofString(string1);
    int len_s2=LengthofString(string2);
    for (int i=0;i<len_s1;i++)
    {
        if (string1[i]>string2[i])
        {
            printf("The first string is greater than the second string.\n");
            break;
        }
        else if (string1[i]<string2[i])
        {
            printf("The second string is greater than the first string.\n");
            break;
        }
    }
}
void StringInsertion(char string1[],char substring[],int position)
{
    int len_s1=LengthofString(string1);
    int len_substring=LengthofString(substring);
    for (int i=position;i<=len_s1;i++)
    {
        string1[i+len_substring]=string1[i];
    }
    for (int i=0;i<len_substring;i++)
    {
        string1[position+i]=substring[i];
    }
}
void StringDeletion(char string1[],char substring_del[],int del_position)
{
    int len_s1=LengthofString(string1);
    int len_substring_del=LengthofString(substring_del);
    if (len_s1<len_substring_del)
    {
        printf("The length of the substring is greater than the length of the string.Hence,deletion is not possible.");
    }
    else
    {
        //Let us say we have a string of length n. At position k,the substring starts,and goes till position l.Then,the length of the substring is l-k.So,we need to shift all the characters after the
        //end of the substring to l-k positions before.
        for (int i=0;i<len_substring_del;i++)
        {
            string1[del_position+i]=string1[len_substring_del+del_position+i];
        }
    }
}
void main()
{
    char string[50],string2[50],substring[50],substring_del[50];
    int position,del_position;
    printf("Enter a string:");
    gets(string);
    printf("Enter another string:");
    gets(string2);
    printf("The length of the first string is %d.\n",LengthofString(string)); //Answer a.
    printf("The length of the second string is %d.\n",LengthofString(string2));
    printf("The concatenated string is:");
    StringConcatenation(string,string2); //Answer b.
    StringComparision(string,string2); //Answer c.
    printf("Enter the string you want to insert in the first string:");
    gets(substring);
    printf("Enter the position where you want to enter the substring:");
    scanf("%d",&position);
    StringInsertion(string,substring,position); //Answer d.
    printf("The string after inserting the substring is:");
    printf("%s\n",string);
    printf("Enter the substring you want to delete from the first string:");
    scanf("%s",&substring_del);
    printf("Enter the position in the first string from where the substring starts:");
    scanf("%d",&del_position);
    StringDeletion(string,substring_del,del_position); //Answer e.
    printf("The string after deleting the substring is:");
    puts(string);
}
