/*
Given an integer array, rearrange it such that every second element becomes greater than its left and right elements. 
Assume no duplicate elements are present in the array.
*/
#include <iostream>
using namespace std;
 
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
void reArrange(int A[], int n)
{

    for (int i = 1; i < n; i += 2)
    {
        if (A[i - 1] > A[i]) {swap(A, i - 1, i);}
        if (i + 1 < n && A[i + 1] > A[i]) {swap(A, i + 1, i);}
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);
    reArrange(A, n);
    for (int i = 0; i < n; i++) {cout << A[i] << " ";} cout << endl;
    return 0;
}