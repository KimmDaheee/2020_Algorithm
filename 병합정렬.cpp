#include <iostream>
using namespace std;
#define Max 10
int list[Max] = { 9, 10, 5, 7, 8, 6, 4, 3, 2, 1 };
int mergeList[Max];

void Out() {
	for (int i = 0; i < Max; i++) {
		printf("%d ", mergeList[i]);
	}
}

void Merge(int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= high) {
		if (list[i] < list[j]) {
			mergeList[k] = list[i];
			i++;
		}
		else {
			mergeList[k] = list[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		while (j <= high) {
			mergeList[k] = list[j];
			k++;
			j++;
		}
	}
	else {
		while (i <= mid) {
			mergeList[k] = list[i];
			k++;
			i++;
		}
	}

	for (int m = low; m <= high; m++) { list[m] = mergeList[m]; }

}

void MergeSort(int low, int high) {

	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(low, mid);
		MergeSort(mid+1, high);
		Merge(low, mid, high);
	}
}



int main() {
	cout << "½ÃÀÛ~" << endl;
	MergeSort(0, 9);
	Out();
}