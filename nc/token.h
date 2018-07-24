#include "std_lib_facilities.h"

class token{
	public:
		char kind;
		double val;
		string name;
		token(char ch): kind{ch}{}
		token(char ch, double v): kind{ch}, val{v}{}
		token(char ch, string n): kind{ch}, name{n}{}
};

class token_stream{
	public:
		token get();
		token popback();
		void putback(token t);
		
	private:
		vector<token> buffer;
};

