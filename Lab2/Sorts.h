#pragma once
// ��� ����������:
//�	���������� �������
//�	���������� ���������
//�	���������� ���������
//�	���������� ��������
//�	������� ����������
//�	���������� �����(�� ����� ���� ��������� �������������������, ���������� ���������� � ������ ������������)
//�	������������� ����������
//�	Timsort
//�	IntroSort

const int RUN = 32;
const int M = 100;

void swap(int* a, int* b);
void merge(int* A, int low, int mid, int high);
unsigned partition(int* A, unsigned start, unsigned end);
void heapify(int* A, int N, int i);
int minn(int a, int b);
unsigned* sedgewickgaps(int size, unsigned* realsize);

void SelectionSort(int* A, unsigned N);
void InsertionSort(int* A, unsigned begin, unsigned end);
void BubbleSort(int* A, unsigned N);
void MergeSort(int* A, unsigned left, unsigned right);
void QuickSort(int* A, unsigned size);
void ShellSort1(int* A, unsigned N);
void ShellSort2(int* A, unsigned* gaps, unsigned size, unsigned* rsize);
void ShellSort3(int* A, unsigned N);
void HeapSort(int* A, unsigned begin, unsigned end);
void TimSort(int* A, unsigned N);
void IntroSort(int *data, unsigned begin, unsigned count);