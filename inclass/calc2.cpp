#include "std_lib_facilities.h"

int main(){
	int lval = 0;
	int rval = 0;
	char op;
	int res = 0;
	cout << "Please enter the expression: ";
	cin >> lval;
	if (!cin) error(" ");
	for(char op; cin >> op;){
		if(op != 'x')
			cin >> rval;
		else{
			break;
		}
		if (!cin) error(" "); 

		switch (op){
			case '+':
			res = lval + rval;
			break;
			case '-':
			break;
			res = lval - rval;
			break;
			case '*':
			res = lval * rval;
			break;
			case '/':
			res = lval / rval;
			break;
		}
		lval = res;
	}
	cout << "The result is: " << res << "\n";

}