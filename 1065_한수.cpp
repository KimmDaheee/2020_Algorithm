#include <iostream>
using namespace std;

int n;
int result;

void Input() {
	cin >> n;
}

void Answer() {
	if (n < 100) 
	{
		result = n;
	}
	else 
	{
		int hundredNum = n / 100;
		int diff;
		result = 99 + (5 * (hundredNum - 1));
		diff = 0 - (hundredNum / 2);
		for (int i = diff; i < diff + 5; i++) 
		{
			int newNum = (hundredNum * 100) + ( (hundredNum + i) * 10 ) +(hundredNum + (2 * i));
			if (newNum <= n) 
			{
				result++;
			}
			else break;
		}
	}
}

int main() {
	Input();
	Answer();
	cout << result;
}