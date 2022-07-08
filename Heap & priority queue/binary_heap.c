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

void insert(int arr[], int* n, int key)
{
    arr[*n] = key;
    int i=*n;
    *n = *n + 1;
    while(i>0)
    {
        int parent=i/2-1;
        if(arr[parent]<arr[i])
        {
            swap(&arr[parent],&arr[i]);
            i=parent;
        }
        else
            return;
    }
}

void delete(int arr[], int* n)
{
    *n = *n-1;
    arr[0] = arr[*n];
    heapify(arr,0,*n);
}

int main()
{
    int arr[50] = {10,30,50,20,35,15};
    int size = 6;
    print_array(arr, size);
    build_heap(arr,size);
    print_array(arr, size);
    insert(arr,&size,13);
    print_array(arr,size);
    delete(arr,&size);
    print_array(arr, size);
}