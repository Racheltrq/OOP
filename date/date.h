class Date{
	public:
		Date(int y, int m, int d);
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		int year();
		int month();
		int day();
		bool isvalid();
	private:
		int y;
		int m;
		int d;
};