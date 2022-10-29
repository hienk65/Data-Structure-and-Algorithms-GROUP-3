/*
Problem:
    Given an integer array, sort it using the merge sort algorithm.

Algorithm:
    * Variables: 
       - aux[]: the array use to copy sorted order
       - low, mid, high: two subarrays arr[low...mid] and arr[mid+1...high]
       - i, j: current index of subarray
       - k: current index of aux[]
    * Merge function: Merge two sorted subarrays into aux[] in sorted order.
    * Recursive function, parameter low and high:
       - mid = (low + high) / 2
       - Call two recursive functions with index (low, mid) and (mid+1, high).
       - Merge the two subarrays.
*/

#include <iostream>
#include <ctime>

#define N 15

using namespace std;

void merge(int *,int, int , int );

void merge_sort(int *arr, int low, int high)
{
    if (low < high) {

        // divide array at mid and independently sort them using merge sort
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        // merge / conquer sorted arrays
        merge(arr, low, high, mid);
    }
}

// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int k = low, i = low, j = mid + 1, aux[N];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            aux[k++] = arr[i++];
        }
        else  {
            aux[k++] = arr[j++];
        }
    }

    // copy remaining elements
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
    while (j <= high) {
        aux[k++] = arr[j++];
    }
    
    for (int i = low; i <= high; i++)  {
        arr[i] = aux[i];
    }
}

int main()
{   
    int arr[N];
    srand(time(NULL));
 
    // generate random input of integers
    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % 100) - 50;
    }
 
    merge_sort(arr, 0, N - 1);
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// Time complexity: O(n*log(n))