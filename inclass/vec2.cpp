#include "std_lib_facilities.h"

class vect{
	int sz;
	double* elem;
public:
	vect(int s):sz{s}, elem{new double s[]}{}
	~vect(){delete elem;}
}