#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
    printf("\n");
}

// Time complexity = O(n^2)
// Better than bubble sort since lesser number of operations are performed.
void insertionSort(int n, int arr[])
{
    int i;
    for(i=0;i<n;i++)
    {
        int temp = arr[i];
        int a=i-1;
        while(a>=0 && arr[a] > temp)
        {
            arr[a+1] = arr[a];
            a--;
        }
        arr[a+1] = temp;
    }
}

int main()
{
    int arr[] = {3,2,1,4,5,7,6,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    insertionSort(size, arr);
    print_array(arr, size);
    return 0;
}