#include <iostream>
#include <vector>
using namespace std;

//공간 크기
int n;
//그림 정보 저장
vector<vector<int>> map;
//그림 압축정보 저장
vector<char> compress;


//입력받고, 이차원 벡터에 저장.
void Input() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int value;
			scanf_s("%1d", &value);
			temp.push_back(value);
		}
		map.push_back(temp);
	}
}

void Print() {
	printf("(");
	for (int i = 0; i < compress.size(); i++) {
		printf("%c", compress[i]);
	}
}

void Division(vector<vector<int>> map) {
	
	int size = map.size();
	int newSize = size / 2;

	//4개의 이차원 벡터로 분할
	// 1) 이차원 벡터 배열 생성.
	if (newSize != 0) {
		vector<vector<int>> arr[4];
		//각 부분이 all 0 or all 1로 압축 되는지 판별하는 정수 배열. -1이면 압축 x.
		int isCompress[4] = { -1, };
		// 2) 각 이차원 벡터의 시작 지점 입력 및 그림 정보 입력. (왼위, 오위, 왼아, 오아 순서)
		for (int i = 0; i < 4; i++) {
			int start_y;
			int start_x;
			switch (i) {
			case 0:
				start_y = 0;
				start_x = 0;
				break;
			case 1:
				start_y = 0;
				start_x = newSize;
				break;
			case 2:
				start_y = newSize;
				start_x = 0;
				break;
			case 3:
				start_y = newSize;
				start_x = newSize;
			}
			for (int j = 0; j < newSize; j++) {
				vector<int> temp;
				for (int k = 0; k < newSize; k++) {
					temp.push_back(map[start_y + j][start_x + k]);
				}
				arr[i].push_back(temp);
			}
		}

		for (int i = 0; i < 4; i++) {
			bool all0 = false;
			bool all1 = false;
			for (int j = 0; j < newSize; j++) {
				for (int k = 0; k < newSize; k++) {
					if (arr[i][j][k] == 0) {
						all0 = true;
					}
					else {
						all1 = true;
					}
				}
			}
			if (all0 && all1) {
				isCompress[i] = -1;
				compress.push_back('(');
				Division(arr[i]);
			}
			else if (all0 && !all1) {
				compress.push_back('0');
				isCompress[i] = 0;
			}
			else if (!all0 && all1) {
				compress.push_back('1');
				isCompress[i] = 1;
			}
		}
	}
	compress.push_back(')');
}

int main() {
	Input();
	bool all0 = false;
	bool all1 = false;
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			if (map[j][k] == 0) {
				all0 = true;
			}
			else {
				all1 = true;
			}
		}
	}
	if (all0 && all1) {
		Division(map);
		Print();
	}
	else if (all0 && !all1) {
		printf("0");
	}
	else if (!all0 && all1) {
		printf("1");
	}
	
}