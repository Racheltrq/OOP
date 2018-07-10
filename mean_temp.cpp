#include "std_lib_facilities.h"

int main(){
	cout << "Enter recent temperatures and we will calculate their average:\n";

	vector<double> temps;
	for(double temp; cin >> temp;)
		temps.push_back(temp);
	double total = 0.0;
	for(double temp : temps)
		total += temp;
	double mean = total / temps.size();
	cout << "Your mean temperature for the last "<<temps.size()<<" days was "<<mean<<'\n';
	keep_window_open();
	return 0;
}