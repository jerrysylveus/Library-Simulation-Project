#include <string>
#include <iostream>
#include "Book.hpp"


// constructor taking three string parameter
Book::Book(std::string idc, std::string t, std::string a)
{
	idCode = idc;
	title = t;
	author = a;
	checkedOutBy = NULL;
	requestedBy = NULL;
}


// returns the Id Code
std::string Book::getIdCode()
{
	return idCode;
	
}

// give how long a book can be checked out for
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}

// Return the title of the book
std::string Book::getTitle()
{
	return title;
}

// return the name of the author
std::string Book::getAuthor()
{
	return author;
}

// determine if the book is on the shelf, hold shelf or checked out
Locale Book::getLocation()
{
	return location;
}

// set method for where the book is
void Book::setLocation(Locale loc)
{
	location = loc;
}

// return who has the book checked out
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}

// takes a pointer to patron who has the book checked out
void Book::setCheckedOutBy(Patron* patWhohasBook)
{
	checkedOutBy = patWhohasBook;
	
}

// return what patron requested the book
Patron* Book::getRequestedBy()
{
	return requestedBy;
}

// set method for books requested by the patron.
void Book::setRequestedBy(Patron* request)
{
	requestedBy = request;
}


// setting the date the book is checked out to current library date
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
	//std::cout << "Id Jerry is found \n";
}

// set Methods to set the date to current lib date
void Book::setDateCheckedOut(int currentDate)
{
	dateCheckedOut = currentDate;
	
}