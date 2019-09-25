#include <iostream>
using namespace std;

void exchangeSort(int *a, int n) {
	int i, tmp, j;
	for (i = 1; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}

		}
	}
}

int main(void) {
	int a[11] = { -1, 3, 5, 10, 4, 2, 5, 32, 100, 1, 10 };
	exchangeSort(a, 11);
	for (int i = 1; i < 11; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
