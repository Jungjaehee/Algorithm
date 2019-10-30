#include "natualmergesort.h"
#include <vector>
using namespace std;
int sortedIndex(int *a, int n, int start) {
	int i=start;
	for (i = start; i < n; i++) {
		if (a[i] > a[i + 1])
			break;
	}
	return i;
}
void makeRun(int a[], int n, vector<int>& ary) {
	int index;
	ary.push_back(0);
	for (int i = 1; i <= n; i++) {
		index = sortedIndex(a, n, i);
		ary.push_back(index);
		i = index;
	}
}
void natualMergeSort(int a[], int n) {
	vector<int> ary;
	makeRun(a, n, ary);
	int* b = new int[n+1];
	b[0] = -1;
	int x,y;
	if (ary.size() < 3)
		return;
	for (int i = 2; i < ary.size(); i++) {
		x = 1; y = 1;
		for (int j = 1; j <= ary.at(i); j++) {
			if (x > (ary.at(i) - ary.at(i - 1))) {
				b[j] = a[ary.at(0) + y];
				y++;
			}
			else if (y > ary.at(i-1)) {
				b[j] = a[ary.at(i-1) + x];
				x++;
			}
			else if (a[ary.at(0)+y] > a[ary.at(i - 1)+x]) {
				b[j] = a[ary.at(i - 1) + x];
				x++;
			}
			else {
				b[j] = a[ary.at(0) + y];
				y++;
			}
		}
		for (int j = 1; j <= ary.at(i); j++)
			a[j] = b[j];
	}
}