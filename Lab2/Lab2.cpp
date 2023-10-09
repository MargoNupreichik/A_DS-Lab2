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

const int N = 100;

int main()
{
	cout << "Выполнила: Нупрейчик Маргарита, гр. 2309" << endl;
	short currentMethod = 0;
	cout << "Введите число от 1 по 9 (число соответствует порядковому\nномеру из списка реализуемых сортировок)." << endl;
	cout << "Если вы хотите завершить работу программы, введите 0." << endl;
	cout.precision(10);
	cin >> currentMethod;
	while (currentMethod) {
		switch (currentMethod) {
		case 1:
		{
			cout << "SelectionSort" << endl;
			clock_t start = clock();

			double time = double(clock() - start);
			cout << " Время выполнения: " << fixed << time << endl;
		}
		break;
		case 2:
		
			cout << "InsertionSort" << endl;
			clock_t start = clock();

			double time = double(clock() - start);
			cout << " Время выполнения: " << fixed << time << endl;
		
		break;
		case 3:
			cout << "BubbleSort" << endl;
			clock_t start = clock();
			double time = double(clock() - start);

			cout << " Время выполнения: " << fixed << time << endl;
			break;
		case 4:
			cout << "MergeSort" << endl;
			clock_t start = clock();
			double time = double(clock() - start);

			cout << " Время выполнения: " << fixed << time << endl;
			break;
		case 5:
			// Вставка перед элеентом с определенным индексом.
		
			cout << "QuickSort" << endl;
			clock_t start = clock();
			double time = double(clock() - start);

			cout << " Время выполнения: " << fixed << time << endl;
		
		break;
		case 6:
			cout << "ShellSort" << endl;
			clock_t start = clock();
			double time = double(clock() - start);

			cout << " Время выполнения: " << fixed << time << endl;
		break;
		case 7:
			cout << "HeapSort" << endl;
			clock_t start = clock();
			double time = double(clock() - start);

			cout << " Время выполнения: " << fixed << time << endl;
		break;
		case 8:
			cout << "TimSort" << endl;
			clock_t start = clock();
			double time = double(clock() - start);

			cout << " Время выполнения: " << fixed << time << endl;
			break;
		case 9:
			cout << "IntroSort" << endl;
			clock_t start = clock();
			double time = double(clock() - start);

			cout << " Время выполнения: " << fixed << time << endl;
			break;
		case 0:
			cout << "Работа программы завершена.";
			break;
		default: cout << "Недопустимое значение.\n";
		}
		cin >> currentMethod;
	}
    
}
