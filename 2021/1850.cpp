#include <iostream>
using namespace std;

long long a, b;

long long GCD(long long a, long long b) {
	if (a % b == 0) return b;

	return GCD(b, a % b);
}

int main() {
	cin >> a >> b;
	
	if (b > a) {
		long long temp = a;
		a = b;
		b = temp;
	}

	long long result = GCD(a, b);

	for (long long i = 0; i < result; i++) {
		cout << 1;
	}
	return 0;
}