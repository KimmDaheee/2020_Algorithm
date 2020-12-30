#include<iostream>
#include<math.h>
using namespace std;

int Answer(int num) {
	int length = 1;
	int result = 1;
	while (true) {
		int temp = result % num;
		if (temp != 0) {
			result = temp * 10 + 1;
		}
		else break;
		length++;
	}
	return length;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		int num;
		cin >> num;
		if (cin.eof()) break;
		else {
			cout << Answer(num) << '\n';
		}
	}
}