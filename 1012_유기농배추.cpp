#include<iostream>
#define MAX 50
using namespace std;

//상하좌우 이동
int T; //테스트 케이스
int row;
int col;
int bNum; //배추개수
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void Dfs_recursion(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx >= 0 && nx < col && ny >= 0 && ny < row) {
			if (map[nx][ny] == 1 && visited[nx][ny] != true) {
				Dfs_recursion(nx, ny);
			}
		}
	}

}

void Answer() {
	int answer = 0;
	scanf_s("%d", &row);
	scanf_s("%d", &col);
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}

	scanf_s("%d", &bNum);
	for (int i = 0; i < bNum; i++) {
		int x, y;
		scanf_s("%d %d", &x, &y);
		map[y][x] = 1;
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 1 && visited[i][j] != true) {
				answer++;
				Dfs_recursion(i, j);
			}
		}
	}

	printf("%d\n", answer);

}

int main() {
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		Answer();
	}

	return 0;
}