enum class Month{
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

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
		bool isleap(int y);
		Month operator++(Month &m);
	private:
		int y;
		Month m;
		int d;
};


