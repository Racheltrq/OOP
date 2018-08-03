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
	vect(int s):sz{s}, elem{new double [s]}{}
	vect(const vect&);

	~vect(){delete elem;}
};


vect::vect(const vect& arg):sz{arg.sz}, elem{new double[arg.sz]}{
	copy(arg.elem, arg.elem + arg.sz, elem);
}

vect& vect::operator=(const vect& a){
	double* p = new double[a.sz];
	copy(a.elem, a.elem + a.sz, p);
	delete[] elem;
	sz = a.sz;
	return *this;
}
