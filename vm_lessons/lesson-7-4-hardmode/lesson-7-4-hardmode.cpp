#include <iostream>
#include <stdio.h>

#include "library.h"

using namespace std;

int main()
{
    FILE* book_list_file = NULL;

    sBook book_list[10];

    int year;

    for (size_t i = 0; i < 10; i++)
    {
        book_list[i] = Get_Random_Book();
    }
    
    Create_Book_List_File(book_list_file);

    Save_Book_List_To_File(book_list_file, book_list, 10);

    Print_Book_List(book_list, 10);

    cout << "Enter Year to start search: ";
    cin >> year;
    cout << endl;

    Search_For_Suitable_Books(book_list, 10, year);

    return 0;
}
