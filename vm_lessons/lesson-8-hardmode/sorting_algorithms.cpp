#include "sorting_algorithms.h"
#include <cstdio>
#include <iostream>
#include <Windows.h>

#define DEFAULT_COLOR 15
#define GREEN_COLOR 2

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
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	
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
	SetConsoleTextAttribute(console_color, GREEN_COLOR);
	cout << "Bubble sort execution time: " << end - start << endl;
	SetConsoleTextAttribute(console_color, DEFAULT_COLOR);
}


void Selection_Sort(int* array, int size) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	
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
	SetConsoleTextAttribute(console_color, GREEN_COLOR);
	cout << "Selection sort execution time: " << end - start << endl;
	SetConsoleTextAttribute(console_color, DEFAULT_COLOR);
}

void Insertion_Sort(int* array, int size) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	
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
	SetConsoleTextAttribute(console_color, GREEN_COLOR);
	cout << "Insertion sort execution time: " << end - start << endl;
	SetConsoleTextAttribute(console_color, DEFAULT_COLOR);
}

void Shell_Sort(int* array, int size) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	clock_t start, end;
	int j, temp, gap;
	int spacings[] = { 9, 5, 3, 2, 1 };

	cout << "------------------------" << endl;
	cout << "| Shell Sort Algorithm |" << endl;
	cout << "------------------------" << endl;
	
	start = clock();

	for (int k = 0; k < 5; k++) {
		gap = spacings[k];
		for (int i = gap; i < size; i++) {
			temp = array[i];
			for (j = i - gap; temp < array[j] && j >= 0; j -= gap) {
				array[j + gap] = array[j];
			}
			array[j + gap] = temp;
		}
	}

	end = clock();
	SetConsoleTextAttribute(console_color, GREEN_COLOR);
	cout << "Shell sort execution time: " << end - start << endl;
	SetConsoleTextAttribute(console_color, DEFAULT_COLOR);
}

static int Get_Quick_Sort_Borders(int* array, int first_index, int last_index) {
	int i = first_index - 1;
	int j = last_index + 1;
	int border = array[first_index];
	int temp;
	
	while (i < j) {
		while (array[--j] > border);
		while (array[++i] < border);
		
		if (i < j) {
			temp = array[j]; 
			array[j] = array[i]; 
			array[i] = temp;
			//swap(array[i], array[j]);
		}
	}

	return j;
}

static void Quick_Sort_Handler(int* array, int first_index, int last_index) {
	if (first_index < last_index)
	{
		int border = Get_Quick_Sort_Borders(array, first_index, last_index);
		Quick_Sort_Handler(array, first_index, border);
		Quick_Sort_Handler(array, border + 1, last_index);
	}
}

void Quick_Sort(int* array, int size) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	clock_t start, end;

	cout << "------------------------------" << endl;
	cout << "| Quick(Hoar) Sort Algorithm |" << endl;
	cout << "------------------------------" << endl;
	
	start = clock();
	
	Quick_Sort_Handler(array, 0, size - 1);

	end = clock();
	SetConsoleTextAttribute(console_color, GREEN_COLOR);
	cout << "Quick(Hoar) sort execution time: " << end - start << endl;
	SetConsoleTextAttribute(console_color, DEFAULT_COLOR);
}