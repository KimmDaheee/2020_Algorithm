#include<iostream>
#include<algorithm>
#define MAX 25
using namespace std;

int n; //���� ��� ���� ũ��
int groups[MAX*MAX + 1]; //�� ������ ���� ��
int group_id = 0; //������ ��ȣ �ο�
int map[MAX][MAX]; //�Է¹��� ���� ���� ����
bool visited[MAX][MAX]; //�湮 ���� ����
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Dfs_recursion(int x, int y) {
	
	visited[x][y] = true; //�Լ��� ������ �湮���� ����.
	groups[group_id]++; //���� �� ���� �� ����.
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//�ش� ����� ��, ����, �Ʒ�, ���� ��� ����

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			//nx, ny�� 0���� ũ�� �־��� ��� ���� ����� �ʰ�
			if (map[nx][ny] == 1 && visited[nx][ny] != true) {
				// �ش� ��ġ�� ���̰�, �湮���� �ʾ�����
				Dfs_recursion(nx,ny);
			}
		}
	
	}

}


int main() {

	//��� ���� ũ�� �ޱ�
	scanf_s("%d", &n);
	
	//������� ���� �ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
			visited[i][j] = false;
		}
	}

	//��ü Ž���ϱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//Ž���� ���� ���̰�, �湮���� �ʾ�����
			if (map[i][j] == 1 && visited[i][j] != true) {
				//���� ��ȣ �ο�(����)
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