#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today{2018, 11, 20};

	//cout << "Today: " << today.y << "/" << today.m << "/" 
	//	<< today.d << "\n";
	cout << today.month() << endl;
	return 0;
}