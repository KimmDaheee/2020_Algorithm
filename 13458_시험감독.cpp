#include <iostream>
using namespace std;
#define Max 1000001

int N;
int personNum[Max];
int B, C;
long long int result;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> personNum[i];
	}
	cin >> B >> C;
	result = N;
}

void Out(long long int result) {
	cout << result;
}

void Answer() {
	for (int i = 0; i < N; i++) {
		int temp = personNum[i] - B;
		if (temp > 0 && temp % C == 0) {
			temp = temp / C;
		}
		else if(temp > 0 && temp % C != 0){
			temp = (temp / C) + 1;
		}
		else if (temp <= 0) {
			temp = 0;
		}
		result += temp;
	}
}

int main() {
	Input();
	Answer();
	Out(result);
}
