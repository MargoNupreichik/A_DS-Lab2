#include "Sorts.h"
#include <cmath>


void SelectionSort(int* A, unsigned N)
{
	unsigned minIndex = 0;
	for (unsigned i = 1; i < N - 1; i++) {
		for (unsigned j = i + 1; j < N - 1; j++) {
			if (*(A + j) < *(A + minIndex)) {
				minIndex = j;
			}
		}
		swap(A[i], A[minIndex]);
	}
}

void InsertionSort(int* A, unsigned begin, unsigned end)
{
	int key = 0;
	unsigned inner = 0;
	for (unsigned i = begin + 1; i < end; i++) {
		key = *(A + 1);
		inner = i - 1;
		while (inner >= 0 && *(A + inner) > key) {
			swap(A[inner + 1], A[inner]);
			inner = inner - 1;
		}
		*(A + inner + 1) = key;
	}
}

void BubbleSort(int* A, unsigned N)
{
	int buff = 0;
	
	for (unsigned i = 0; i < N; i++) {
		for (unsigned j = 0; j < N - 1; j++) {
			if (*(A+j) < *(A + j + 1))
			{
				swap(A[j], A[j + 1]);
			}
		}
	}
	

}

void MergeSort(int* A, unsigned left, unsigned right)
{
	if (left >= right) {
		return;
	}

	unsigned mid = left + (right - left) / 2;
	
	MergeSort(A, left, mid);
	MergeSort(A, mid + 1, right);
	
	int *leftArr = new int[mid - left + 1]; 
	int *rightArr = new int[right - mid];
	
	for (int i = 0; i <= mid - left; i++) {
		leftArr[i] = A[left + i];
	}
	
	for (int i = 0; i < right - mid; i++) {
		rightArr[i] = A[mid + 1 + i];
	}
	
	merge(A, leftArr, mid - left + 1, rightArr, right - mid);
}

void QuickSort(int* A, unsigned start, unsigned end) {
	if (start >= end)
		return;

	// partitioning
	unsigned p = partition(A, start, end);

	// left part
	QuickSort(A, start, p - 1);

	// right part
	QuickSort(A, p + 1, end);
}

void ShellSort(int* A, unsigned N)
{
	for (unsigned gap = N / 2; gap > 0; gap /= 2)
	{
		for (unsigned i = gap; i < N; i += 1)
		{
			int temp = A[i];

			unsigned j = 0;
			for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
				A[j] = A[j - gap];

			A[j] = temp;
		}
	}
}

void HeapSort(int* A, unsigned begin, unsigned end)
{
	for (unsigned i = end / 2 - 1; i >= begin; i--) heapify(A, end, i);

	// one by one extract element from heap
	for (unsigned i = end - 1; i >= begin; i--) {
		// current root to end
		swap(A[begin], A[i]);

		// max heapify
		heapify(A, i, begin);
	}
}

void TimSort(int* A, unsigned N)
{
	// sorting individual subarrays of size RUN
	for (int i = 0; i < N; i += RUN)
		InsertionSort(A, i, minn((i + RUN - 1), (N - 1)));

	for (int size = RUN; size < N; size = 2 * size) {

		for (unsigned left = 0; left < N; left += 2 * size) {

			int mid = left + size - 1;
			int right = minn((left + 2 * size - 1), (N - 1));

			if (mid < right) {
				int* leftArr = new int[mid - left + 1];
				int* rightArr = new int[right - mid];

				for (int i = 0; i <= mid - left; i++) {
					leftArr[i] = A[left + i];
				}

				for (int i = 0; i < right - mid; i++) {
					rightArr[i] = A[mid + 1 + i];
				}
				merge(A, leftArr, mid - left + 1, rightArr, right - mid);
			}
		}
	}
}

void IntroSort(int* A, unsigned* begin, unsigned* end, int maxdepth)
{
	unsigned size = end - begin;
	
	if (size < 16) {
		InsertionSort(A, *begin, *end);
		return;
	}

	if (maxdepth == 0) {
		heapify(A, *begin, *(end) + 1);
		HeapSort(A, *begin, *(end) + 1);
		return;
	}

	unsigned* pivot = medianofthree(begin, begin + size / 2, end);
	
	IntroSort(A, begin, *(begin) + pivot - 1, maxdepth - 1);
	IntroSort(A, *(begin) + pivot + 1, end, maxdepth - 1);

}


void swap(int& a, int& b) {
	int buff = a;
	a = b;
	b = buff;
}

void merge(int *A, int *left, int leftSize, int* right, int rightSize) {
	unsigned i = 0, j = 0, k = 0;
	while (i < leftSize && j < rightSize) {
		if (left[i] <= right[j]) {
			A[k++] = left[i++];
		}
		else {
			A[k++] = right[j++];
		}
	}
	while (i < leftSize) {
		A[k++] = left[i++];
	}
	while (j < rightSize) {
		A[k++] = right[j++];
	}
}

unsigned partition(int* A, unsigned start, unsigned end)
{
	int pivot = A[start];

	unsigned count = 0;
	for (unsigned i = start + 1; i <= end; i++) {
		if (A[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	unsigned pivotIndex = start + count;
	swap(A[pivotIndex], A[start]);

	// Sorting left and right parts of the pivot element
	unsigned i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (A[i] <= pivot) {
			i++;
		}

		while (A[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(A[i++], A[j--]);
		}
	}

	return pivotIndex;
}

void heapify(int* A, int N, int i)
{
	unsigned largest = i; // Initialize largest as root Since we are using 0 based indexing
	unsigned l = 2 * i + 1; // left = 2*i + 1
	unsigned r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < N && A[l] > A[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < N && A[r] > A[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(A[i], A[largest]);

		heapify(A, N, largest);
	}
}

int minn(int a, int b) {
	if (a > b) return a;
	else return b;
}

unsigned* medianofthree(unsigned* a, unsigned* b, unsigned* c)
{
	if (*a < *b && *b < *c)
		return (b);

	if (*a < *c && *c <= *b)
		return (c);

	if (*b <= *a && *a < *c)
		return (a);

	if (*b < *c && *c <= *a)
		return (c);

	if (*c <= *a && *a < *b)
		return (a);

	if (*c <= *b && *b <= *a)
		return (b);
}