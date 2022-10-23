#include<bits/stdc++.h>

using namespace std;
int main() {
    int arr[][2] = {{3, 4}, {1, 2}, {5, 2}, {7, 10}, {4, 3}, {2, 5}}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The Symmetric Pairs are: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] == arr[i][1] && arr[j][1] == arr[i][0]) {
                cout << "{" << arr[i][1] << " " << arr[i][0] << "}" << " | " << "{" << arr[i][0] << " " << arr[i][1] << "}" << " " << endl;
            }
        }
    }
}