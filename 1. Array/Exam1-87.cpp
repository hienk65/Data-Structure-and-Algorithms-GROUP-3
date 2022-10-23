#include <bits/stdc++.h>
using namespace std;

struct inter {
	int start, end;
};
stack<inter> s;
bool compareInter(inter i1, inter i2){return (i1.start < i2.start);} 
void mergeInter(inter arr[], int n)
{
	if (n <= 0)
	stack<inter> s;
	sort(arr, arr + n, compareInter);
	s.push(arr[0]);
	for (int i = 1; i < n; i++) {
		inter top = s.top();
		if (top.end < arr[i].start)
			s.push(arr[i]);
		else if (top.end < arr[i].end) {
			top.end = arr[i].end;
			s.pop();
			s.push(top);
		}
	}
	cout << "\n The Merged inters are: ";
	while (!s.empty()) {
		inter t = s.top();
		cout << "[" << t.start << "," << t.end << "] ";
		s.pop();
	}
	return;
}

int main()
{
	inter arr[] = {{1, 5}, {2, 3}, {4, 6}, {7, 8}, {8, 10}, {12, 15}};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeInter(arr, n);
	return 0;
}
