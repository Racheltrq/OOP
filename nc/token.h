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
		void putback(token t);
		token(char ch): kind{ch}{}
		token(char ch, double v): kind{ch}, val{v}{}
		token(char ch, string n): kind{ch}, name{n}{}
	private:
		vector<token> buffer;
};

