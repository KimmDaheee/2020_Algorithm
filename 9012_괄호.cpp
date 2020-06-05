#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;

string result(string str) 
{
	stack<int> s;
	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] == '(') s.push(0);
		else {
			if (!s.empty()) s.pop();
			else return "NO";
		}
	}
	if (!s.empty()) return "NO";
	else return "YES";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		string str;
		cin >> str;
		cout << result(str) << "\n";
	}
	return 0;
}