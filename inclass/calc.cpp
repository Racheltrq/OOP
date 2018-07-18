#include "std_lib_facilities.h"
#include "token.h"

double expression();
double primary();
double term();



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

void Token_stream::ignore(){
	
}

Token_stream ts;

double expression(){
	double left = term();
	Token t = ts.get();
	while(true){
		switch(t.kind){
			case '+':

				left = left + term();
				break;
			case '-':
				left = left - term();				
				break;
			default:
				ts.putback(t);
				return left;
		}
		t = ts.get();
		
	}
}

double term(){
	return primary();
}

double primary(){
	Token t = ts.get();
	return t.value;
}


int main(){	
	double val = 0.0;
	while (cin){
		Token t = ts.get();
		cout << "Got token: " << t.kind << " with val of " << t.value << '\n';
		if(t.kind == 'q') break;
		if(t.kind == ';') cout << " = " << val << '\n';
			else ts.putback(t);
		val = expression();
	}
	cout << "\nCALCULATOR TERMINATED\n";
	return 0;
}

