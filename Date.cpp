#include "Date.h"

Date::Date(int m, int d, int y) {
	if (isValidDate(m, d, y)) {
		month = m;
		day = d;
		year = y;
	}
	else {
		cerr << "Invalid date provided. Setting default date (1/1/1930)." << endl;
		month = 10;
		day = 29;
		year = 2003;
	}
}

int Date::getDay() const { return day; }

int Date::getMonth() const { return month; }

int Date::getYear() const { return year; }

void Date::setDate(int m, int d, int y) {
	if (isValidDate(m, d, y)) {
		month = m;
		day = d;
		year = y;
	}
	else {
		cerr << m << "/" << d << "/" << y << " <-- Invalid date provided. Date not updated." << endl;
	}
}

bool Date::isLeapYear(int y) const {
	// for general years it has to be divisble by 4, if it's also divisble by 100 go to the next step
	if (y % 4 == 0 && y % 100 != 0) {
		return true;
	}
	// if it's a century year it has to be divisble by 100 AND 400
	else if (y % 100 == 0 && y % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Date::daysInAMonth(int m) const {
	if (m == 2) {
		return 28;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

void Date::printDate(int dateFormat) const {
	if (dateFormat == 1) {
		cout << month << "/" << day << "/" << year << endl;
	}
	else if (dateFormat == 2 || dateFormat == 3) {
		string months[] = {"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
		};
		if (dateFormat == 2) {
			cout << months[month - 1] << " " << day << ", " << year << endl;
		}
		else if (dateFormat == 3) {
			cout << day << " " << months[month - 1] << " " << year << endl;
		}
	}
	else {
		cerr << "Invalid date format." << endl;
	}
}

// Prefix version
Date Date::operator++() {
	if (day < daysInAMonth(month) || (month == 2 && day == 28 && isLeapYear(year))) {
		++day;
	}
	else {
		day = 1;
		if (month < 12) {
			++month;
		}
		else {
			month = 1;
			++year;
		}
	}
	return *this;
}
// Postfix version
Date Date::operator++(int) {
	Date temp = *this;
	++(*this); // reuse prefix logic
	return temp;
}

// Prefix version for decrementing
Date Date::operator--() {
	if (day > 1) {
		--day;
	}
	else {
		if (month == 1) { // if it's January, wrap around to December
			month = 12;
			--year;
		}
		else {
			--month; 
		}
		// adjust day for the new month
		if (month == 2 && isLeapYear(year)) {
			day = 29; // leap year adjustment
		}
		else {
			day = daysInAMonth(month);
		}
	}
	return *this;
}

// Postfix version for decrementing
Date Date::operator--(int) {
	Date temp = *this;
	--(*this); // reuse prefix logic
	return temp;
}

int Date::operator-(const Date& other) const {
	// calculate the total days for both dates
	int totalDaysThis = calculateTotalDays();
	int totalDaysOther = other.calculateTotalDays();

	return totalDaysThis - totalDaysOther;
}

ostream& operator<<(std::ostream& out, Date& date) {
	static const string months[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	if (date.month >= 1 && date.month <= 12) {
		out << months[date.month - 1] << " " << date.day << ", " << date.year;
	}
	else {
		out << "Invalid Date";
	}

	return out;
}

istream& operator>>(istream& in, Date& date) {
	int m, d, y;
	char slash1, slash2;

	// eead input in the format MM/DD/YYYY
	in >> m >> slash1 >> d >> slash2 >> y;

	// validate format and date
	if (slash1 == '/' && slash2 == '/' && date.isValidDate(m, d, y)) {
		date.setDate(m, d, y); // Set the date if valid
	}
	return in;
}


bool Date::isValidDate(int m, int d, int y) const {
	if (m < 1 || m > 12) {
		return false;
	}
	int daysInCurrentMonth = daysInAMonth(m);
	if (m == 2 && isLeapYear(y)) {
		daysInCurrentMonth += 1; // adjust for leap year
	}
	if (d < 1 || d > daysInCurrentMonth) {
		return false;
	}
	if (y < 0) {
		return false;
	}
	return true;
}

int Date::calculateTotalDays() const {
	int total = 0;
	// days from the year
	total += (year * 365) + (year / 4) - (year / 100) + (year / 400);

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// days from the month
	for (int i = 1; i < month; i++) {
		total += daysInMonth[i - 1];
	}
	// leap year check
	if (month > 2 && isLeapYear(year)) {
		total += 1;
	}
	// add days in the current month
	total += day;

	return total;
}