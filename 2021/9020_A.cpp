#include <iostream>
using namespace std;

int T;
int arr[10001] = { 0, }; // 0 = prime number, 1 = composite number

//에라토스테네스의 체
void isPrimeNum() {
	for(int i = 2; i<10001; i++){
		for (int j = i*2; j < 10001; j += i) {
			arr[j] = 1;
		}
	}
}

int Answer(int num) {
	//절반부터 탐색
	int length = num / 2;
	for (int i = 0; i < length; i++) {
		int temp1 = length - i;
		int temp2 = num - temp1;

		// 배열에 접근한 뒤, 둘 다 소수이면 출력
		if (arr[temp1] == 0) {
			if (arr[temp2] == 0) {
				cout << temp1 << ' ' << temp2 << '\n';
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	isPrimeNum();

	cin >> T;

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		Answer(num);
	}

	return 0;

}