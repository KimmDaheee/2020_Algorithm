#include <iostream>
using namespace std;

int N;
long long result = 0;


int main() {
	cin >> N;


	for (int i = 1; i < N+1; i++) {
		// N까지의 약수의 합안에 i가 몇 번 나오는지 구함 
		long long temp = N / i;
		// i가 temp번 나오므로 result에 i*temp를 더함
		result = result + (i * temp);
	}

	cout << result << '\n';
}