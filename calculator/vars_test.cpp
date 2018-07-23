#include "std_lib_facilities.h"
#include "vars.h"

int main(){
	set_value("a", 10.0);
	set_value("abc", 1.11);


	double d;
	d = get_value("a");
	cout << "a = " << d << endl;
	d = get_value("abc");
	cout << "abc = " << d << endl;
}