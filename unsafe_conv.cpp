#include "std_lib_facilities.h"

int main(){
	double a = 111111111111111112;
	int aNarrowed = a;
    double aBroader = aNarrowed;
    cout << "double: " << a << "\n"
        << "narrowed int: " << aNarrowed << "\n"
        << "broader double: " << aBroader << "\n";

    double b = 2.55;
    char bNarrowed = b;
    double bBroader = bNarrowed;
    cout << "double: " << b << "\n"
        << "narrowed char: " << bNarrowed << "\n"
        << "broader double: " << bBroader << "\n";

    double c = 2.55;
    bool cNarrowed = c;
    double cBroader = cNarrowed;
    cout << "double: " << c << "\n"
        << "narrowed boolean: " << cNarrowed << "\n"
        << "broader double: " << cBroader << "\n";

    int d = 3;
    char dNarrowed = d;
    int dBroader = dNarrowed;
    cout << "int: " << d << "\n"
        << "narrowed char: " << dNarrowed << "\n"
        << "broader int: " << dBroader << "\n";

    int e = 3;
    bool eNarrowed = e;
    int eBroader = eNarrowed;
    cout << "int: " << e << "\n"
        << "narrowed boolean: " << eNarrowed << "\n"
        << "broader int: " << eBroader << "\n";


    char f = 'a';
    bool fNarrowed = f;
    char fBroader = fNarrowed;
    cout << "char: " << f << "\n"
        << "narrowed boolean: " << fNarrowed << "\n"
        << "broader char: " << fBroader << "\n";

}
