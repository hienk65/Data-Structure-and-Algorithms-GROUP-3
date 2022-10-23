// Find maximum sum path involving elements of given arrays
#include <iostream>
using namespace std;
 
// Find the maximum of two integers
int max (int x, int y) {
    return (x > y) ? x : y;
}
 
// Function to find the maximum sum path of two given arrays
int MaxSumPath(int X[], int Y[], int m, int n)
{
    int result = 0;
    int sum_x = 0, sum_y = 0;
    // sum_x is the sum before common element of array X
    // sum_y is the sum before common element of array Y
    // result += max(sum_x,sum_y) + common element

    // 'i' and 'j' are the current array index of X and Y
    int i = 0, j = 0;
 
    while (i < m && j < n)
    {
        // handle the duplicate elements 
        while (i < m-1 && X[i] == X[i+1]) {
            sum_x += X[i]; 
            i++;
        }
 
        while (j < n-1 && Y[j] == Y[j+1]) {
            sum_y += Y[j];
            j++;
        }
 
        // Add elements before common element of Y to sum_y
        if (Y[j] < X[i])
        {
            sum_y += Y[j];
            j++;
        }
 
        // Add elements before common element of X to sum_x
        else if (X[i] < Y[j])
        {
            sum_x += X[i];
            i++;
        }
 
        else    // if (X[i] == Y[j]) aka common element
        {
            // takes the maximum sum and adds the current common element
            result += max(sum_x, sum_y) + X[i];
 
            // updates i and j for next calculation
            i++; j++;
 
            // reset both sums
            sum_x = 0, sum_y = 0;
        }
    }
    
    // When done the above 'while' loop:
    // process the remaining elements of X
    while (i < m) {
        sum_x += X[i++];
    }

    // process the remaining elements of Y
    while (j < n) {
        sum_y += Y[j++];
    }
 
    result += max(sum_x, sum_y);
    return result;
}
 
int main()
{
    int X[] = { 3, 6, 7, 8, 10, 12, 15, 18, 100 };
    int Y[] = { 1, 2, 3, 5, 7, 9, 10, 11, 15, 16, 18, 25, 50 };
 
    int m = sizeof(X)/sizeof(X[0]);
    int n = sizeof(Y)/sizeof(Y[0]);
 
    cout << "The maximum sum is " << MaxSumPath(X, Y, m, n);
 
    return 0;
}