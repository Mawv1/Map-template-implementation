#include "Employee.h"													// Defines class Employee
#include "Map.h"														// Defines template Map<Key, Value>
#include "Library.h"
#include <iostream>
#include <string>

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees

typedef string title;
typedef Map<title, Book> Library;
using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);

void addBooks(Library& lib);
void modifyLibrary(Library& lib);

int main() {
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:" << endl << database << endl;


    Library library;
    addBooks(library);

    Library new_library = library;									// Make a copy of database
    new_library.add("The Last Wish", Book("Andrzej Sapkowski", "fantasy", true, 288));	// Add fourth book
    modifyLibrary(new_library);

    cout << "Original library database:" << endl << library << endl;
    cout << "Modified library database:" << endl << new_library << endl;

    library = new_library;												// Update original database

    cout << "Library database after the assignment:" << endl << library << endl;

};

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";									// Modify the position of employee

	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
}

void addBooks(Library& lib) {
    lib.add("Harry Potter and the Philosopher's Stone", Book("Joanne Murray","fantasy",true,223));
    lib.add("Pan Tadeusz", Book("Adam Mickiewicz", "epic poem", true,376));
    lib.add("Dune", Book("Frank Herbert", "science fiction", false,896));
}

void modifyLibrary(Library& lib) {
    Book* book_ptr;

    book_ptr = lib.find("The Last Wish");								// Find book using its title
    book_ptr->status = false;									// Modify the status of book

    book_ptr = lib.find("Harry Potter and the Philosopher's Stone");								// Find book using its title
    book_ptr->author = "J. K. Rowling";												// Modify the authors name
}
