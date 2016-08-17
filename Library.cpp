#include "Library.hpp"
#include <string>
#include <vector>
#include <string>

// default constructor
Library::Library()
{
    // setting the current date to zero
	currentDate = 0;
}

// adding the parameter to holding
void Library::addBook(Book* book)
{
	holdings.push_back(book);
}

// adding the parameter to members
void Library::addPatron(Patron* patron)
{
	members.push_back(patron);
}



std::string Library::checkOutBook(std::string pID, std::string bID)
{
    // if the book is not on the shelf, then it's not found.
	Book* book = getBook(bID);
	if (book == NULL)
		return "book not found";

    // patron hasn't check out the book it should be on the shelf.
	Patron* patron = getPatron(pID);
	if (patron == NULL)
		return "patron not found";

    // patron object p1 that has checked out a book.
	Patron* p1 = book->getCheckedOutBy();
    
    // if patron has checked out the book he has
    // the date, the location, the return date, and the book
    // has been added to the patron.
	if (p1 != NULL){
		book->setDateCheckedOut(currentDate);
		book->setLocation(CHECKED_OUT);
		book->setCheckedOutBy(patron);
		patron->addBook(book);
		return "book already checked out";
	}
    
    // If another patron wants that same book that is out
    // let him knows someone else has the book

	Patron* p2 = book->getRequestedBy();
	if (p2 != NULL)
		return "book on hold by other patron";

	book->setDateCheckedOut(currentDate);
	book->setLocation(CHECKED_OUT);
	book->setCheckedOutBy(patron);
	patron->addBook(book);
	return "check out successful";
}


std::string Library::returnBook(std::string bID)
{
	Book* b = getBook(bID);
	if (b == NULL)
		return "book not found";

	Patron* p = b->getCheckedOutBy();
	if (p == NULL)
		return "book already in library";
	p->removeBook(b);

	Patron* p1 = b->getRequestedBy();
	if (p1 == NULL)
		b->setLocation(ON_SHELF);
	else{
		b->setDateCheckedOut(currentDate);
		b->setLocation(CHECKED_OUT);
		b->setCheckedOutBy(p1);
		p1->addBook(b);
	}
	return "return successful";

}


std::string Library::requestBook(std::string pID, std::string bID)
{
	Book* b = getBook(bID);
	if (b == NULL)
		return "book not found";

	Patron* p = getPatron(pID);
	if (p == NULL)
		return "patron not found";

	Patron* p1 = b->getRequestedBy();
	if (p1 != NULL)
		return "book on hold by other patron";

	b->setRequestedBy(p1);
	b->setLocation(ON_HOLD_SHELF);
	return "request successful";

}


std::string Library::payFine(std::string pID, double payment)
{
	Patron* p = getPatron(pID);
	if (p == NULL)
		return "patron not found";

	if (payment < 0)
		return "Fine should be positive";

	p->amendFine(payment);
	return "payment successful";

}

void Library::incrementCurrentDate()
{
	currentDate++;
}


Patron* Library::getPatron(std::string pID)
{
	for (int i = 0; i < members.size(); i++){
		Patron* p = members[i];
		if (p->getIdNum() == pID) 
			return p;
	}
	return NULL;
}


Book* Library::getBook(std::string bID)
{
	for (int i = 0; i < holdings.size(); i++){
		Book* b = holdings[i];
		if (b->getIdCode() == bID)
			return b;
	}
	return NULL;
}