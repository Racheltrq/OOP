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
		string temp = t.name;
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
		/*
		else{
			double d = get_value(temp);
			Token a = {number, d};
			ts.putback(t);
			ts.putback(a);
			d = expression(ts);
			return d;
		}
		*/
		ts.putback(t);
		ts.putback(var);
//      cout << "unspecified variable operation \n";
//		cout << "Test print" << endl;
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
//	cout << t.kind << endl;
	while(true){
		//cout <<"token kind: " << t.kind, "token value: " << t.value;
		switch(t.kind){
			case '(':
			{
				double expr = statement(ts);
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
//				cout << "Done" << endl;
//				cout << get_value(t.name);
				return get_value(t.name); //put var value into the function
			case 'q':
				error("program ends");
			case trig:
			{
				double res;
				switch(t.name){
					case "sin":
						res = sin(primary(ts)); 
						break;
					case "cos":
						res = cos(primary(ts));
						break;
					case "tan":
						res = tan(primary(ts));
						break;
					case "cot":
						res = cot(primary(ts));
						break;
					case "sec":
						res = sec(primary(ts));
						break;
					case "csc":
						res = csc(primary(ts));
						break;
				return res;
				}
			}

			default:
                string s = "" + t.kind;
//				cout << s << endl;
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

