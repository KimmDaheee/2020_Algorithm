#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, string> arr[20000];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		arr[i] = make_pair(a.size(), a);
	}
}

int main() {
	input();
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			if (arr[i].second != arr[i + 1].second)	cout << arr[i].second << "\n";
		}
		else {
			cout << arr[i].second;
		}
	}
}