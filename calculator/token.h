const char invalid = 'i';
const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';
const char power = '^';
const char mod = '%';

class Token{
	public:
		char kind;
		double value;
};

class Token_stream{
	public:
		Token get();
		void putback(Token t);
	private:
		bool full{false};
		Token buffer;
};