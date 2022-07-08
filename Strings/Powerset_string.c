/* Problem Statement:
Print all the possible subsets or powerset of the entered string characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* add_string(char curr[], char a)
{
    char *temp = malloc(20*sizeof(char));
    int i;
    while(curr[i] != '\0')
    {
        temp[i] = curr[i];
        i++;
    }
    temp[i]=a;
    temp[i+1]='\0';
    printf("%s",curr);
    printf("%s",temp);
    return temp;
}

void Powerset(char str[], int i, char curr[])
{
    if(i == strlen(str))
    {
        printf("%s  ",curr);
        return;
    }
    Powerset(str, i+1, strcat(curr,&str[i]));
    Powerset(str, i+1, curr);
}

int main()
{
    char str[] = "abc";
    char curr[10] = "curr";
    printf("%d",strlen(curr));
    char* c = add_string(curr,'a');
    printf("%s",*c);
    // Powerset(str, 0, curr);
}