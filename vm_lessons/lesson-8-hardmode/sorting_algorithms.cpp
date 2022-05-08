#include "sorting_algorithms.h"
#include <cstdio>
#include <iostream>

using namespace std;

void Print_Array(int* array, int size) {
	cout << endl;
	cout << "* Your Array Start *" << endl;
	cout << "--------------------" << endl;
	for (int i = 0; i < size; i++) {
		cout << "[" << array[i] << "] ";
	}
	cout << endl;
	cout << "--------------------" << endl;
	cout << "*  Your Array End  *" << endl;
	cout << endl;
}

void Bubble_Sort(int* array, int size) {
	clock_t start, end;
	
	cout << "-------------------------" << endl;
	cout << "| Bubble Sort Algorithm |" << endl;
	cout << "-------------------------" << endl;

	start = clock();
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) { 
				swap(array[j], array[j + 1]);
			}
		}
	}
	
	end = clock();
	
	cout << "Bubble sort execution time: " << end - start << endl;
}


void Selection_Sort(int* array, int size) {}
void Insertion_Sort(int* array, int size) {}
void Shell_Sort(int* array, int size) {}
void Quick_Sort(int* array, int size) {}