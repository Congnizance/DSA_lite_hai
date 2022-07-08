#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Time complexity = O(n^2)
void bubbleSort(int n, int arr[])
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j+1] < arr[j])
                swap(&arr[j+1],&arr[j]);
        }
    }
}

int main()
{
    int arr[] = {3,2,1,4,5,7,6,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    bubbleSort(size, arr);
    print_array(arr, size);
    return 0;
}