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

// Time coplexity = O(n^2)
void selectionSort(int n, int arr[])
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int min = i;
        for(j=i;j<n;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
            swap(&arr[i],&arr[min]);
    }
}

int main()
{
    int arr[] = {3,2,1,4,5,7,6,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    selectionSort(size, arr);
    print_array(arr, size);
    return 0;
}