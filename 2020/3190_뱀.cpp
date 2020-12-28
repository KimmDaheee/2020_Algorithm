#include<iostream>
#include<queue>
using namespace std;
#define Max 101

//���� ũ��
int N;
//��� ����, ��� ��ġ�� ������ �ִ� ��. 0�� ���x 1�� ��� o
int K;
int apple[Max][Max] = { 0, };
// ���� ��ȯ Ƚ��, ���� ��ȯ ���� ���� �迭
int L;
char direct[10001] = { 'a', };
// �̵��Լ�
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
// �ð�
int sec = 0;
int result;
// ���� �ʿ��� �����ϰ� �ִ� ��ġ�� ��Ÿ���� ť
queue<pair<int, int>> body;
// ���� �Ӹ��� ��ġ�� ������ ��Ÿ���� ����
pair<int, int> head;
int headDirect; // �� 0, ���� 1, �Ʒ� 2, ���� 3

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
	//�Ӹ� �̵�. ��� �Ǵ� ��, �ش� ��ġ���� �Ӹ��� ��/���� �ε������� Ȯ��.
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

//���� ��ȯ�� answer�Լ����� ó���ϰ� cycle����.
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

