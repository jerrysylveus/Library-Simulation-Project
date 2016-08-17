//#include "Book.hpp"
//#include "Patron.hpp"
#include "Library.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()

{


	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Book b4("456", "ahmed", "ali");
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");
	Patron p3("hhh", "ahm");
	Library lib;
	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.requestBook("bcd", "234");
	cout << lib.requestBook("bcd", "234") << endl;
	cout << lib.checkOutBook("abc", "345") << endl;
		cout << lib.checkOutBook("hhh", "234") << endl;
	cout << lib.requestBook("bcd", "123") << endl;
		cout << lib.returnBook("345") << endl;
	for (int i = 0; i<7; i++)
		lib.incrementCurrentDate();
	cout << lib.checkOutBook("abc", "123") << endl;
	cout << lib.checkOutBook("abc", "345") << endl;
	for (int i = 0; i<24; i++)
		lib.incrementCurrentDate();
	lib.payFine("abc", 1.4);
	double p1Fine = p1.getFineAmount();
	cout << "Patron p1 fine Amount:" << p1.getFineAmount()<< endl;
	double p2Fine = p2.getFineAmount();
	cout << "Patron p2 fine Amount:" << p2.getFineAmount()<< endl;





	cin.ignore();
	cin.get();
	return 0;

}
