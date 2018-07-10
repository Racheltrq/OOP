#include "std_lib_facilities.h"

int main(){
	cout << "Enter recent temperatures and we will calculate their average:\n";

	vector<double> temps;
	for(double temp; cin >> temp;)
		temps.push_back(temp);
	sort(v);
	cout << temps[temps.size() /2] <<'\n';
	keep_window_open();
	return 0;
}