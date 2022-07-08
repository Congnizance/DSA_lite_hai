/* Problem Statement:
Check if a string is a palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Time Complexity = O(n)
bool isPalin(char str[], int l, int r)
{
    if(l >= r)
        return true;
    if(str[l] != str[r])
        return false;
    return isPalin(str, l+1, r-1);
}

int main()
{
    char str[] = "abc";
    int size = (sizeof(str)/sizeof(str[0]))-1;
    printf("%s : ",str);
    printf("%d\n",size);
    if(isPalin(str, 0, size-1))
        printf("String is Palindrome");
    else
        printf("String is not Palindrome");
}