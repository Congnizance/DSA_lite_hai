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

void merge(int left, int mid, int right, int arr[])
{
    int temp[50];
    int i=left, j=mid+1, k=left;
    while(i<=mid && j<=right)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=right)
        {
            temp[k++] = arr[j++];
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[k++] = arr[i++];
        }
    }
    for(i=0;i<k;i++)
        arr[i] = temp[i];
}

// Time complexity (average case) = O(nlogn)
// Time complexity (worst case) = O(nlogn)
// Time complexity (best case) = O(nlogn)
// Most efficient algorithm
void mergeSort(int left, int right, int arr[])
{
    if(left<right)
    {
        int mid = (left+right)/2;
        mergeSort(left, mid, arr);
        mergeSort(mid+1, right, arr);
        merge(left, mid, right, arr);
    }
}

int main()
{
    int arr[] = {3,2,1,4,5,7,6,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    mergeSort(0, size-1, arr);
    print_array(arr, size);
    return 0;
}