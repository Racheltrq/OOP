#include "std_lib_facilities.h"
#include "date.h"

int main(){
	cout << "Please enter a date in format (YYYY,MM,DD): ";
	Date new_day;
	cin >> new_day;
	cout << "How many days do you want to add? ";
	int addDay;
	cin >> addDay;
	new_day.add_day(addDay);
	cout << new_day << endl;
	return 0;
}


//Input a date in format (yyyy,mm,dd)
//Enter #days to add to your date