class Date{
	public:
		Date(int y, int m, int d);
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		int month();
		bool isvalid();
	private:
		int y;
		int m;
		int d;
};