#include "std_lib_facilities.h"
#include "token.h"

double expression(Token_stream& ts);
double primary(Token_stream& ts);
double term(Token_stream& ts);



void Token_stream::putback(Token t){
	buffer = t;
	full = true;
}

Token Token_stream::get(){
	if (full){
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch(ch){
		case ';':
		case 'q':
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		return Token{ch};
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{'8', val};
		}

	}
}
/*
void Token_stream::ignore(){

}
/**/


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
				double a = primary(ts);
				if(a == 0) error("Divide by zero.");
				left /= a;
				break;
			case '%':
				double b = primary(ts);
				if(b == 0) error("Divide by zero.");
				left = fmod(left, b);

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
	switch(t.kind){
		case '(':
			double expr = expression(ts);
			t = ts.get();
			if(t.kind != ')') error(") expected");
			return expr;
		case number:
			return t.value;
		case '+':
			return primary(ts);
		case '-':
			return -primary(ts);
		default:
			error("primary expected");
	}
	t = ts.get();
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

