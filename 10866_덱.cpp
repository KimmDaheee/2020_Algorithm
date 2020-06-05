#include <iostream>
#include <deque>
#include <string>
using namespace std;
int n;
string arr[10001];
int arr2[10001] = { 0, };
deque<int> s;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == "push_back" || arr[i] =="push_front") {
			cin >> arr2[i];
		}
	}
}

int main() {
	input();

	for (int i = 0; i < n; i++) {
		if (arr[i] == "empty") cout << s.empty() << endl;
		else if (arr[i] == "size") cout << s.size() << endl;
		else if (arr[i] == "pop_front") {
			if (!s.empty()) {
				cout << s.front() << endl;
				s.pop_front();
			}
			else cout << -1 << endl;
		}
		else if (arr[i] == "pop_back") {
			if (!s.empty()) {
				cout << s.back() << endl;
				s.pop_back();
			}
			else cout << -1 << endl;
		}
		else if (arr[i] == "push_front") {
			s.push_front(arr2[i]);
		}
		else if (arr[i] == "push_back") {
			s.push_back(arr2[i]);
		}
		else if (arr[i] == "front"){
			if (!s.empty()) cout << s.front() << "\n";
			else cout << -1 << "\n";
		}
		else {
			if (!s.empty()) cout << s.back() << "\n";
			else cout << -1 << "\n";
		}
	}
	

}