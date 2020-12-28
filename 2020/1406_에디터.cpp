#include <iostream>
#include <list>
using namespace std;

list<char> arr;
int n;
string str;
char command[500001];
char commandNum[500001];

void input() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) 
	{
		arr.push_back(str[i]);
	}
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> command[i];
		if (command[i] == 'P') cin >> commandNum[i];
	}
}



int main() {
	input();

	auto itor = arr.end();
	for (int i = 0; i < n; i++) 
	{
		switch (command[i]) {
		case 'L':
			if(!(itor==arr.begin())) itor--;
			break;
		case 'D':
			if (!(itor == arr.end())) itor++;
			break;
		case 'B':
			if (!(itor == arr.begin())) {
				itor--;
				itor = arr.erase(itor);
			}
			break;
		case 'P':
			arr.insert(itor, commandNum[i]);
			break;

		}
	}
	


	itor = arr.begin();
	for (int i = 0; i < arr.size(); i++) {
		if(*itor!=' ') cout << *itor;
		itor++;
	}

}