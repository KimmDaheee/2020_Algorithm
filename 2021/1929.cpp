#include <iostream>
using namespace std;

const int MAX = 1000000 + 1;

int M, N;
int arr[MAX] = { 0, };

//에라토스테네스의 체
void isPrimeNumber() {
	arr[1] = 1;
	for (int i = 2; i < N + 1; i++) {
		if (arr[i] == 0) {
			for (int j = i * 2; j < N + 1; j += i) {
				arr[j] = 1;
			}
		}
	}
}

void outPut() {
	for (int i = M; i < N + 1; i++) {
		if (arr[i] == 0) {
			cout << i << '\n';
		}
	}
}

int main() {
	cin >> M >> N;

	isPrimeNumber();

	outPut();

}