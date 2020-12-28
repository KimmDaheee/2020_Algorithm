#include<iostream>
#include<queue>
using namespace std;

#define Max 100
int map[Max][Max];
int arriveTime[Max][Max] = { 0, };
int n, m, t;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int gram_y, gram_x;


queue<pair<int, int>> q;

void Input() {
	scanf_s("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &map[i][j]);
			if (map[i][j] == 2){
				gram_y = i;
				gram_x = j;
			}
		}
		q.push(pair<int, int>(0, 0));
	}
}

bool IsInside(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) {
		return true;
	}
	return false;
}

void Out(int x) {

		cout << x;

}

void Answer() {
	int cur_y = 0;
	int cur_x = 0;
	int time;
	arriveTime[cur_y][cur_x] = 0;

	while (!q.empty()) {
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (IsInside(next_y, next_x) && map[next_y][next_x] != 1 && arriveTime[next_y][next_x] == 0) {
				q.push(pair<int, int>(next_y, next_x));
				arriveTime[next_y][next_x] = arriveTime[cur_y][cur_x] + 1;
			}
		}
	}

	int T1 = arriveTime[n - 1][m - 1];
	int T2 = 0;
	if (arriveTime[gram_y][gram_x] != 0) {
		T2 = arriveTime[gram_y][gram_x] + (n - 1 - gram_y) + (m - 1 - gram_x);
	}


	if (T1 == 0 && T2 == 0) {
		cout << "Fail";
	}
	else if (T1 == 0 && T2 != 0) {
		time = T2;
		if (time <= t) {
			cout << T2;
		}
		else {
			cout << "Fail";
		}
	}
	else if (T1 != 0 && T2 == 0) {
		time = T1;
		if (time <= t) {
			cout << time;
		}
		else {
			cout << "Fail";
		}
	}
	else {
		if (T1 <= T2) {
			time = T1;
			cout << time;
		}
		else {
			time = T2;
			cout << T2;
		}
	}


}

int main() {
	Input();
	Answer();
}