#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_NODE 501

using namespace std;

typedef struct EDGE {
	int dest;
	int val;
};

// 0�� �ε����� ������. 
vector<EDGE> edge_vec[MAX_NODE];
int value_arr[MAX_NODE] = { 0 };
int N, M;

int bellman_ford(int excute_num) {
	int isChanged = 0;
	// ���� ���� �˰����� �����Ѵ�. 
	// ��� VERTEX ���� ����� EDGE �� Ȯ���ؾ� �Ѵ�.
	// i�� ������  edge_vec[i][k].dest �� ������
	// �� ��帶�� �� ���� �����Ѵ�.
	for (int t = 1; t <= N; t++) {
		// �� ��帶�� ��� ������ ���Ͽ� 
		for (int i = 1; i <= N; i++) {
			for (int k = 0; k < edge_vec[i].size(); k++) {
				// ���� �������� ���� ����� ����ġ��, ��� ��忡�� ������ ���� ���� ����� ����ġ�� ���� ���Ѵ�. 
				int new_val = (value_arr[i] + edge_vec[i][k].val);
				int before_val = (value_arr[edge_vec[i][k].dest]);
				// ��� ���� ���� �� ���� ũ�� �����Ѵ�.
				if ((value_arr[i] != INF) && (new_val < before_val)) {
					isChanged = 1;
					// ���� 2��° ���� �Ķ�� �ٷ� �Լ��� �����Ѵ�. 
					if (isChanged * excute_num) return isChanged;
					value_arr[edge_vec[i][k].dest] = new_val;
				}
			}
		}
	}

	return isChanged;
}

int main() {
	cin >> N >> M;

	// EDGE �Է¹ޱ� 
	int from, to, val;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &val);
		edge_vec[from].push_back(EDGE{ to, val });
	}

	// �ʱ� ���� ������ �ð��� INF ���� �ʱ�ȭ 
	for (int i = 2; i <= N; i++) value_arr[i] = INF;

	// ���� ���� �˰��� ����
	bellman_ford(0);

	// �� ��° �����ؼ� ���� ����Ǵ� ���� ������, �Լ����� 1�� ���ϵȴ�. 
	if (bellman_ford(1) == 1) {
		cout << -1;
	}
	// �Լ� ���� ���� 0�̸� ���� ���� ���� ������, �ٷ� ���� ����Ѵ�. 
	else {
		for (int i = 2; i <= N; i++)
			printf("%d\n", (value_arr[i] != INF ? value_arr[i] : -1));
	}

	return 0;
}