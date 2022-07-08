#include <stdio.h>
#include <stdlib.h>

int n=5;

// Time complexity = O(logn)
// Space complexity = O(logn)
/* Recursive solution uses recusion stack for storing function calls thus is less efficeint
in terms of space.
*/
int binarySearch(int low, int high, int key, int arr[])
{
    int mid=(low+high)/2;
    if(low > high)
        return -1;
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return binarySearch(mid+1, high, key, arr);
    else
        return binarySearch(low, mid-1, key, arr);
}

// Time complexity = O(logn)
// Space complexity = O(1)
/* Iterative solution is faster than recursive solution due to space complexity */
int binarySearch2(int key, int arr[])
{
    int low=0,high=n-1;
    while(low <= high)
    {
        int mid=(low+high)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,10};
    n = sizeof(arr)/sizeof(arr[0]);
    int key;
    scanf("%d",&key);
    // int result = binarySearch(0, n-1, key, arr);
    int result = binarySearch2(key, arr);
    if(result != -1)
        printf("Key %d exists at %d index in array",key,result);
    else
        printf("Key %d does not exist in array",key);
}