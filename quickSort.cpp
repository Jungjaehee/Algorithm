#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

const int N =10000;

int partition(int *a, int l, int r) {
	int v, i, j;
	i = l - 1;
	j = r;
	v = a[r];
	int tmp;
	while (true) {
		while (a[++i] < v);
		while (a[--j] > v &&j >= l);
		if (i > j)
			break;
		tmp = a[i]; 
		a[i] = a[j];
		a[j] = tmp;
	}
	tmp = a[i]; a[i] = a[r]; a[r] = tmp;
	return i;
}
void quickSort_basic(int *a, int l, int r) {
	int i;
	if (r > l) {
		i = partition(a, l, r);
		quickSort_basic(a, l, i - 1);
		quickSort_basic(a, i + 1, r);
	}
}
void insertionSort(int a[], int l, int r) {
	int v, j;
	int n = r - l + 1;
	for (int i = 2; i < n; i++) {
		v = a[i];
		j = i;
		while (a[j - 1] > v) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
	}
}
void quickSort_small_file(int a[], int l, int r, int M) {
	int i;
	if (r - l <= M) {
		insertionSort(a, l, r);
	}
	else {
		i = partition(a, l, r);
		quickSort_basic(a, l, i - 1);
		quickSort_basic(a, i + 1, r);
	}
}
void quickSort_center_partition(int a[], int l, int r) {
	int i, j, m, v,tmp;
	if (r - l > 1) { 
		m = (l + r) / 2; 
		if (a[l] > a[m]) {
			tmp = a[l]; a[l] = a[m]; a[m] = tmp;
		}
		if (a[l] > a[r]) {
			tmp = a[l]; a[l] = a[r]; a[r] = tmp;
		} 
		if (a[m] > a[r]) {
			tmp = a[m]; a[m] = a[r]; a[r] = tmp;
		}
		tmp = a[m]; a[m] = a[r-1]; a[r-1] = tmp;
		v = a[r - 1]; i = l; j = r - 1;
		for (; ; ) {
			while (a[++i] < v);
			while (a[--j] > v&&j >= l);
			if (i >= j) break;
			tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
		tmp = a[i]; a[i] = a[r - 1]; a[r - 1] = tmp;
		quickSort_basic(a, l, i - 1);
		quickSort_basic(a, i + 1, r);
	}
	else if (a[l] > a[r]) {
		tmp = a[l]; a[l] = a[r]; a[r] = tmp;
	}
}
bool checkSort(int *a) {
	for (int i = 1; i < N; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

int main(void) {
	srand((unsigned int)time(NULL));
	int *a = new int[N + 1];
	int l = 1, r = N;
	a[0] = -1;
	for (int i = 1; i < N+1; i++) {
		a[i] = rand();
	}
	int M = 5;
	clock_t start = clock();
	quickSort_basic(a, l, r);
	//quickSort_small_file(a, l, r, M);
	//quickSort_center_partition(a, l, r);
	clock_t end = clock();
	cout << "정렬 : " << checkSort(a)<<endl;
	cout << "수행시간 : " << (double)(end - start) << endl;
	free(a);
	return 0;
}