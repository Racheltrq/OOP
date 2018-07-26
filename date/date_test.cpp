#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today{2018, Month::feb, 20};
	cout << "Today: " << today.year() << "/" << int(today.month()) << "/" 
		<< today.day() << endl;
	cout << "How many days do you want to add? ";
	int addDay;
	cin >> addDay;
	today.add_day(addDay);
	cout << today.day() << endl;
	return 0;
}