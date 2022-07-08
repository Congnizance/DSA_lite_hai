/* Problem Statement:
An array contains both positive and negative numbers in random order. Rearrange the array 
elements so that all negative numbers appear before all positive numbers.
*/

#include <stdio.h>
#include <stdlib.h>

/* function to print an array */
void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
    printf("\n");
}

/* -------------function to seperate negative and positive elements in an array---------------*/

/* My approach:algo1 */
// Algorithm: higih
// Time complexity = O(n)
// Auxilary space = O(1)
void seperate1(int arr[], int n)
{
    int i, t1=0, t2=0;
    int temp1[n],temp2[n];
    for(i=0;i<n;i++)
    {
        if(arr[i] < 0)
            temp1[t1++] = arr[i];
        else
            temp2[t2++] = arr[i];
    }
    for(i=0;i<n;i++)
    {
        if(i < t1)
            arr[i] = temp1[i];
        else
            arr[i] = temp2[i-t1];
    }
}

/* Algo2: partition process of quicksort */
// Algorithm: keep counting negative number and swap if counter is ahead of the current lookup.
// Time complexity = O(n)
// Auxilary space = O(1)
void seperate2(int arr[], int n)
{
    int i,j=0, temp=0;
    for(i=0;i<n;i++)
    {
        if(arr[i] < 0)
        {
            if(i != j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
    }
}

/* Algo3: Two-pointer approach */
// Algorithm: Check for four possible conditions at end points of array and swap if necessary.
// Time complexity = O(n)
// Auxilary space = O(1)
void seperate3(int arr[], int n)
{
    int left=0,right=n-1, temp=0;
    while(left <= right)
    {
        if(arr[left] < 0 && arr[right] < 0)
        {
            left++;
        }
        else if(arr[left] < 0 && arr[right] > 0)
        {
            left++;
            right--;
        }
        else if(arr[left] > 0 && arr[right] < 0)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        else
        {
            right--;
        }
    }
}

/* Algo4: Dutch national flag algorithm */
// Algorithm: Check for possible conditions at end points of array and swap if necessary.
// Time complexity = O(n)
// Auxilary space = O(1)
void seperate4(int arr[], int n)
{
    int low=0,high=n-1, temp=0;
    while(low < high)
    {
        if(arr[low] < 0)
        {
            low++;
        }
        else if(arr[high] > 0)
        {
            high--;
        }
        else
        {
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
}

/* main driver function */
int main()
{
    int arr[] = {13,-5,-17,11,-15};
    /* take input from user */
    // int n;
    // printf("Enter size:\n");
    // scanf("%d",&n);
    // int arr[n];
    // printf("Enter array elements:\n");
    // for(int i=0;i<n;i++)
    //     scanf("%d",&arr[i]);
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    // seperate1(arr, size);
    // seperate2(arr, size);
    seperate4(arr, size);
    // seperate4(arr, size);
    print_array(arr,size);
    return 0;
}