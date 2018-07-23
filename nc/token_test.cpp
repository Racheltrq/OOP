#include "std_lib_facilities.h"
#include "token.h"

int main(){
	token_stream ts;
	while(cin){
		t = ts.get();
		cout << t.kind << " " << t.val;
		ts.putback(t);
	};

}