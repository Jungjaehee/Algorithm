#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;

const int N = 100000;

void shellSort(int a[], int n) {
	int h, v, j,i;
	for (h = 1; h < n-1;h= h * 3 + 1);
	for (; h > 0; h /= 3) {
		for (i = h + 1; i < n-1; i++) {
			v = a[i];
			j = i;
			while (j > h && a[j - h] > v) {
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = v;
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
	srand((unsigned int)time(0));
	int* a = new int[N + 1];
	int* b = new int[N + 1];
	int n = N + 1;
	a[0] = -1;
	for (int i = 1; i < n; i++) {
		a[i] = rand();
	}
	clock_t start = clock();
	shellSort(a, n);
	clock_t end = clock();
	cout << "정렬 : " << checkSort(a) << endl;
	cout << endl << "실행시간 : " << (double)(end - start) << endl;
	return 0;
}