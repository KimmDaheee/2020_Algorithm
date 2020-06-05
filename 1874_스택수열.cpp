#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n;
int arr[100001];
stack<int> s;
queue<int> q;
queue<char> out;

void input() 
{
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
		q.push(i + 1);
	}
}

bool result() {
	for (int i = 0; i < n; i++) {
		int num = arr[i];
		if (!q.empty() && num > q.front()) {
			while (num != q.front()) {
				s.push(q.front());
				q.pop();
				out.push('+');
			}
			s.push(q.front());
			q.pop();
			out.push('+');
			s.pop();
			out.push('-');
		}
		else if (!q.empty() && num == q.front()) {
			q.pop();
			out.push('+');
			out.push('-');
		}
		else {
			if (num < s.top()) {
				return false;
			}
			else {
				out.push('-');
				s.pop();
			}
		}
	}
	return true;
}


int main() 
{
	input();

	bool temp = result();
	if (temp != true) cout << "NO";
	else {
		int qsize = out.size();
		for (int i = 0; i < qsize; i++) {
			cout << out.front() << '\n';
			out.pop();
		}
	}
}