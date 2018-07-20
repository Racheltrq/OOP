#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today{2018, 11, 20};
	cout << "Today: " << today.year() << "/" << today.month() << "/" 
		<< today.day() << endl;
	return 0;
}