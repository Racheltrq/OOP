#include "std_lib_facilities.h"

class vect{
	int sz;
	double* elem;
public:
	double& operator[](int n){ return elem[n]; }
	vect(int s):sz{s}, elem{new double [s]}{}
	vect(const vect& a);
	vect& operator=(const vect& a);
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

void f(){
    vect v(3);
    v.set(2,2.2);
    vect v2 = v;
    v.set(1,9.9);
    v2.set(0,8.8);
    cout << v.get(0) << ' ' << v2.get(1) << endl;
    cout << v.get(1) << ' ' << v2.get(0) << endl;
}

int main(){
    f();

}
