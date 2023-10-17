// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//1.	Реализовать следующие алгоритмы сортировки :
//•	Сортировка выбором
//•	Сортировка вставками
//•	Сортировка пузырьком
//•	Сортировка слиянием
//•	Быстрая сортировка
//•	Сортировка Шелла(не менее трех различных последовательностей, желательно приводящих к разным асимптотикам)
//•	Пирамидальная сортировка
//•	Timsort
//•	IntroSort

#include <iostream>
#include <locale>
#include "Sorts.h"

using namespace std;

int* copyarray(int array[]);
void printarray(int arr[], unsigned N);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Выполнила: Нупрейчик Маргарита, гр. 2309" << endl;
	
	short currentMethod = 0;
	
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
	
	clock_t start; double time;

	while (currentMethod) {
		cout << "Массив до сортировки:" << endl;
		printarray(ReverseSorted, N);

		int* newArray1 = copyarray(ReverseSorted);
		
		cout << "\nСоздана копия массива." << endl;

		switch (currentMethod) {
		case 1:
		{
			cout << "\nSelectionSort" << endl;
			start = clock();
			SelectionSort(newArray1, N);
			time = double(clock() - start);
			cout << " Время выполнения: " << fixed << time << endl;
		}
		break;
		case 2:
		
			cout << "\nInsertionSort" << endl;
			start = clock();
			InsertionSort(newArray1, 0, N);
			time = double(clock() - start);
			cout << "Время выполнения: " << fixed << time << endl;
		
		break;
		case 3:
			cout << "\nBubbleSort" << endl;
			start = clock();
			BubbleSort(newArray1, N);
			time = double(clock() - start);
			cout << " Время выполнения: " << fixed << time << endl;
			break;
		case 4:
			cout << "\nMergeSort" << endl;
			start = clock();
			MergeSort(newArray1, 0, N - 1);
			time = double(clock() - start);
			cout << "Время выполнения: " << fixed << time << endl;
			break;
		case 5:
			cout << "\nQuickSort" << endl;
			start = clock();
			QuickSort(newArray1, N);
			time = double(clock() - start);
			cout << "Время выполнения: " << fixed << time << endl;
		
		break;
		case 6:
			cout << "\nShellSort" << endl;
			start = clock();
			ShellSort(newArray1, N);
			time = double(clock() - start);
			cout << "Время выполнения: " << fixed << time << endl;
		break;
		case 7:
			cout << "\nHeapSort" << endl;
			start = clock();
			HeapSort(newArray1, 0, N);
			time = double(clock() - start);
			cout << "Время выполнения: " << fixed << time << endl;
		break;
		case 8:
			cout << "\nTimSort" << endl;
			start = clock();
			TimSort(newArray1, N);
			time = double(clock() - start);
			cout << "Время выполнения: " << fixed << time << endl;
			break;
		case 9:
			cout << "\nIntroSort" << endl;
			start = clock();

			IntroSort(newArray1, 0, N);

			time = double(clock() - start);

			cout << "Время выполнения: " << fixed << time << endl;
			break;
		case 0:
			cout << "\nРабота программы завершена.";
			break;
		default: cout << "Недопустимое значение.\n";
		}
		
		cout << "Массив после сортировки:" << endl;
		printarray(newArray1, N);
		
		delete[] newArray1;
		
		cout << endl;
		cin >> currentMethod;
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