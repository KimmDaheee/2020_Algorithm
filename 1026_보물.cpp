#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr1[50];
int arr2[50];

bool comp(int i, int j) {
	return j < i;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr2[i];
	}
}

int main() {
	input();
	int result = 0;
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n, comp);
	for (int i = 0; i < n; i++) {
		result += arr1[i] * arr2[i];
	}
	cout << result;
}