#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
	
public:
	// default value
	Date(int m = 1, int d = 1, int y = 1930);

	// getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	// setters
	void setDate(int m, int d, int y);

	// misc
	bool isLeapYear(int y) const;
	int daysInAMonth(int d) const ;
	void printDate(int dateFormat) const;

	// Overloaded operators
	Date operator++(); // Prefix ++
	Date operator++(int); // Postifx ++
	Date operator--(); // Prefix --
	Date operator--(int); // Postfix ++
	friend ostream& operator<<(ostream& out, Date& date);
	friend istream& operator>>(istream& in, Date& date);
	int operator-(const Date& other) const; // subtraction

private:
	bool isValidDate(int m, int d, int y) const;
	int calculateTotalDays() const;
};

