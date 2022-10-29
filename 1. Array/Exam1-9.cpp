/* 
Problem: 
    Given an array containing only 0’s, 1’s, and 2’s, sort it in linear time and using constant space.

Algorithm:
    * Three variables: 
       - i: the number of value 0 checked
       - j: current element's index
       - k: initial value is the last element's index
    * Loop, check A[j]:
       - If A[j] is valued 0: Swap it with A[i]. Increment i and j.
       - If A[j] is valued 1: Increment j.
       - If A[j] is valued 2: Swap it with A[k]. Decrement k.
*/

#include <iostream>
using namespace std;
 
// Swap two elements in array
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
// Linear time partition routine to sort an array of 0, 1, and 2.
void threeWayPartition(int A[], int end)
{   
    int start = 0, mid = 0;

    /* Elements from 0 to 'start-1' are equal to 0
            from 'start' to 'mid-1' are equal to 1
            from 'mid' (current element) to 'end' are not yet sorted
            from 'end+1' to the end of array are equal to 2
    */
    while (mid <= end)
    {
        if (A[mid] == 0)         
        {
            swap(A, start, mid);
            ++start, ++mid;
        }
        else if (A[mid] == 2)    
        {
            swap(A, mid, end);
            --end;
        }
        else {                // current element is 1
            ++mid;
        }
    }
}
 
int main()
{
    int A[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
    int n = sizeof(A)/sizeof(A[0]);
 
    threeWayPartition(A, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
 
    return 0;
}

// Time complexity: O(n)