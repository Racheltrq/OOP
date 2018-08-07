#include "std_lib_facilities.h"

class variable{
	public:
		string name;
		double value;
};

double get_value(string s);
void set_value(string s, double d);
void print_vars();