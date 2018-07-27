#include "std_lib_facilities.h"
#include "date.h"

vector<int> month_days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> leap_month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string count_mon[13] = {"", "jJanuary", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

Date::Date(int yy, Month mm, int dd)
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
	int numDay;
	if(isleap(y)) numDay = month_days[int(m) - 1];
	else numDay = leap_month_days[int(m) - 1];
	while(d > numDay){
		d -= numDay;
		
		m++;
		//m = Month(int(m) + 1);
	}
}

int Date::year(){
	return y;
}

Month Date::month(){
	return m;
}

int Date::day(){
	return d;
}

Month Date::operator++(){
	cout << "!" << endl;
	m = (m == Month::dec) ? (Month::jan) : Month(int(m) + 1);
	return m;
}

std::ostream& operator<<(ostream& os, Date& dt){
	os << count_mon[int(dt.month())] << " " << dt.day() << " " << dt.year();
}

bool Date::isvalid(){
	if((int(m) < 1) || (int(m) > 12)) return false;
	else return true;
}

bool Date::isleap(int y){
	if(y % 4 == 0){
		if(y % 100 == 0) return false;
		else return true;
	}
	else return false;
}