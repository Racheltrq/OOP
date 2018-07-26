enum class Month{
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
}


class Date{
	public:
		Date(int y, Month m, int d);
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		int year();
		Month month();
		int day();
		bool isvalid();
	private:
		int y;
		Month m;
		int d;
};

Month operator++(Month &m){
	m = (m == Month::dec) ? Jan : Month(m + 1);
	return m;
}

