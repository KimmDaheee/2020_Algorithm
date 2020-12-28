#include <iostream>
using namespace std;

int T, num;

bool isPrimeNum(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}


int Answer(int num) {
	int length = num / 2;

	for (int i = 0; i < length; i++) {
		int temp1 = length - i;
		if (isPrimeNum(temp1)) {
			if (isPrimeNum(num - temp1)) {
				cout << temp1 << ' ' << num - temp1 << '\n';
				return 0;
			}
		}
	}

	return 1;

}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num;
		Answer(num);
	}
}