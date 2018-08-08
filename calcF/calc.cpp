#include "std_lib_facilities.h"
#include <cmath>
#include "token.h"
#include "vars.h"

double statement(Token_stream& ts);
double expression(Token_stream& ts);
double primary(Token_stream& ts);
double term(Token_stream& ts);
double expon(Token_stream& ts);
void helper();

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
			case 'h':
				return;
			case trig:
			{
				double res;
				if(t.name == "sin") res = sin(primary(ts)); 
				else if(t.name == "cos") res = cos(primary(ts));
				else if(t.name == "atan") res = atan(primary(ts));
				else if(t.name == "asin") res = asin(primary(ts));
				else if(t.name == "acos") res = acos(primary(ts));
				else if(t.name == "tan") res = tan(primary(ts));
				else if(t.name == "log") res = log(primary(ts));
				else if(t.name == "log2") res = log2(primary(ts));
				else if(t.name == "log10") res = log10(primary(ts));
				return res;
			}

			default:
                string s = "" + t.kind;
//				cout << s << endl;
				error("primary expected");
		}
	t = ts.get();
	}
}

void helper(){
	cout << "assign var: \neg. x=3*2; \nevaluate function: \neg. x=3; \n3+x-2; \nevaluate trignometric function: \neg. sin(3);" << endl;
}

int main(){
	cout << "Please enter an expression(enter 'h' to get help, 'q' to quit)" << endl;
	Token_stream ts;

	while (cin){
		cout << "> ";
		Token t = ts.get();
		while(t.kind == print) t = ts.get();
		if (t.kind == quit) return 0;

		if(t.kind == help) helper();
		ts.putback(t);
		cout << "=" << statement(ts) << '\n';
	}
	cout << "\nCALCULATOR TERMINATED\n";
	return 0;
}

