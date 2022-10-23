// Maximum Subarray Sum using Divide and Conquer
#include <iostream>
#include <climits>

using namespace std;

int MAX_SUM(int nums[], int n)
{
    int max_sum = INT_MIN;
    int sum = 0;
 
    // do for each subarray that starts with 'i'
    for (int i = 0; i < n; i++)
    {
        // calculate sum of subarray 'nums[i…j]'
        sum = 0; 
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            /* if the current subarray sum is greater than the max sum 
            calculated, update the max sum */
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }

    return max_sum;
}
 
int main(void)
{
    int arr[] = { 2, -4, 1, 9, -6, 7, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "The maximum sum of the subarray is " << MAX_SUM(arr, n);
 
    return 0;
}
