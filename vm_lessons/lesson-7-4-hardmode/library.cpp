#include "library.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const char* names[] {
	"Ivan",
	"Kirill",
	"Denis",
	"Gleb",
	"Zakhar",
	"Igor",
	"Valeria",
	"Natalia",
	"Varvara",
	"Nikolay"
};

const char* surnames[] {
	"Makarevich",
	"Shnaider",
	"Puccini",
	"Portman",
	"Kastro",
	"Antonenko",
	"Petrenko",
	"Black",
	"White",
	"Washington"
};

const char* books[] {
	"C Programming. Absolut beginners guide",
	"C Programming Language",
	"C: The Complete Reference",
	"C Programming in easy steps.",
	"C Programming: A Modern Approach",
	"Computer Fundamentals and Programming in C",
	"Low-Level Programming: C, Assembly, and Program Execution",
	"C in a Nutshell: The Definitive Reference 2nd Edition",
	"Hands-on Network Programming with C",
	"Data Structures Using C"
};

const char* publishing_houses[]{
	"Oxford",
	"Harvard",
	"Apress",
	"O`Reilly",
	"Pact"
};

sBook Get_Random_Book() {
	sBook book;

	book.registration_number = (rand() % 1000) + 1;
	sprintf_s(book.author, "%s %s", names[rand() % 10], surnames[rand() % 10]);
	sprintf_s(book.name, "%s", books[rand() % 10]);
	book.year = (rand() % (2022 - 1565)) + 1565;
	sprintf_s(book.publishing_house, "%s", publishing_houses[rand() % 5]);
	book.number_of_pages = (rand() % (1000 - 100)) + 100;

	return book;
}

void Create_Book_List_File(FILE* file) {
	fopen_s(&file, "Book_List.txt", "w");
	fclose(file);
}

void Save_Book_List_To_File(FILE *file, sBook* book_list, int size) {
	fopen_s(&file, "Book_List.txt", "a");
	
	for (int i = 0; i < size; i++) {
		fprintf_s(file, "-- Number in List: %i --\n", i + 1);
		fprintf_s(file, "Registration Number: %i\n", book_list[i].registration_number);
		fprintf_s(file, "Author:              %s\n", book_list[i].author);
		fprintf_s(file, "Book Name:           %s\n", book_list[i].name);
		fprintf_s(file, "Publishing Year:     %i\n", book_list[i].year);
		fprintf_s(file, "Publishing House:    %s\n", book_list[i].publishing_house);
		fprintf_s(file, "Number of Pages:     %i\n", book_list[i].number_of_pages);
		fprintf_s(file, "------------------------\n\n");
	}

	fclose(file);
}

void Print_Book_List(sBook* book_list, int size) {
	for (int i = 0; i < size; i++) {
		cout << "-- Number in List: "<< i + 1 <<" --" << endl;
		cout << "Registration Number: " << book_list[i].registration_number << endl;
		cout << "Author:              " << book_list[i].author << endl;
		cout << "Book Name:           " << book_list[i].name << endl;
		cout << "Publishing Year:     " << book_list[i].year << endl;
		cout << "Publishing House:    " << book_list[i].publishing_house << endl;
		cout << "Number of Pages:     " << book_list[i].number_of_pages << endl;
		cout << "------------------------" << endl << endl;
	}
}

void Search_For_Suitable_Books(sBook* book_list, int size, int year) {

	char temp[sizeof(book_list[0].author)];

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(book_list[i].author, book_list[j].author) > 0) {
				strcpy_s(temp, book_list[i].author);
				strcpy_s(book_list[i].author, book_list[j].author);
				strcpy_s(book_list[j].author, temp);
			}
		}
	}

	cout << "########################################" << endl;
	cout << "# Suitable Books Sorted Alphabetically #" << endl;
	cout << "########################################" << endl << endl;

	for (int i = 0; i < size; i++) {
		if (book_list[i].year >= year) {
			cout << "-- Registration Number: " << book_list[i].registration_number << " --" << endl;
			cout << "Author:              " << book_list[i].author << endl;
			cout << "Book Name:           " << book_list[i].name << endl;
			cout << "Publishing Year:     " << book_list[i].year << endl;
			cout << "Publishing House:    " << book_list[i].publishing_house << endl;
			cout << "Number of Pages:     " << book_list[i].number_of_pages << endl;
			cout << "-----------------------------" << endl << endl;
		}
	}
}