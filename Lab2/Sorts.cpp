#include "Sorts.h"
#include <cmath>

// +
void SelectionSort(int* A, unsigned size)
{
	unsigned minIndex = 0;
	for (unsigned i = 0; i < size - 1; i++) {
		for (unsigned j = i + 1; j < size; j++) {
			if (*(A + j) < *(A + minIndex)) {
				minIndex = j;
			}
		}
		int* pa = &(*(A + i));
		int* pb = &(*(A + minIndex));
		swap(pa, pb);
	}
}
// +
void InsertionSort(int* A, unsigned begin, unsigned end)
{
	int buff = A[begin];
	int keybuff = begin;
	for (unsigned i = begin + 1; i < end; i++) {
		buff = A[i];
		keybuff = i - 1;
		while (keybuff >= 0 && A[keybuff] > buff)
		{
			int* pa = &(*(A + keybuff + 1));
			int* pb = &(*(A + keybuff));
			swap(pa, pb);
			swap(pb, &buff);
			--keybuff;
		}
	}
}
// +
void BubbleSort(int* A, unsigned size)
{
	for (unsigned i = 0; i < size - 1; i++) {
		for (unsigned j = 0; j < size - 1 - i; j++) {
			if (*(A + j) > *(A + j + 1))
			{
				int* pa = &(*(A + j));
				int* pb = &(*(A + j + 1));
				swap(pa, pb);
			}
		}
	}
}
// +
void MergeSort(int* A, unsigned low, unsigned high)
{
	if (low >= high)
		return;

	int mid = low + (high - low) / 2;
	MergeSort(A, low, mid);
	MergeSort(A, mid + 1, high);
	merge(A, low, mid, high);
}
// +
void QuickSort(int* A, unsigned size) 
{
	int i = 0;
	int j = size - 1;
	int mid = A[size / 2];

	do {
		while (A[i] < mid) {
			i++;
		}
		while (A[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		QuickSort(A, j + 1);
	}
	if (i < size) {
		QuickSort(&(A[i]), size - i);
	}
}
// + Шелл
void ShellSort1(int* A, unsigned size)
{
	for (unsigned gap = size / 2; gap > 0; gap /= 2)
	{
		for (unsigned i = gap; i < size; i += 1)
		{
			int temp = A[i];

			unsigned j = 0;
			for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
				A[j] = A[j - gap];

			A[j] = temp;
		}
	}
}
// Седжвик
void ShellSort2(int* A, unsigned l, unsigned r)
{
	int h;
	for (h = 1; h <= (r - l) / 9; h = 3 * h + 1);
	for (; h > 0; h /= 3)
		for (int i = l + h; i <= r; i++)
		{
			int j = i; int v = A[i];
			while (j >= l + h && v < A[j - h])
			{
				A[j] = A[j - h]; j -= h;
			}
			A[j] = v;
		}
}
// Хиббард
void ShellSort3(int* A, unsigned size) {
	for (int i = 1; i < size; i++) {
		int d = exp2(i) - 1;
		if (d <= size)  
			for (int k = 0; k < size - d; k++) {
				int j = k;
				while (j >= 0 && A[j] > A[j + d]) {
					int number = A[j];
					A[j] = A[j + d];
					A[j + d] = number;
					j--;
				}
			}
	}
}
// +
void HeapSort(int* A, unsigned begin, unsigned end)
{
	for (int i = end / 2 - 1; i >= 0; i--)
		heapify(A, end, i);

	for (int i = end - 1; i >= 0; i--) {
		int* pa = &(*(A));
		int* pb = &(*(A + i));
		swap(pa, pb);
		heapify(A, i, 0);
	}
}
// +
void TimSort(int* A, unsigned sizeup)
{
	for (int i = 0; i < sizeup; i += RUN)
		InsertionSort(A, i, minn((i + RUN - 1), (sizeup - 1)));

	for (int size = RUN; size < sizeup; size *= 2) { // при попытке отследить, что происходит при заходе в цикл, программа падает
		// соообщение следующее: запись в память вне буфера

		for (unsigned left = 0; left < sizeup; left += 2 * size) {

			int mid = left + size - 1;
			int right = minn((left + 2 * size - 1), (sizeup - 1));

			if (mid < right) {
				merge(A, left, mid, right);  
			}
		}
	}
}
// +
void IntroSort(int* data, unsigned begin, unsigned count) {
	int partitionSize = partition(data, 0, count - 1);

	if (partitionSize < 16)
	{
		InsertionSort(data, 0, count);
	}
	else if (partitionSize > (2 * log(count)))
	{
		HeapSort(data, 0, count);
	}
	else
	{
		QuickSort(data, count - 1);
	}
}


void swap(int* a, int* b) {
	int temp_a = *a;
	*a = *b;
	*b = temp_a;
}

void merge(int* A, int low, int mid, int high) {
	int const subArrayOne = mid - low + 1;
	int const subArrayTwo = high - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = A[low + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = A[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = low;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			A[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			A[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		A[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		A[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

unsigned partition(int* A, unsigned left, unsigned right)
{
	int pivot = A[right];
	int temp;
	int i = left;

	for (int j = left; j < right; ++j)
	{
		if (A[j] <= pivot)
		{
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
		}
	}

	A[right] = A[i];
	A[i] = pivot;

	return i;
}

void heapify(int* A, int size, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// If the left child is larger than the root.
	if (l < size && A[l] > A[largest])
		largest = l;

	// If the right child is larger.
	if (r < size && A[r] > A[largest])
		largest = r;

	int* pa = nullptr;
	int* pb = nullptr;

	// If the root is not the largest.
	if (largest != i) {
		pa = &(*(A + i)); pb = &(*(A + largest));
		swap(pa, pb);

		// Heapifying the sub-tree repeatedly.
		heapify(A, size, largest);
	}
}

int minn(int a, int b) {
	if (a > b) return b;
	else return a;
}

unsigned medianofthree(unsigned a, unsigned b, unsigned c)
{
	if (a < b && b < c)
		return b;

	if (a < c && c <= b)
		return c;

	if (b <= a && a < c)
		return a;

	if (b < c && c <= a)
		return c;

	if (c <= a && a < b)
		return a;

	if (c <= b && b <= a)
		return b;
}