#include "std_lib_facilities.h"

struct reading{
	int a;
	double b;
	double c;
};

int main(){
	cout << "please enter the input file name: ";
	string iname;
	cin >> iname;
	ifstream ist {iname};
	if(!ist) error("can't open input file", iname);

	cout << "please enter the output file name: ";
	string oname;
	cin >> oname;
	ifstream ost {oname};
	if(!ost) error("can't open input file", oname);

	vector<reading> temps;
	int a;
	double b;
	double c;
	while(ist >> a >> b >> c){
		temps.push_back(reading{a, b, c});
	}
	for (int i = 0; i < temps.size(); i++){
		ost << temps[i].a << "	" << temps[i].b << " " << temps[i].c << "\n";
	}
}