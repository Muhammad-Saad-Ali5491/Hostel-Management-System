#include <iostream>
#include <algorithm>

struct Date {
	int day, month, year;
};

int daysInMonth(int month, int year) {
	static const int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysOfMonth = days[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
		// Leap year, February has 29 days
		daysOfMonth = 29;
	}
	return daysOfMonth;
}

int calculateDaysBetweenDates(const Date& date1, const Date& date2) {
	int days = 0;

	// Create a temporary variable for swapping
	Date tempDate1 = date1;
	Date tempDate2 = date2;

	// Ensure tempDate1 is earlier than or equal to tempDate2
	if (tempDate1.year > tempDate2.year || (tempDate1.year == tempDate2.year && (tempDate1.month > tempDate2.month || (tempDate1.month == tempDate2.month && tempDate1.day > tempDate2.day)))) {
		std::swap(tempDate1, tempDate2);
	}

	while (tempDate1.year < tempDate2.year || (tempDate1.year == tempDate2.year && (tempDate1.month < tempDate2.month || (tempDate1.month == tempDate2.month && tempDate1.day <= tempDate2.day)))) {
		days++;
		tempDate1.day++;

		if (tempDate1.day > daysInMonth(tempDate1.month, tempDate1.year)) {
			tempDate1.day = 1;
			tempDate1.month++;

			if (tempDate1.month > 12) {
				tempDate1.month = 1;
				tempDate1.year++;
			}
		}
	}

	return days;
}


