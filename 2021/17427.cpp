#include <iostream>
using namespace std;

int N;
long long result = 0;


int main() {
	cin >> N;


	for (int i = 1; i < N+1; i++) {
		// N������ ����� �վȿ� i�� �� �� �������� ���� 
		long long temp = N / i;
		// i�� temp�� �����Ƿ� result�� i*temp�� ����
		result = result + (i * temp);
	}

	cout << result << '\n';
}