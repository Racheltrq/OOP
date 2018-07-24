#include "std_lib_facilities.h"
#include "token.h"

token token_stream::get(){
	while(buffer.size() > 0) return buffer.pop_back();
	char ch;
	cin >> ch;
	switch(ch){
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '(':
		case ')':
		case ';':
		case '^':
			return token{ch};
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
		case '.':
		{
			cin.putback(ch);
			double a;
			cin >> a;
			return token{'n', a};
		}
		default: // is var
			return token{'q'};
	}

}

token token_stream::popback(){
	return buffer.pop_back();
}

void token_stream::putback(token t){
	buffer.push_back(t);
}