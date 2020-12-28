#include <iostream>
using namespace std;

#define Max 101

//맵의 높이정보 저장
int map[Max][Max];

//좌표이동
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
//맵의 최대 크기
int N;
//최대 높이 저장
int maxHeight = 0;
//최대 안전 영역 저장
int maxArea = 0;

//입력받으면서 최대 높이 구함
void Input() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &map[i][j]);
			if (map[i][j] > maxHeight) maxHeight = map[i][j];
		}
	}
}

//출력
void Out(int x) {
	printf("%d", x);
}

//좌표가 맵 내부인지 판별
bool IsInside(int y, int x) {
	if (y >= 0 && y < N&& x >= 0 && x < N) return true;
	return false;
}

//Dfs 재귀함수 이용.
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
	//최대 높이 만큼 안전영역 구하기 반복
	for (int i = 0; i < maxHeight+1; i++) {
		//해당높이의 최대 안전영역
		int checkArea = 0;

		//물에 잠기는 watermap 선언 및 초기화.
		int waterMap[Max][Max] = { 0, };
		//맵의 방문 여부 저장. 미방문 0 방문 1
		int visited[Max][Max] = { 0, };
		//물에 잠기는 영역 설정. i보다 작거나 같으면 물에 잠김 = 1 아니면 물에 잠기지 않음 = 0
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] <= i) waterMap[j][k] = 1;
			}
		}

		//Dfs위한 맵 탐색
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (waterMap[j][k] == 0 && visited[j][k] == 0) {
					checkArea++;
					Dfs(j, k, waterMap, visited);
				}
			}
		}
		//해당 높이의 최대 안전영역이 전체 최대 안정영역보다 크면 최대 안정역역 갱신.
		if (checkArea > maxArea) maxArea = checkArea;
	}
	return maxArea;
}

int main() {
	Input();
	Out(Answer());
}

