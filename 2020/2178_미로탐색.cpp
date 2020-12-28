#include <iostream>
#include <queue>
using namespace std;

#define Max 100

//��,��
int row, col;
//������ �̷� ����
int map[Max][Max];
//�� �������� �����ϴ� �ּ� �Ÿ�
int dis[Max][Max] = { 0, };
//���� ��ġ�� �̵��ϱ� ���� ����Ʈ. �� ���� �Ʒ� ��
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };


void Input() {
	scanf_s("%d%d", &row, &col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
}

void Out(int answer) {
	printf("%d\n", answer);
}

bool Inside(int y, int x) {
	if (y >= 0 && y < row && x >= 0 && x < col) {
		return true;
	}
	return false;
}

int Bfs() {
	int cur_x = 0;
	int cur_y = 0;

	queue<pair<int, int>> q;
	q.push(pair<int, int>(cur_y, cur_x));
	//�ʱ� ��ġ�� �Ÿ��� 1
	dis[cur_y][cur_x] = 1;

	while (!q.empty()) {
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		if (cur_y == row && cur_x == col) break;

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (Inside(next_y, next_x) && dis[next_y][next_x] == 0 && map[next_y][next_x] == 1) {
				dis[next_y][next_x] = dis[cur_y][cur_x] + 1;
				q.push(pair<int, int>(next_y, next_x));
			}
			
		}
	}

	return dis[row - 1][col - 1];
	
}

int main() {
	Input();
	Out(Bfs());


}
