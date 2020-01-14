#include <iostream>
#include <queue>
using namespace std;

//�ִ� ũ��
#define Max 1000
//���� �丶�� ����
int map[Max][Max];
//M ���� N ����
int M, N;
//�� ���� �Ʒ� �� ��ǥ �̵�
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

//���� Ž���� ť
queue<pair<int, int>> todayQ;

//���� Ž���� ť
queue<pair<int, int>> tomorrowQ;

//�Է¹޾� ���� ���� �� ó���ϴ� �Լ�
void Input() {
	scanf_s("%d%d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &map[i][j]);

			//�ʱ⿡ ���� �丶�� �߰��ϸ� ���� Ž���� ť�� �߰�.
			if (map[i][j] == 1) {
				todayQ.push(pair<int, int>(i, j));
			}
		}
	}
}

//��� ����ϴ� �Լ�
void Out(int answer) {
	printf("%d", answer);
}

//�ش� ��ġ�� ǥ�� �������� �Ǻ��ϴ� �Լ�
bool IsInside(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M) return true;
	return false;
}

int Answer() {
	int cur_y, cur_x;
	//day�� 0�������� ����.
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