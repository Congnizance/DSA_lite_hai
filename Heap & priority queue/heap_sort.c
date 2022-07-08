#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
    printf("\n");
}

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l] > arr[largest])
        largest = l;
    if(r<n && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        // print_array(arr,n);
        heapify(arr,largest,n);
    }
}

void build_heap(int arr[], int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
        heapify(arr,i,n);
}

void heap_sort(int arr[], int n)
{
    int i;
    for(i=n-1;i>=0;i--){
    swap(&arr[0],&arr[i]);
    heapify(arr,0,i);
    }
}

int main()
{
    int arr[] = {7,10,20,3,4,49,50};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    build_heap(arr,size);
    heap_sort(arr, size);
    print_array(arr, size);
}
