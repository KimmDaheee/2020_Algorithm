#include <iostream>
#include <math.h>
using namespace std;
#define MAX_SIZE 20000001

int n, m;
int arr[MAX_SIZE] = { 0, };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		int a;
		scanf("%d", &a);
		if (a < 0) 
		{ 
			a = abs(a);
			arr[2 * a - 1] = 1; 
		}
		else arr[2 * a] = 1;
	}
	cin >> m;
}

int main() {
	input();
	for (int i = 0; i < m; i++) 
	{
		int a;
		scanf("%d", &a);
		if (a < 0)
		{ 
			a = abs(a);
			a = 2 * a - 1; 
		}
		else a = 2 * a;

		if (arr[a] == 1) printf("1 ");
		else printf("0 ");
	}

}