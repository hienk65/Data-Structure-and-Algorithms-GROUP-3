/*
Problem:
    Given an integer array, find the maximum sum among all subarrays possible.

Algorithm:
    1. Divide the array into two equal subarrays.
    2. Recursively calculate the maximum subarray sum for the left subarray.
    3. Recursively calculate the maximum subarray sum for the right subarray.
    4. Find the maximum subarray sum that crosses the middle element.
    5. Return the maximum of the above three sums.
*/

#include <iostream>
#include <climits>

using namespace std;

int max(int x, int y) {
    return (x > y) ? x : y;
}
 
// Find the maximum subarray sum using divide-and-conquer
int maximum_sum(int nums[], int low, int high)
{
    if (high <= low) {
        return nums[low];
    }
 
    // middle array element
    int mid = (low + high) / 2;
 
    // Find maximum subarray sum for the left subarray including the middle element
    int left_max = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += nums[i];
        if (sum > left_max) {
            left_max = sum;
        }
    }
 
    // Find maximum subarray sum for the right subarray
    int right_max = INT_MIN;
    sum = 0;   
    for (int i = mid + 1; i <= high; i++)
    {
        sum += nums[i];
        if (sum > right_max) {
            right_max = sum;
        }
    }
 
    // Recursively find the maximum subarray sum for the left and right subarray, then take maximum
    int max_left_right = max(maximum_sum(nums, low, mid),
                            maximum_sum(nums, mid + 1, high));
 
    return max(max_left_right, left_max + right_max);
}
 
int main(void)
{
    int arr[] = { 2, -4, 1, 9, -6, 7, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "The maximum sum of the subarray is " << maximum_sum(arr, 0, n - 1);
        
    return 0;
}

// Time complexity: O(n*log(n))