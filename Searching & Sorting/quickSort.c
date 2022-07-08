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

int partition(int low, int high, int arr[])
{
    int pivot = arr[low];
    int i = low, j = high;
    while(i<j)
    {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i<j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j],&arr[low]);
    return j;
}

// Time complexity(average case) = O(nlogn). 
// Time complexity(worst case) = O(n^2) when array is sorted.
// Time complexity(best case) = O(nlogn) when array is always partitioned in the middle.
/* 
To solve this issue we choose the pivot differently:
1) pivot = (l+h)/2 
2) pivot = random(l,h)
*/
// Space complexity = O(n) due to recursion stack
void quickSort(int low, int high, int arr[])
{
    if(low < high)
    {
        int pivot = partition(low, high, arr);
        quickSort(low, pivot-1, arr);
        quickSort(pivot+1, high, arr);
    }
}

int main()
{
    int arr[] = {3,2,1,4,5,7,6,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    // partition(0,size-1,arr);
    quickSort(0, size-1, arr);
    print_array(arr, size);
    return 0;
}