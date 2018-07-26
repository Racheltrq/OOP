#include "std_lib_facilities.h"

struct reading{
	int a;
	char b;
	double c;
	char d;
	double e;
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
	ofstream ost {oname};
	if(!ost) error("can't open input file", oname);

	vector<reading> temps;
	int a;
	char b;
	double c;
	char d;
	double e;
	while(ist >> a >> b >> c >> d >> e){
		temps.push_back(reading{a, b, c, d, e});
	}
	for (int i = 0; i < temps.size(); i++){
		ost << temps[i].a  << "	" << temps[i].c << "	" << temps[i].e << "\n";
	}
}