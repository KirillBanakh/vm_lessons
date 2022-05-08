#include <iostream>

#include "sorting_algorithms.h"

using namespace std;

int main()
{
	int array_size;
	bool show_arrays = false;
	cout << "Input array size: ";
	cin >> array_size;
	cout << "Show arrays in console?" << endl;
	cout << "[0]: No" << endl;
	cout << "[1]: Yes" << endl;
	cin >> show_arrays;

	int* my_array = new int[array_size];
	int* my_array_copy = new int[array_size];

	for (int i = 0; i < array_size; i++)
	{
		my_array[i] = rand() % 100;
	}

	if (show_arrays) Print_Array(my_array, array_size);
	
	memcpy_s(my_array_copy, array_size * sizeof(int), my_array, array_size * sizeof(int));
	Bubble_Sort(my_array_copy, array_size);
	if (show_arrays) Print_Array(my_array_copy, array_size);

	memcpy_s(my_array_copy, array_size * sizeof(int), my_array, array_size * sizeof(int));
	Selection_Sort(my_array_copy, array_size);
	if (show_arrays) Print_Array(my_array_copy, array_size);

	return 0;
}
