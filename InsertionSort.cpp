#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;

const int N = 30000;
void insertionSort(int a[], int n) {
	int v, j;
	for (int i = 2; i < n; i++) {
		v = a[i];
		j = i;
		while (a[j-1] > v) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
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
	int* a = new int[N+1];
	int* b = new int[N + 1];
	int n = N+1;
	a[0] = -1;
	for (int i = 1; i < n; i++) {
		a[i] = rand();
	}
	
	clock_t start = clock();
	insertionSort(a, n);
	clock_t end = clock();
	cout << "정렬 : " << checkSort(a) << endl;
	cout << endl << "실행시간 : " << (end - start) << endl;
	return 0;
}