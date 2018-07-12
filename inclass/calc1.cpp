#include "std_lib_facilities.h"

int main(){
	int lval = 0;
	int rval = 0;
	char op;
	int res = 0;
	cout << "Please enter the expression: ";
	cin >> lval >> op >> rval;
	if (op == '+')
		res = lval + rval;
	else res = lval - rval;

	cout << "The result is: " << res << "\n";

}