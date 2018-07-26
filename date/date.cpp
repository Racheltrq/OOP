#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, int mm, int dd)
:y{yy}, m{mm}, d{dd}
{
	if(!isvalid()){
		throw invalid_argument("Invalid month.");
	}
}

void Date::add_year(int n){

}

void Date::add_month(int n){
}

void Date::add_day(int n){
	d += n;
	if(d > vector[m - 1]){
		m += 1;
		
	}
}

int Date::year(){
	return y;
}

int Date::month(){
	return m;
}

int Date::day(){
	return d;
}

bool Date::isvalid(){
	if((m < 1) || (m > 12)) return false;
	else return true;
}