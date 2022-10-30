Code:
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





Algorithm:

Function printAllSubarrays (A, n)
For i=0 to n do {
  Sum =0
     For j=I to n do {
              Sum += A[j]
If Sum =0 { 
cout}
	}
}
Return 0;
