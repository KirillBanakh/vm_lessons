#pragma once

#include <stdio.h>

struct sBook {
	int registration_number;
	char author[64];
	char name[64];
	int year;
	char publishing_house[64];
	int number_of_pages;
};

sBook Get_Random_Book();
void Create_Book_List_File(FILE* file);
void Save_Book_List_To_File(FILE* file, sBook* book_list, int size);
void Print_Book_List(sBook* book_list, int size);
void Search_For_Suitable_Books(sBook* book_list, int size, int year);