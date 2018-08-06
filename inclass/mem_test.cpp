#include "std_lib_facilities.h"

int main(){
	int count = 0;
	double* arr = new double[10000];
	while(true){
		arr = new double[10000];
		arr = NULL;
		count++;
		cout << count << endl;
	}
}