#include <iostream>
#include <queue>
using namespace std;

//최대 크기
#define Max 1000
//맵의 토마토 정보
int map[Max][Max];
//M 가로 N 세로
int M, N;
//위 오른 아래 왼 좌표 이동
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

//오늘 탐색할 큐
queue<pair<int, int>> todayQ;

//내일 탐색할 큐
queue<pair<int, int>> tomorrowQ;

//입력받아 정보 저장 및 처리하는 함수
void Input() {
	scanf_s("%d%d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &map[i][j]);

			//초기에 익은 토마토 발견하면 오늘 탐색할 큐에 추가.
			if (map[i][j] == 1) {
				todayQ.push(pair<int, int>(i, j));
			}
		}
	}
}

//결과 출력하는 함수
void Out(int answer) {
	printf("%d", answer);
}

//해당 위치가 표의 내부인지 판별하는 함수
bool IsInside(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M) return true;
	return false;
}

int Answer() {
	int cur_y, cur_x;
	//day는 0일차부터 시작.
	int day = 0;

	while (!todayQ.empty()) {
		cur_y = todayQ.front().first;
		cur_x = todayQ.front().second;
		todayQ.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			
			if (IsInside(next_y, next_x) && map[next_y][next_x] == 0) {
				tomorrowQ.push(pair<int, int>(next_y, next_x));
				map[next_y][next_x] = 1;
			}
		}

		if (todayQ.empty() && !tomorrowQ.empty()) {
			while (!tomorrowQ.empty()) {
				todayQ.push(tomorrowQ.front());
				tomorrowQ.pop();
			}
			day++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) day = -1;
		}
	}

	return day;
}

int main() {
	Input();
	Out(Answer());
}