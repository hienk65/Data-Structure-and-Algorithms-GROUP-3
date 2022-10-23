// Find the missing number and duplicate elements in an array
#include <iostream>
using namespace std;
 
void getDupAndMiss(int arr[], int n)
{   
    int duplicate = 0 , missing = 0 ;
    int i = 0;

    /* Sort the given array, the duplicate element will be placed 
    at missing element's position */
    while (i < n)
    {   
        // If the element 'i' is on the correct sorting position
        if (arr[i] == arr[arr[i] - 1])
            i++;
        // If it isn't at the correct position, move it to correct position 
        else swap(arr[i], arr[arr[i] - 1]);
    }

    // Find duplicate / missing number
    for (int i = 0; i < n; i++) 
    {
        // If any element isn't in the correct position
        if (arr[i] != i + 1) {
            duplicate = arr[i];
            missing = i + 1;
            break;
        }
    }
 
    cout << "The duplicate and missing elements are " << duplicate
         << " and " << missing ;
}

int main()
{
    int arr[] = { 4, 3, 6, 5, 2, 4 };

    getDupAndMiss(arr, sizeof(arr) / sizeof(int));

    return 0;
}