#include <iostream>
using namespace std;

long long lan, newLan;
long long Max;
long long length[10001];
long long temp = 0;
long long answer = 0;

void Input() {
	cin >> lan >> newLan;
	cin >> length[0];
	Max = length[0];
	for (long long i = 1; i < lan; i++) {
		cin >> length[i];
		if (Max < length[i]) Max = length[i];
	}
}

long long BS(long long &l, long long &r, long long &mid){
	long long sum = 0;
	for (long long i = 0; i < lan; i++) sum += length[i] / mid;
	if (sum >= newLan) {
		l = mid + 1; 
		answer = mid;
	}
	else r = mid - 1;
	if (l > r) {
		return mid;
	}
	else {
		mid = (l + r) / 2;
		return 0;
	}
}

void Answer() {
	long long l, r, mid;
	l = 1; r = Max; mid = (l + r) / 2;
	while (true) {
		int end = BS(l, r, mid);

		if (end) {
			cout << answer;
			return;
		}
	}
}

int main() {
	Input();
	Answer();
}