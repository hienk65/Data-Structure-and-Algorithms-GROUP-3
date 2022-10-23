// Merge sort algorithm
#include <iostream>
#include <ctime>

using namespace std;

void merge(int *,int, int , int );

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high) {

        //divide array at mid and independently sort them using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);

        //merge / conquer sorted arrays
        merge(arr,low,high,mid);
    }
}

// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

int main()
{   const int N=15;
    int myarr[N];
    srand(time(NULL));
 
    // generate random input of integers
    for (int i = 0; i < N; i++) {
        myarr[i] = (rand() % 100) - 50;
    }
 
    // sort array 'myarr'
    merge_sort(myarr, 0, N - 1);
    
    for (int i = 0; i < N; i++) {
        cout << myarr[i] << " ";
    }

    return 0;
}