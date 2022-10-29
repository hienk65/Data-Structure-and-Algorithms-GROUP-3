/* 
Problem:
    Write code to print all combinations of positive integers in increasing order that sum to a given positive number.

Algorithm: Same as 1-57.
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