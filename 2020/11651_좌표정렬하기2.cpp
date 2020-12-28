#include <bits/stdc++.h>

using namespace std;

int n;
int arr[2001] = { 0, };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a < 0) {
			a = abs(a);
			arr[2 * a - 1] = 1;
		}
		else arr[2 * a] = 1;
	}
}

int main() {
	input();
	for (int i = 1999; i > -1; i = i-2) {
		if (arr[i] == 1) {
			int temp = i;
			temp = temp / 2 + 1;
			cout << "-"<< temp << " ";
		}
	}
	for (int i = 0; i < 2001; i = i + 2) {
		if (arr[i] == 1) {
			int temp = i / 2;
			cout << temp << " ";
		}
	}
}