/* Problem Statement:
There are n people standing in a circle waiting to be executed. The counting out begins at some point in the 
circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are 
skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller 
and smaller as the executed people are removed), until only the last person remains, who is given freedom. 
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person 
is killed in circle. The task is to choose the place in the initial circle so that you are the last one 
remaining and so survive.
*/

#include <stdio.h>
#include <stdlib.h>

// function to find the position of the Most
// Significant Bit
int msbPos(int n)
{
    int pos = 0;
    while (n != 0) {
        pos++;
 
        // keeps shifting bits to the right
        // until we are left with 0
        n = n >> 1;
    }
    return pos;
}

// Recursive approach
// Time Complexity = O(n)
int josephus1(int n, int k)
{
    return (n > 1) ? ((josephus1(n-1,k)+k-1)%n+1):1;
}

// only for k=2, bit manipulation approach
// Time complexity = O(1)
int josephus2(int n)
{
    /*  Getting the position of the Most Significant
        Bit(MSB). The leftmost '1'. If the number is
       '41' then its binary is '101001'.
        So msbPos(41) = 6   */
    int position = msbPos(n);
 
    /* 'j' stores the number with which to XOR the
        number 'n'. Since we need '100000'
       We will do 1<<6-1 to get '100000' */
    int j = 1 << (position - 1);
 
    /* Toggling the Most Significant Bit. Changing
       the leftmost '1' to '0'.
       101001 ^ 100000 = 001001 (9) */
    n = n ^ j;
 
    /*  Left-shifting once to add an extra '0' to
        the right end of the binary number
        001001 = 010010 (18) */
    n = n << 1;
 
    /* Toggling the '0' at the end to '1' which
       is essentially the same as putting the
       MSB at the rightmost place. 010010 | 1
       = 010011 (19) */
    n = n | 1;
 
    return n;
}

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    printf("%d",josephus1(n,k));
    // printf("%d",josephus2(n));
}