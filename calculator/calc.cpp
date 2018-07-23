#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"

double expression(Token_stream& ts);
double primary(Token_stream& ts);
double term(Token_stream& ts);


/*
double statement(Token_stream& ts){
	Token t = ts.get();
	if(t.kind == name){
		Token var = t;
		cout << "A var with a name " << var.name << endl;
		t = ts.get();
		if(t.kind == '='){
			double d = expression(ts);
			set_value(var.name, d);
			return d;
		}
		else if(t.kind == print){
			ts.putback(t);
			return get_value(var.name);
		}
		ts.putback(t);
		ts.putback(var);
		return expression(ts);
	}
	ts.putback(t);
	return expression(ts);
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
/*
int main(){
	Token_stream ts;

	while (cin){
		cout << "<";
		Token t = ts.get();
		while(t.kind == print) t = ts.get();
		if (t.kind == quit) return;

		ts.putback(t);
		cout << result << statement(ts) << '\n';
	}
	cout << "\nCALCULATOR TERMINATED\n";
	return 0;
}
*/
int main(){
	
}
