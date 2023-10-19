// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include "Sorts.h"


using namespace std;

int* copyarray(int array[]);

int* reversedarray(int size);
int* sortedarray(int size);
int* randomarray(int size);
int* nearlysortedarray(int size);

bool ismember(int* arr, int size, int comp);

void printarray(int arr[], unsigned N);

const int numarr = 10;
const int eacharr = 4;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Выполнила: Нупрейчик Маргарита, гр. 2309" << endl;
	
	short currentMethod = 0;
	
	// генерация указателей на массивы разных размеров. каждый указатель указывает на 4 массива.
	int* myarrays[numarr][eacharr];

	for (int i = 0; i < numarr; i++) {
		for (int j = 0; j < eacharr; j++) {
			if (j == 0) {
				// reverse
				myarrays[i][j] = reversedarray((i + 1) * N);
			}
			else if (j == 1) {
				// sorted
				myarrays[i][j] = sortedarray((i + 1) * N);
			}
			else if (j == 2) {
				// nearly sorted
				myarrays[i][j] = nearlysortedarray((i + 1) * N);
			}
			else if (j == 3) {
				// random array
				myarrays[i][j] = randomarray((i + 1) * N);
			}
		}
	}
	

	int ReverseSorted[N] = { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 
		86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 
		68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 
		50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 
		32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 
		14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	cout << "Введите число от 1 по 9 (число соответствует порядковому\nномеру из списка реализуемых сортировок)." << endl;
	cout << "Если вы хотите завершить работу программы, введите 0." << endl;
	
	cout.precision(10);
	cin >> currentMethod;
	
	clock_t start; 
	double time;

	double timecopy, timedelete; 

	while (currentMethod) {

		start = clock();
		int* newArray1 = copyarray(ReverseSorted);
		timecopy = double(clock() - start);
		
		start = clock();
		delete[] newArray1;
		timedelete = double(clock() - start);

		cout << "\nСоздана копия массива." << endl;

		switch (currentMethod) {
		case 1:
		{
			cout << "\nSelectionSort" << endl;
			start = clock();
			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				SelectionSort(newArray1, N);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
			cout << " Время выполнения: " << fixed << time << endl;
		}
		break;
		case 2:
			cout << "\nInsertionSort" << endl;
			start = clock();

			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				InsertionSort(newArray1, 0, N);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
			cout << "Время выполнения: " << fixed << time << endl;
		
		break;
		case 3:
			cout << "\nBubbleSort" << endl;
			start = clock();
			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				BubbleSort(newArray1, N);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
			cout << " Время выполнения: " << fixed << time << endl;
			break;
		case 4:
			cout << "\nMergeSort" << endl;
			start = clock();
			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				MergeSort(newArray1, 0, N - 1);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
			cout << "Время выполнения: " << fixed << time << endl;
			break;
		case 5:
			cout << "\nQuickSort" << endl;
			start = clock();
			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				QuickSort(newArray1, N);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
			cout << "Время выполнения: " << fixed << time << endl;
		
		break;
		case 6:
			cout << "\nShellSort" << endl;
			start = clock();
			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				ShellSort(newArray1, N);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
			cout << "Время выполнения: " << fixed << time << endl;
		break;
		case 7:
			cout << "\nHeapSort" << endl;
			start = clock();
			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				HeapSort(newArray1, 0, N);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
			cout << "Время выполнения: " << fixed << time << endl;
		break;
		case 8:
			cout << "\nTimSort" << endl;
			start = clock();
			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				TimSort(newArray1, N);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
			cout << "Время выполнения: " << fixed << time << endl;
			break;
		case 9:
			cout << "\nIntroSort" << endl;
			start = clock();
			for (int i = 0; i < 1000; i++) {
				newArray1 = copyarray(ReverseSorted);
				IntroSort(newArray1, 0, N);
				delete[] newArray1;
			}
			time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);

			cout << "Время выполнения: " << fixed << time << endl;
			break;
		case 0:
			cout << "\nРабота программы завершена.";
			break;
		default: cout << "Недопустимое значение.\n";
		}
		cout << "Процесс завершен." << endl;
		cout << endl;
		cin >> currentMethod;
	}

	for (int i = 0; i < numarr; i++) {
		for (int j = 0; j < eacharr; j++) {
			delete[] myarrays[i][j];
		}
	}

}

void printarray(int arr[], unsigned N)
{
	for (unsigned i = 0; i < N; i++) {
		cout << arr[i] << " ";
		if (i % 10 == 0 && i != 0) cout << endl;
	}
}

int* copyarray(int array[]) {
	int* newArr = new int[N];
	for (unsigned i = 0; i < N; i++) {
		*(newArr + i) = array[i];
	}
	return newArr;
}

int* reversedarray(int size)
{
	int* pointer = new int[size];
	for (int i = size - 1; i >= 0; i--) {
		pointer[size - i - 1] = i;
	}
	return pointer;
}

int* sortedarray(int size)
{
	int* pointer = new int[size];
	for (int i = 0; i < size; i++) {
		pointer[i] = i;
	}
	return pointer;
}

int* randomarray(int size)
{
	int* pointer = new int[size];
	int i = 0;
	while (i < size) {
		int b = rand() % size;
		if (ismember(pointer, i, b)) { continue; }
		else {
			pointer[i] = b;
			++i;
		}
	}
	return pointer;
}

int* nearlysortedarray(int size)
{
	int* pointer = sortedarray(size);
	int temp = pointer[0];
	pointer[0] = pointer[size - 1];
	pointer[size - 1] = temp;
	return pointer;
}

bool ismember(int* arr, int size, int comp)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == comp) {
			return true;
		}
	}
	return false;
}
