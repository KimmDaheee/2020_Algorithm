#include <iostream>
#include<algorithm>
using namespace std;

int inArr[9];
int outArr[9];
int sumTotal = 0;

void Input() {
	for (int i = 0; i < 9; i++) {
		int n;
		scanf_s("%d", &n);
		inArr[i] = n;
		sumTotal += n;
	}
}

void Sort(int a, int b) {
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) {
			outArr[i] = 100;
		}
		else {
			outArr[i] = inArr[i];
		}
	}

	sort(outArr, outArr + 9);
}

void Out() {
	for (int i = 0; i < 7; i++) {
		if (i != 6) {
			cout << outArr[i] << endl;
		}
		else {
			cout << outArr[i];
		}
	}
}

void Permutation() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i != j) {
				int sum2 = inArr[i]+inArr[j];
				if (sum2 == sumTotal - 100) {
					Sort(i, j);
					Out();
					return;
				}
			}
		}
	}
}

int main() {
	Input();
	Permutation();
}