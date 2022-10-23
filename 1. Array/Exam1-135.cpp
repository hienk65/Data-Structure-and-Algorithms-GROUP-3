#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int> const &A, int k)
{
    int n = A.size();
    bool T[n + 1][k + 1];
    for (int j = 1; j <= k; j++) {T[0][j] = false;}
    for (int i = 0; i <= n; i++) {T[i][0] = true;}
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (A[i - 1] > j) {T[i][j] = T[i - 1][j];}
            else {T[i][j] = T[i - 1][j] || T[i - 1][j - A[i - 1]];}
        }
    }
    return T[n][k];
}
 
// Subset Sum Problem
int main()
{
    // Input: a set of items and a sum
    vector<int> A = { 7, 3, 2, 5, 8 };
    int k = 18;
 
    if (subsetSum(A, k)) {
        cout << "Subsequence with the given sum exists";
    }
    else {
        cout << "Subsequence with the given sum does not exist";
    }
 
    return 0;
}
