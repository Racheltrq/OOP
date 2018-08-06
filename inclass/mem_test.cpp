#include "std_lib_facilities.h"

int main(){
	count = 0;
	while(true){
	double* arr = new double[10000];
	for(int i = 0; i < 10000; i++){
		arr[i] = i;
		count++;
		cout << count << endl;
	}
}
}