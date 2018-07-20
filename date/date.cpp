#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, int mm, int dd)
:y{yy}, m{mm}, d{dd}
{
}

void Date::add_day(int n){
}

int Date::month(){
	return m;
}