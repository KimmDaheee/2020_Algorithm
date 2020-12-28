#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n;
string arr[10001];
int arr2[10001] = { 0, };
queue<int> s;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == "push") {
			cin >> arr2[i];
		}
	}
}

int main() {
	input();

	for (int i = 0; i < n; i++) {
		if (arr[i] == "empty") cout << s.empty() << endl;
		else if (arr[i] == "size") cout << s.size() << endl;
		else if (arr[i] == "pop") {
			if (!s.empty()) {
				cout << s.front() << endl;
				s.pop();
			}
			else cout << -1 << endl;
		}
		else if (arr[i] == "front") {
			if (!s.empty()) {
				cout << s.front() << endl;
			}
			else cout << -1 << endl;
		}
		else if (arr[i] == "back") {
			if (!s.empty()) {
				cout << s.back() << endl;
			}
			else cout << -1 << endl;
		}
		else {
			s.push(arr2[i]);
		}
	}
}