enum class Month{
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date{
	public:
		Date(int y = 0, Month m = Month(1), int d = 1);
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		int year();
		Month month();
		int day();
		bool isvalid();
		bool isleap(int y);
		//Month operator++();
		

		int y;
		Month m;
		int d;
};

ostream& operator<<(ostream& os, Date& dt);
istream& operator>>(istream& is, Date& dt);
