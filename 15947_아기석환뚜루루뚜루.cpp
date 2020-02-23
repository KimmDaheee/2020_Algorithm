#include <iostream>
#include <string>
using namespace std;

void Answer(int num) {
	//몇 번째 노래인지. 0번째 부터 시작
	int line = num / 14;
	//노래 안 몇 번째 단어.인지 
	int word = num % 14;
	string numWord;

	if (word == 0) {
		cout << "sukhwan";
		return;
	}

	if (word % 4 == 3) {
		if (line < 3) {
			numWord = "tururu";
			for (int i = 0; i < line; i++) {
				numWord += "ru";
			}
		}
		else {
			numWord = "tu+ru*";
			cout << numWord << line+2;
			return;
		}
	}

	else if (word % 4 == 0) {
		if (line < 4) {
			numWord = "turu";
			for (int i = 0; i < line; i++) {
				numWord += "ru";
			}
		}
		else {
			numWord = "tu+ru*";
			cout << numWord << line + 1;
			return;
		}
	}
	
	else {
		if (word == 1 || word == 13) {
			numWord = "baby";
		}
		else if (word == 2 || word == 14) {
			numWord = "sukhwan";
		}
		else if (word == 5) {
			numWord = "very";
		}
		else if (word == 6) {
			numWord = "cute";
		}
		else if (word == 9) {
			numWord = "in";
		}
		else if(word == 10){
			numWord = "bed";
		}
	}

	cout << numWord;

}

int main() {
	int num;
	cin >> num;

	Answer(num);
}