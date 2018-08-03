#include "std_lib_facilities.h"

class vect{
	int sz;
	double* elem;
public:
	double get(int i){
		return elem[i];
	}
	void set(int i, double d){
		elem[i] = d;
	}

}

