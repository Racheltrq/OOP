#include "std_lib_facilities.h"

int main(){
	char c = 'a';
	int i = 1212;
	double d = 3.14;
	char* cp = &c;
	//double* dp = &dp;
	int* ip = &i;
	cout << cp << " has a value of " << *cp << endl;
	cout << "size of cp is: " << sizeof(cp);
	//cout << dp << " has a value of " << *dp << endl;
	//cout << "size of dp is: " << sizeof(dp);
	cout << ip << " has a value of " << *ip << endl;
	cout << "size of ip is: " << sizeof(ip);
}