#include "std_lib_facilities.h"
#include <cmath>
#include "token.h"
#include "vars.h"

double statement(Token_stream& ts);
double expression(Token_stream& ts);
double primary(Token_stream& ts);
double term(Token_stream& ts);
double expon(Token_stream& ts);



double statement(Token_stream& ts){
	Token t = ts.get();
	if(t.kind == name){
		Token var = t;
//		cout << "A var with a name " << var.name << endl;
		t = ts.get();
		if(t.kind == '='){
//            cout << "SET VAR STATEMENT\n";
			double d = expression(ts);
			set_value(var.name, d);
			return d;
		}else if(t.kind == print){
//            cout << "GET VAR STATEMENT\n";
			ts.putback(t);
			return get_value(var.name);
		}
		else{
			string s = "" + t.kind;
			cout << s << endl;
			cout << get_value(s) << endl;
			double temp = get_value(s);
			ts.putback(temp);
			ts.putback(t);
			double d = expression(ts);
			return d;
		}
//		ts.putback(t);
//		ts.putback(var);
//        cout << "unspecified variable operation \n";
		return expression(ts);
	}
//    cout << "NON VARIABLE STATEMENT\n";
	ts.putback(t);
	return expression(ts);
}

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
	double left = expon(ts);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '*':
				left *= expon(ts);
				break;
			case '/':
			{
				double temp = expon(ts);
				if(temp == 0) error("Divide by zero.");
				left /= temp;
				break;
			}
			case '%':
			{
				double temp = expon(ts);
				if(temp == 0) error("Divide by zero.");

				left = fmod(left, temp);
				break;
			}
			//case power:
			//	left = pow(left, expon(ts));
			//	break;
			default:
				ts.putback(t);
				return left;
		}
	t = ts.get();
	}
}

double expon(Token_stream& ts){
	double left = primary(ts);
	Token t = ts.get();
	while(true){
		if(t.kind == power){
			left = pow(left, primary(ts));
			
		}
		else{
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
				double expr = expression(ts);
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
			case name:
				return name;
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

	while (cin){
		cout << "> ";
		Token t = ts.get();
		while(t.kind == print) t = ts.get();
		if (t.kind == quit) return 0;
		
		ts.putback(t);
		cout << "=" << statement(ts) << '\n';
	}
	cout << "\nCALCULATOR TERMINATED\n";
	return 0;
}

