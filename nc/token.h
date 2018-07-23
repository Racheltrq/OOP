#include "std_lib_facilities.h"

class token{
	public:
		char kind;
		double val;
		string name;
};

class token_stream{
	public:
		token get();
		token popback();
		void putback();
		Token(char ch): kind{ch}{};
		Token(char ch, double v): kind{ch}{}, val{v}{};
		Token(char ch, string n): kind{ch}{}, name{n}{};
	private:
		vector<token> buffer;
};

