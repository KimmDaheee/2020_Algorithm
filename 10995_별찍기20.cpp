#include <iostream>
using namespace std;

void Answer(int num) {
	for (int i = 0; i < num; i++) {
		if (i % 2 == 1) {
			for (int i = 0; i < num; i++) {
				cout << " *";
			}
		}
		else {
			for (int i = 0; i < num; i++) {
				cout << "* ";
			}
		}
		cout << endl;
	}
}

int main() {
	int num;
	cin >> num;
	Answer(num);
}