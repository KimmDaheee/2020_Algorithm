#include <iostream>
using namespace std;
#define Max 129


int n;
//white 0, blue 1
int map[Max][Max];
int white = 0;
int blue = 0;

void Input() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}
}

void Print(int white, int blue) {
	cout << white << endl;
	cout << blue;
}

void MakePaper(int n, int y, int x) {
	if (n == 1) {
		if (map[y][x] == 0) white++;
		else blue++;
		return;
	}

	bool allWhite = true;
	bool allBlue = true;

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (map[i][j] == 0) {
				allBlue = false;
			}
			else {
				allWhite = false;
			}
			if (allBlue == false && allWhite == false) break;
		}
	}

	if (allWhite) white++;
	else if(allBlue)blue++;
	else {
		int half = n / 2;
		MakePaper(half, y, x);
		MakePaper(half, y, x + half);
		MakePaper(half, y + half, x);
		MakePaper(half, y + half, x + half);
	}
	return;
}

int main() {
	Input();
	MakePaper(n, 0, 0);
	Print(white, blue);
}

