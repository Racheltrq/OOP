#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today{2008, Month::feb, 20};
	cout << today << endl;
	cout << "How many days do you want to add? ";
	int addDay;
	cin >> addDay;
	today.add_day(addDay);
	cout << today << endl;
	cout << "Please enter a date in format (YYYY,MM,DD): ";
	cin >> new_day;
	return 0;
}


//Input a date in format (yyyy,mm,dd)
//Enter #days to add to your date