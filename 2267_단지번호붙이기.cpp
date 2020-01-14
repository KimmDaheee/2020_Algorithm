#include<iostream>
#include<algorithm>
#define MAX 25
using namespace std;

int n; //맵의 행과 열의 크기
int groups[MAX*MAX + 1]; //각 단지내 세대 수
int group_id = 0; //단지에 번호 부여
int map[MAX][MAX]; //입력받은 맵의 정보 저장
bool visited[MAX][MAX]; //방문 여부 저장
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Dfs_recursion(int x, int y) {
	
	visited[x][y] = true; //함수에 들어오면 방문으로 설정.
	groups[group_id]++; //단지 내 세대 수 증가.
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//해당 노드의 위, 오른, 아래, 왼쪽 노드 조사

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			//nx, ny가 0보다 크고 주어진 행과 열을 벗어나지 않고
			if (map[nx][ny] == 1 && visited[nx][ny] != true) {
				// 해당 위치가 집이고, 방문하지 않았으면
				Dfs_recursion(nx,ny);
			}
		}
	
	}

}


int main() {

	//행과 열의 크기 받기
	scanf_s("%d", &n);
	
	//순서대로 끊어 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
			visited[i][j] = false;
		}
	}

	//전체 탐색하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//탐색한 곳이 집이고, 방문하지 않았으면
			if (map[i][j] == 1 && visited[i][j] != true) {
				//세대 번호 부여(증가)
				group_id++;
				groups[group_id] = 0;
				Dfs_recursion(i, j);
			}
		}
	}

	sort(groups+1, groups + group_id);
	printf("%d\n", group_id);
	for (int i = 1; i <= group_id; i++) {
		printf("%d\n", groups[i]);
	}

	return 0;

}