#include <iostream>
using namespace std;

const int MAX = 1000000;
int T;
long long arr[MAX+1] = { 0, };
long long G[MAX + 1] = { 0, };


void DivisorNum() {
	int temp = MAX + 1;
	for (int i = 1; i < temp; i++) {
		for (int j = i; j < temp; j += i) {
			arr[j] += i;
		}
	}
	G[1] = 1;
	for (int i = 2; i < temp; i++) {
		G[i] = G[i - 1] + arr[i];
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	DivisorNum();

	cin >> T;

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		cout << G[num] << '\n';
	}

}