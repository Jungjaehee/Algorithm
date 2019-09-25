#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;
const int N = 10000;
void selectionSort(int *a, int n) {
	int minIndex, tmp;
	for (int i = 1; i < n; i++) {
		minIndex = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		tmp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = tmp;
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
	int *a = new int[N+1];
	int *b = new int[N + 1];
	int n = N+1;
	a[0] = rand();
	b[0] = -1;
	for (int i = 1; i < n; i++) {
		a[i] = rand();
		if (a[0] > a[i])
			a[0] = a[i] - 1;
	}
	clock_t start = clock();
	selectionSort(a, n);
	clock_t end = clock();
	cout << "정렬 : " << checkSort(a) << endl;
	cout << endl<<"수행시간 : "<<(double)(end-start)<<endl;
	return 0;
}