#include "tournamentsort.h"

void tournament(int *b, int size, int start) {
	int i = start;
	int end = size - 1;
	int n = (size-start)/2;
	int tmp;
	while (i > 1) {
		tmp=n;
		for (int j = i; j < end; j += 2) {
			b[j-n] = b[j] > b[j + 1] ? b[j] : b[j + 1];
			n++;
		}
		end =i;
		i = i-tmp;
		n = (tmp + 1) / 2;
	}
}
void tournamentSort(int a[], int n) {
	int size = 0;
	int i = n;
	while (i>1) {
		size += i;
		i = (i + 1) / 2;
	}
	size += 3;
	int *b = new int[size];
	b[size - 1] = 0;
	int j = 0;
	int start = size - n - 1;
	for (int i = 0; i < size-1 ; i++) {
		if (i >=start) 
			b[i] = a[++j];
		else
			b[i] = 0;
	}
	int cnt = 0;
	while (cnt < n) {
		tournament(b, size, start);
		a[n - cnt] = b[1];
		for (int i = 1; i < size; i++) {
			if (b[i] == a[n - cnt])
				b[i] = 0;
		}
		cnt++;
	}
}
