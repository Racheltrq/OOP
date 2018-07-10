#include "std_lib_facilities.h"

int main(){
	cout << "Enter a word: \n";
	vector<string> conc;
	for(string word; cin >> word;){
		conc.push_back(word);
	}
	sort(conc);
	for(string x: conc){
		cout << x << ' ';
	}
	cout << '\n';
	int index = 0;
	int n = 1;
	while((index+n) < conc.size()){

		if (conc[n + index] != conc[index]){
			cout << conc[index] << ':' << n << '\n';
			index += n;
			n = 1;


		}
		else n++;

	}

	cout << conc[index] << ':' << n << '\n';
}



