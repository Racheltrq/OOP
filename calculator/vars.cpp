#include "std_lib_lib_facilities.h"
#include "vars.h"

vector<variable> var_table;

double get_value(string s){
	for(variable var: var_table)
		if(var.name == s) return var.value;
	return 0.0;
}

void set_value(string s, double d){
	for(variable& var: var_table)
		if(var.name == s){
			var.value = d;
			return;
		}
	var_table.push_back(variable{s, d});
}

void print_vars(){
	for(variable var: var_table)
		cout < "Var " << var.name << " = " << var.value << endl;
}