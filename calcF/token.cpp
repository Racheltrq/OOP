#include "std_lib_facilities.h"
#include "token.h"

void Token_stream::putback(Token t){
	buffer.push_back(t);
}

Token Token_stream::popback(){
	Token t = buffer.back();
    buffer.pop_back();
	return t;
}

Token Token_stream::get(){
	if (buffer.size() > 0){
		Token t = popback();
		return t;
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
        case '=':
		case mod:
		case power:
		return Token{ch};
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{number, val};
		}

		
		default:
			if(isalpha(ch)){
				string s;
				s += ch;
				while(cin.get(ch) && (isalpha(ch) || isdigit(ch)))
					s += ch;
				cin.putback(ch);
				//if((s == "sin") || (s == "cos") || (s == "tan") || (s == "cot") || (s == "sec") || (s == "csc"))
				return Token{name, s};

			}

			return Token{invalid, double(ch)};
		
	}
	return Token{quit};

}
