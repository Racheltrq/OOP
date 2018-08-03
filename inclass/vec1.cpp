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
	~vect(){delete elem;}
};

void f(){
    vect v(3);
    v.set(2,2.2);
    vect v2 = v;
    v.set(1,9.9);
    v2.set(0,8.8);
    cout << v.get(0) << ' ' << v2.get(1);
}

int main(){
    f();

}

