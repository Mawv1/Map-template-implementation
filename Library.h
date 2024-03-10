#ifndef TABLICA_ASOSACYJNA_LIBRARY_H
#define TABLICA_ASOSACYJNA_LIBRARY_H

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Book{
public:
    string author;
    string category;
    int pages;
    bool status;

    Book(string author, string cat, int pgs, bool stat): author(author), category(cat), pages(pgs), status(stat){}

    friend ostream& operator<<(ostream& os, const Book& book){
        os << "author: " << book.author << ", category: " << book.category << ", pages: " << book.pages<<", status: ";
        if(book.status == 0) os<<"not ";
        os<<"available";
        return os;
    }
};
#endif //TABLICA_ASOSACYJNA_LIBRARY_H
