// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include "Sorts.h"


using namespace std;

int* copyarray(int array[], unsigned length);

int* reversedarray(int size);
int* sortedarray(int size);
int* randomarray(int size);
int* nearlysortedarray(int size);

bool ismember(int* arr, int size, int comp);

void printarray(int arr[], unsigned M);

const int numarr = 10;
const int eacharr = 4;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Выполнила: Нупрейчик Маргарита, гр. 2309" << endl;
	
	short currentMethod = 0;
	
	// генерация указателей на массивы разных размеров по типам массивов.
	int** reversedarrays = new int* [numarr];
	int** sortedarrays = new int* [numarr];
	int** nearlysortedarrays = new int* [numarr];
	int** randomarrays = new int* [numarr];
	// заполнение обратно отсортированных
	for (int i = 0; i < numarr; i++) {
		reversedarrays[i] = reversedarray((i+1)*M);
	}
	// заполнение отсортированных
	for (int i = 0; i < numarr; i++) {
		sortedarrays[i] = sortedarray((i + 1) * M);
	}
	// заполнение почти отсортированных
	for (int i = 0; i < numarr; i++) {
		nearlysortedarrays[i] = nearlysortedarray((i + 1) * M);
	}
	// заполнение рандомное
	for (int i = 0; i < numarr; i++) {
		randomarrays[i] = randomarray((i + 1) * M);
	}

	cout << "Введите число от 1 по 9 (число соответствует порядковому\nномеру из списка реализуемых сортировок)." << endl;
	cout << "Если вы хотите завершить работу программы, введите 0." << endl;
	
	cout.precision(8);
	cin >> currentMethod;
	
	clock_t start; 
	double time;

	double timecopy, timedelete; 

	while (currentMethod) {

		cout << "\nСоздана копия массива." << endl;

		switch (currentMethod) {
		case 1:
		{
			cout << "\nSelectionSort" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j+1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);

				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(reversedarrays[j], (j+1) * M);
					SelectionSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					SelectionSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					SelectionSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					SelectionSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
		}
		break;
		case 2:
			cout << "\nInsertionSort" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					InsertionSort(newArray1, 0, (j + 1)* M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 10000; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					InsertionSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 10000 * timecopy - 10000 * timedelete) / 10000);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					InsertionSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					InsertionSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			
		break;
		case 3:
			cout << "\nBubbleSort" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					BubbleSort(newArray1, (j + 1)* M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					BubbleSort(newArray1, (j + 1)* M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					BubbleSort(newArray1, (j + 1)* M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					BubbleSort(newArray1, (j + 1)* M);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			
			break;
		case 4:
			cout << "\nMergeSort" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					MergeSort(newArray1, 0, (j + 1) * M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					MergeSort(newArray1, 0, (j + 1) * M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					MergeSort(newArray1, 0, (j + 1) * M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 100; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					MergeSort(newArray1, 0, (j + 1) * M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 100 * timecopy - 100 * timedelete) / 100);
				cout << fixed << time << endl;
			}
			break;
		case 5:
			cout << "\nQuickSort" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					QuickSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					QuickSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					QuickSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					QuickSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
		
		break;
		case 6:
			cout << "\nShellSort" << endl;
			
			cout << "Shell gap" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					ShellSort1(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					ShellSort1(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					ShellSort1(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					ShellSort1(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			
			cout << "Sedgewick gap" << endl;
			
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					ShellSort2(newArray1, 0, (j + 1) * M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					ShellSort2(newArray1, 0, (j + 1) * M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					ShellSort2(newArray1, 0, (j + 1)* M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					ShellSort2(newArray1, 0, (j + 1)* M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			
			cout << "Hibbard gap" << endl;
			
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					ShellSort3(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					ShellSort3(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					ShellSort3(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					ShellSort3(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
		break;
		case 7:
			cout << "\nHeapSort" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					HeapSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					HeapSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					HeapSort(newArray1, 0,(j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					HeapSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			
		break;
		case 8:
			cout << "\nTimSort" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					TimSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					TimSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					TimSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					TimSort(newArray1, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			
			break;
		case 9:
			cout << "\nIntroSort" << endl;
			cout << "Reverse sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(reversedarrays[j], (j + 1) * M);
					IntroSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout  << fixed << time << endl;
			}
			cout << "Sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
					IntroSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout << fixed << time << endl;
			}
			cout << "Nearly sorted" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(nearlysortedarrays[j], (j + 1) * M);
					IntroSort(newArray1, 0, (j + 1) * M - 1);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout  << fixed << time << endl;
			}
			cout << "Random" << endl;
			for (int j = 0; j < numarr; j++) {
				start = clock();
				int* newArray1 = copyarray(sortedarrays[j], (j + 1) * M);
				timecopy = double(clock() - start);
				start = clock();
				delete[] newArray1;
				timedelete = double(clock() - start);
				start = clock();
				for (int i = 0; i < 1000; i++) {
					newArray1 = copyarray(randomarrays[j], (j + 1) * M);
					IntroSort(newArray1, 0, (j + 1) * M);
					delete[] newArray1;
				}
				time = double((clock() - start - 1000 * timecopy - 1000 * timedelete) / 1000);
				cout <<  fixed << time << endl;
			}

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

	// очистка памяти (! здесь проблема при попытке очистить)
	for (int i = 0; i < numarr; ++i) {
		if (reversedarrays[i] != NULL) {
			delete reversedarrays[i];
			reversedarrays[i] = NULL;
		}
	}
	for (int i = 0; i < numarr; ++i) {
		if (sortedarrays[i] != NULL) {
			delete sortedarrays[i];
			sortedarrays[i] = NULL;
		}
	}
	for (int i = 0; i < numarr; ++i) {
		if (nearlysortedarrays[i] != NULL) {
			delete nearlysortedarrays[i];
			nearlysortedarrays[i] = NULL;
		}
	}
	for (int i = 0; i < numarr; ++i) {
		if (randomarrays[i] != NULL) {
			delete randomarrays[i];
			randomarrays[i] = NULL;
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

int* copyarray(int array[], unsigned length) {
	int* newArr = new int[length];
	for (unsigned i = 0; i < length; i++) {
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
