#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today;
	today.y = 2018;
	today.m = 7;
	today.d = 20;
	cout << "Today: " << today.y << "/" << today.m << "/" 
		<< today.d << "\n";
	return 0;
}