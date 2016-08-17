#include <iostream>
#include "Patron.hpp"
#include <string>
#include <vector>

Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0;

}

// unique identifier fot the patron
std::string Patron::getIdNum()
{
	return idNum;
}

// name of the patron may not be unique
std::string Patron::getName()
{
	return name;
}


std::vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}

// vector points to book patron has already checked out
void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}

// remove the book from checked out books
void Patron::removeBook(Book* b)
{
	for (int i = 0; i < checkedOutBooks.size(); i++) 
	{
		if (checkedOutBooks[i] == b)
		{
			checkedOutBooks.erase(checkedOutBooks.begin() + i);
			break;
		}
	}

}

// how much the patron owes in late fees
double Patron::getFineAmount()
{
	return fineAmount;
}


void Patron::amendFine(double amount)
{
	fineAmount += amount;
}
