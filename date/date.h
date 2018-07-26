class Date{
	public:
		Date(int y, Month m, int d);
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		int year();
		int month();
		int day();
		bool isvalid();
	private:
		int y;
		Month m;
		int d;
};

enum class Month{
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
}



Month operator++(Month &m){
	m = (m == Dec) ? Jan : Month(m + 1);
	return m;
}

