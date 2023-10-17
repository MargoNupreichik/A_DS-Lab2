#pragma once
// ¬се сортировки:
//Х	—ортировка выбором
//Х	—ортировка вставками
//Х	—ортировка пузырьком
//Х	—ортировка сли€нием
//Х	Ѕыстра€ сортировка
//Х	—ортировка Ўелла(не менее трех различных последовательностей, желательно привод€щих к разным асимптотикам)
//Х	ѕирамидальна€ сортировка
//Х	Timsort
//Х	IntroSort

const int RUN = 32;
const int N = 100;

void swap(int* a, int* b);
void merge(int* A, int low, int mid, int high);
unsigned partition(int* A, unsigned start, unsigned end);
void heapify(int* A, int N, int i);
int minn(int a, int b);
unsigned medianofthree(unsigned a, unsigned b, unsigned c);

void SelectionSort(int* A, unsigned N);
void InsertionSort(int* A, unsigned begin, unsigned end);
void BubbleSort(int* A, unsigned N);
void MergeSort(int* A, unsigned left, unsigned right);
void QuickSort(int* A, unsigned size);
void ShellSort(int* A, unsigned N);
void HeapSort(int* A, unsigned begin, unsigned end);
void TimSort(int* A, unsigned N);
void IntroSort(int *data, unsigned begin, unsigned count);