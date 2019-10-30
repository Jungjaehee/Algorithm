#pragma once
#ifndef	NATUALMERGESORT_H
#define NATUALMERGESORT_H
#include <vector>
int sortedIndex(int *a, int n, int start);
void makeRun(int a[], int n, std::vector<int>& ary);
void natualMergeSort(int a[], int n);
#endif