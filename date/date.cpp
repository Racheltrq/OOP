#include "std_lib_facilities.h"
#include "date.h"

vector<int> month_days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> leap_month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string count_mon[13] = {"", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

Date::Date(int yy, Month mm, int dd)
:y{yy}, m{mm}, d{dd}
{
	if(!isvalid()){
		throw invalid_argument("Invalid month.");
	}
}



void Date::add_year(int n){
	y += n;
}

void Date::add_month(int n){
	m = Month(int(m) + n);
	while(int(m) > 12){
		m = Month(int(m) - 12);
		y++;
	}
}

void Date::add_day(int n){
	d += n;
	int numDay;
	//cout << "Here." << endl;
	if(isleap(y)) numDay = month_days[int(m) - 1];
	else numDay = leap_month_days[int(m) - 1];
	while(d > numDay){
		d -= numDay;
		if(int(m) == 12) {
			m = Month(1);
			y += 1;
		}
		else m = Month(int(m) + 1);
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
/*
Month month::operator++(){
	cout << "!" << endl;
	m = (m == Month::dec) ? (Month::jan) : Month(int(m) + 1);
	return m;
}
*/
std::ostream& operator<<(ostream& os, Date& dt){
	os << count_mon[int(dt.month())] << " " << dt.day() << ", " << dt.year();
}

std::istream& operator>>(istream& is, Date& dt){
	string x;
	is >> x;
	dt.y = stoi(x.substr(1, 5));
	dt.m = Month(stoi(x.substr(6, 8)));
	dt.d = stoi(x.substr(9,11));

}

bool operator==(const Date& dt1, const Date& dt2){
	if((dt1.y == dt2.y) && (int(dt1.m) == int(dt2.m)) && (dt1.d == dt2.d)) return true;
	else return false;
}

bool operator!=(const Date& dt1, const Date& dt2){
	if((dt1.y == dt2.y) && (int(dt1.m) == int(dt2.m)) && (dt1.d == dt2.d)) return false;
	else return true;
}

bool Date::isvalid(){
	if((int(m) < 1) || (int(m) > 12) || (d < 1)) return false;
	else if(isleap(y) && (d > leap_month_days[int(m)-1])) return false;
	else if((!isleap(y)) && (d > month_days[int(m)-1])) return false;
	else return true;
}

bool Date::isleap(int y){
	if(y % 4 == 0){
		if(y % 100 == 0) return false;
		else return true;
	}
	else return false;
}