#include <iostream>
using namespace std;

int num;
int Min = 0;
int Max = 0;
int arr[1000001] = { 0, };

void Input() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
}

void Answer() {
	Min = arr[0];
	Max = arr[0];

	for (int i = 1; i < num; i++) {
		if (arr[i] > Max) {
			Max = arr[i];
		}
		else if(arr[i]<Min) {
			Min = arr[i];
		}
	}

	cout << Min << " " << Max;
}

int main() {
	Input();
	Answer();
}