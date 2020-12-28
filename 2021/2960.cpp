#include <iostream>
using namespace std;

int N, K;
int arr[1001] = { 0, }; 
int result[1001];

int main() {
	cin >> N >> K;
	int count = 0;
	for (int i = 2; i < N+1; i++) {
			for (int j = i; j < N + 1; j+=i) { 
				// 배수가 아직 지워지지 않았으면
				if (arr[j] == 0) { 
					arr[j] = 1; //1로 지우고 
					count++; //count++
					if (count == K) cout << j; //count가 K와 같으면 출력
				}
			}
		}
}
