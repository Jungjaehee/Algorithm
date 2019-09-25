#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;
const int N = 50000;

void bubbleSort(int a[], int n) {
	int tmp;
	for (int i = n-1; i > 1; i--) {
		for (int j = 1; j < i; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp;
			}
		}
	}
}
bool checkSort(int *a) {
	for (int i = 1; i < N; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}
int main() {
	srand((unsigned int)time(NULL));
	int* a = new int[N+1];
	int n = N+1;
	a[0] = -1;
	for (int i = 1; i < n; i++) {
		a[i] = rand();
	}
	clock_t start = clock();
	bubbleSort(a, n);
	clock_t end = clock();
	cout << "정렬 : " << checkSort(a)<< endl;
	cout << endl << "실행시간 : " << (double)(end - start) << endl;
	return 0;
}