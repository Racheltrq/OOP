#include "std_lib_facilities.h"

int main(){
	vector<int> v;
	int i = 0;
	while (cin >> i){
		v.push_back(i);
		for(int x: v){
			cout << x << " ";
		}
	}
}