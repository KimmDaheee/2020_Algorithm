#include <iostream>
using namespace std;

#define Max 101

//���� �������� ����
int map[Max][Max];

//��ǥ�̵�
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
//���� �ִ� ũ��
int N;
//�ִ� ���� ����
int maxHeight = 0;
//�ִ� ���� ���� ����
int maxArea = 0;

//�Է¹����鼭 �ִ� ���� ����
void Input() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &map[i][j]);
			if (map[i][j] > maxHeight) maxHeight = map[i][j];
		}
	}
}

//���
void Out(int x) {
	printf("%d", x);
}

//��ǥ�� �� �������� �Ǻ�
bool IsInside(int y, int x) {
	if (y >= 0 && y < N&& x >= 0 && x < N) return true;
	return false;
}

//Dfs ����Լ� �̿�.
void Dfs(int y, int x, int waterMap[][101], int visited[][101]) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (IsInside(ny, nx) && waterMap[ny][nx] == 0 && visited[ny][nx] == 0) {
			Dfs(ny, nx, waterMap, visited);
		}
	}
}

//
int Answer() {
	//�ִ� ���� ��ŭ �������� ���ϱ� �ݺ�
	for (int i = 0; i < maxHeight+1; i++) {
		//�ش������ �ִ� ��������
		int checkArea = 0;

		//���� ���� watermap ���� �� �ʱ�ȭ.
		int waterMap[Max][Max] = { 0, };
		//���� �湮 ���� ����. �̹湮 0 �湮 1
		int visited[Max][Max] = { 0, };
		//���� ���� ���� ����. i���� �۰ų� ������ ���� ��� = 1 �ƴϸ� ���� ����� ���� = 0
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] <= i) waterMap[j][k] = 1;
			}
		}

		//Dfs���� �� Ž��
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (waterMap[j][k] == 0 && visited[j][k] == 0) {
					checkArea++;
					Dfs(j, k, waterMap, visited);
				}
			}
		}
		//�ش� ������ �ִ� ���������� ��ü �ִ� ������������ ũ�� �ִ� �������� ����.
		if (checkArea > maxArea) maxArea = checkArea;
	}
	return maxArea;
}

int main() {
	Input();
	Out(Answer());
}

