#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"

double expression(Token_stream& ts);
double primary(Token_stream& ts);
double term(Token_stream& ts);

/*
void Token_stream::ignore(){

}
*/

double expression(Token_stream& ts){
	double left = term(ts);
	Token t = ts.get();
	while(true){
		switch(t.kind){
			case '+':
				left = left + term(ts);
				break;
			case '-':
				left = left - term(ts);				
				break;
			default:
				ts.putback(t);
				return left;
		}
		t = ts.get();
		
	}
}

double term(Token_stream& ts){
	double left = primary(ts);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '*':
				left *= primary(ts);
				break;
			case '/':
			{
				double temp = primary(ts);
				if(temp == 0) error("Divide by zero.");
				left /= temp;
				break;
			}
			case '%':
			{
				double temp = primary(ts);
				if(temp == 0) error("Divide by zero.");

				left = fmod(left, temp);
				break;
			}
			case power:
				left = pow(left, primary(ts));
				break;
			default:
				ts.putback(t);
				return left;
		}
	t = ts.get();
	}
}

double primary(Token_stream& ts){
	Token t = ts.get();
	while(true){
		//cout <<"token kind: " << t.kind, "token value: " << t.value;
		switch(t.kind){
			case '(':
			{
				cout << "evaluate expression";
				double expr = expression(ts);
				cout << "Done";
				t = ts.get();
				if(t.kind != ')') error(") expected");
				return expr;
			}
			case '8':
				return t.value;
			case '+':
				return primary(ts);
			case '-':
				return -primary(ts);
			case 'q':
				error("program ends");

			default:
				error("primary expected");
		}
	t = ts.get();
	}
}

int main(){	
	Token_stream ts;
	double val = 0.0;
	while (cin){
		Token t = ts.get();
		cout << "Got token: " << t.kind << " with val of " << t.value << '\n';
		if(t.kind == 'q') break;
		if(t.kind == ';') cout << " = " << val << '\n';
			else ts.putback(t);
		val = expression(ts);
	}
	cout << "\nCALCULATOR TERMINATED\n";
	return 0;
}

