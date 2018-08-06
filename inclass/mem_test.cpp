#include "std_lib_facilities.h"

int main(){
	int count = 1;
	double* arr = new double[10000];
	while(true){
		arr = new double[10000*count];
		count++;
		cout << count << endl;
	}
}