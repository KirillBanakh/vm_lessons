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


void Selection_Sort(int* array, int size) {
	clock_t start, end;
	int k, j;

	cout << "----------------------------" << endl;
	cout << "| Selection Sort Algorithm |" << endl;
	cout << "----------------------------" << endl;

	start = clock();

	for (int i = 0; i < size - 1; i++) {
		for (k = i, j = i + 1; j < size; j++) {
			if (array[j] < array[k]) {
				k = j;
			}
		}
		swap(array[k], array[i]);
	}

	end = clock();

	cout << "Selection sort execution time: " << end - start << endl;
}

void Insertion_Sort(int* array, int size) {
	clock_t start, end;
	int j;

	cout << "----------------------------" << endl;
	cout << "| Insertion Sort Algorithm |" << endl;
	cout << "----------------------------" << endl;
	
	start = clock();
	
	for (int i = 1; i <= size - 1; i++) {
		j = i;
		while (array[j] < array[j - 1] && j >= 1) {
			swap(array[j], array[j - 1]);
			j--;
		}
	}

	end = clock();
	cout << "Insertion sort execution time: " << end - start << endl;
}

void Shell_Sort(int* array, int size) {
	clock_t start, end;
	int j, temp, gap;
	int d[] = { 9, 5, 3, 2, 1 };

	cout << "------------------------" << endl;
	cout << "| Shell Sort Algorithm |" << endl;
	cout << "------------------------" << endl;
	
	start = clock();

	for (int k = 0; k < 5; k++) {
		gap = d[k];
		for (int i = gap; i < size; i++) {
			temp = array[i];
			for (j = i - gap; temp < array[j] && j >= 0; j -= gap) {
				array[j + gap] = array[j];
			}
			array[j + gap] = temp;
		}
	}

	end = clock();
	cout << "Selection sort execution time: " << end - start << endl;
}

void Quick_Sort(int* array, int size) {}