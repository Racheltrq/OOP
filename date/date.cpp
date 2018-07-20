#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, int mm, int dd)
:y{yy}, m{mm}, d{dd}
{
	if(!isvalid()){
		throw invalid_argument("Invalid month.");
	}
}

void Date::add_day(int n){
}

int Date::month(){
	return m;
}

bool Date::isvalid(){
	if((m < 1) || (m > 12)) return false;
	else return true;
}