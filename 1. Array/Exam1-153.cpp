/*
Problem: 
    Given an integer array of size n, with all its elements between 1 and n and one element occurring twice and one element missing. 
    Find the missing number and the duplicate element in linear time and without using any extra memory.

Algorithm:
    * Variable:
       - i: current index of array
    1. Loop, check if arr[i] is in its correct position (correct position: element valued x has index (x-1)):
       - If true: Increment i.
       - If false: Swap it to its correct position.
    2. Find duplicate / missing element from sorted array.
*/

#include <iostream>
using namespace std;
 
void getDupAndMiss(int arr[], int n)
{   
    int duplicate = 0 , missing = 0;
    int i = 0;

    // Sort the given array, the duplicate element will be placed at missing element's position
    while (i < n)
    {   
        // If the element i is at the correct position
        if (arr[i] == arr[arr[i] - 1])
            i++;
        // If it isn't at the correct position, swap it to correct position 
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

// Time complexity: O(n)