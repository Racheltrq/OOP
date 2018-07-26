#include "std_lib_facilities.h"
#include "date.h"

vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> leap_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	Month a = Month::jul;
	Date today{2018, a, 20};
	cout << "Today: " << today.year() << "/" << int(today.month()) << "/" 
		<< today.day() << endl;
	return 0;
}