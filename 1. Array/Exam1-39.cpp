#include <iostream>
#include <vector>
using namespace std;
 
int maxSum(vector<int> const &numbers)
{
    int n = numbers.size();
    if (n == 0) {return 0;}
    if (n == 1) {return numbers[0];}
    int a = numbers[0];
    int b = max(numbers[0], numbers[1]);
    for (int i = 2; i < n; i++)
    {
        int c = max(numbers[i], max(b, a + numbers[i]));
        a = b; b = c;
    }
    return b;
}
 
int main()
{
    vector<int> numbers = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
    cout << "The maximum sum: " << maxSum(numbers);
    return 0;
}
