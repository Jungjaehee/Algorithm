#include <iostream>
using namespace std;

void cocktailShaker(int *a, int n) {
	int i = 1;
	int x, y, tmp;
	while (i <= n / 2) {
		for (x = i; x < (n - i); x++) {
			if (a[x] > a[x + 1]) {
				tmp = a[x];
				a[x] = a[x + 1];
				a[x + 1] = tmp;
			}
		}
		for (y = n - i; y > i; y--) {
			if (a[y] < a[y - 1]) {
				tmp = a[y];
				a[y] = a[y - 1];
				a[y - 1] = tmp;
			}
		}
		i++;
	}
}
int main(void) {
	int a[11] = { -1, 3, 5, 10, 4, 2, 5, 32, 100, 1, 10 };
	cocktailShaker(a, 11);

	for (int i = 1; i < 11; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}