/* 
Problem:
    Given a positive integer n, print all combinations of numbers between 1 and n having sum n.

Algorithm:
    * Variables:
       - out: array
       - n: the current recursive sum
       - i (j): the value to push in the array and pop out later
    * Recursive function, parameter i and n:
       - If n is equal to 0: Print result array.
       - For j from i to n: Push j in the array. Call the recursive function with element j and sum (n-j). 
         Then pop j out of array.
*/

#include <iostream>
#include <vector>
using namespace std;

// Print the content of given array 'out'
void print(vector<int> const &out)
{
    for (int i: out) {
        cout << i << " ";
    }
    cout << endl;
}
 
// Recursive function to print all combinations of numbers
void printComb(int i, int n, vector<int> &out)
{
    // if the sum (of multiple 'j' variable) becomes 'n', print the combination
    if (n == 0) {
        print(out);
    }
 
    // start from the previous element in the combination till 'n'
    for (int j = i; j <= n; j++)
    {
        // include current element from the combination
        out.push_back(j);
 
        // recur with a reduced sum 'n-j'
        printComb(j, n - j, out);
 
        /* remove the last element from the combination
        every time the right above printComb() done */
        out.pop_back();
    }
}
 
int main()
{
    int n = 5;
 
    vector<int> out;
 
    printComb(1, n, out);
 
    return 0;
}

// Time complexity: O(a^n)