#include "std_lib_facilities.h"
#include "token.h"

int main(){
	token_stream ts;
	while(cin){
		token t = ts.get();
		if(t.kind == ';') return 0;
		cout << t.kind << " " << t.val;
		//ts.putback(t);
	};

}