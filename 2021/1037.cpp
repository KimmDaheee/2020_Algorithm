#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 50;

int arr[MAX];

int main() {
	// T = Testcase
	int T, result;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + T);
	
	// �迭 �� ���� ū ���� ���� ���� �� ����
	result = arr[0] * arr[T - 1];

	cout << result;
}