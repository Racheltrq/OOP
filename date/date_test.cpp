#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today{2018, Month::jul, 20};
	cout << "Today: " << today.year() << "/" << int(today.month()) << "/" 
		<< today.day() << endl;
	today.add_day(1);
	cout << today.day() << endl;
	return 0;
}