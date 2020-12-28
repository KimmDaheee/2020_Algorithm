#include<iostream>
#include<queue>
using namespace std;
#define Max 101

//맵의 크기
int N;
//사과 개수, 사과 위치를 가지고 있는 맵. 0은 사과x 1은 사과 o
int K;
int apple[Max][Max] = { 0, };
// 방향 변환 횟수, 방향 변환 정보 저장 배열
int L;
char direct[10001] = { 'a', };
// 이동함수
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
// 시간
int sec = 0;
int result;
// 뱀이 맵에서 차지하고 있는 위치를 나타내는 큐
queue<pair<int, int>> body;
// 현재 머리의 위치와 방향을 나타내는 변수
pair<int, int> head;
int headDirect; // 위 0, 오른 1, 아래 2, 왼쪽 3

int isBody[Max][Max] = { 0, };



void Input() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		apple[a][b] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int time;
		char direction;
		cin >> time >> direction;
		direct[time] = direction;
	}
	body.push(make_pair(0, 0));
	isBody[0][0] = 1;
}


bool isOut(int y, int x) {
	if (y >= N || y < 0 || x >= N || x < 0) {
		return true;
	}
	else {
		return false;
	}
}

int Cycle() {
	//머리 이동. 사과 판단 후, 해당 위치에서 머리가 몸/벽에 부딪히는지 확인.
	switch (headDirect) {
	case 0:
		head = make_pair(head.first + dy[0], head.second + dx[0]);
		break;
	case 1:
		head = make_pair(head.first + dy[1], head.second + dx[1]);
		break;
	case 2:
		head = make_pair(head.first + dy[2], head.second + dx[2]);
		break;
	case 3:
		head = make_pair(head.first + dy[3], head.second + dx[3]);
		break;
	}
	if (isBody[head.first][head.second] || isOut(head.first, head.second)) {
		return 0;
	}

	body.push(head);
	isBody[head.first][head.second] = 1;
	if (apple[head.first][head.second] == 0) {
		pair<int, int> temp = body.front();
		body.pop();
		isBody[temp.first][temp.second] = 0;
	}
	else {
		apple[head.first][head.second] = 0;
	}
	
	return 1;
}

//방향 전환은 answer함수에서 처리하고 cycle들어간다.
void Answer() {
	head = make_pair(0, 0);
	headDirect = 1;
	while (true) {
		int temp = Cycle();
		sec++;
		if (temp == 0) {
			result = sec;
			break;
		}
		else {
				if (direct[sec] == 'L')
				{
					switch (headDirect) {
					case 0:
						headDirect = 3;
						break;
					case 1:
						headDirect = 0;
						break;
					case 2:
						headDirect = 1;
						break;
					case 3:
						headDirect = 2;
						break;
					}
				}
				else if (direct[sec] == 'D')
				{
					switch (headDirect)
					{
					case 0:
						headDirect = 1;
						break;
					case 1:
						headDirect = 2;
						break;
					case 2:
						headDirect = 3;
						break;
					case 3:
						headDirect = 0;
						break;
					}
				}
		}
	}
}

int main() {
	Input();
	Answer();
	cout << result;
}

