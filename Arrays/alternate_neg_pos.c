#include <stdio.h>
#include <stdlib.h>

void rotate(int arr[], int l, int r)
{
    int i, temp=arr[r];
    for(i=r-1;i>=l;i--)
        arr[i+1] = arr[i];
    arr[l] = temp;
}
// {1,2,3,-4,-1,4}
// {-4,1,2,3,-1,4}
// {-4,1,-1,2,3,4}
void rearrange(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(i%2 == 0)
        {
            if(a[i] >= 0)
            {
                int find=i+1;
                while(a[find] >= 0)
                {
                    find++;
                    if(find == n)
                        break;
                }
                if(find == n)
                    continue;
                rotate(a,i,find);
            }
        }
        else
        {
            if(a[i] < 0)
            {
                int find=i+1;
                while(a[find] < 0)
                {
                    find++;
                    if(find == n)
                        break;
                }
                if(find == n)
                    continue;
                rotate(a,i,find);
            }
        }
    }
}

void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
    printf("\n");
}

int main()
{
    // int arr[6] = {1,2,3,-4,-1,4};
    // int arr[10] = {-5,-2,5,2,4,7,1,8,0,-8};
    int arr[6] = {2,-1,-1,-1,3,-1};
    // rotate(arr,1,3);
    rearrange(arr,6);
    print_array(arr,6);
    return 0;
}