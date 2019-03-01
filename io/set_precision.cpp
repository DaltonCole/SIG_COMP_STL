#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double x = 123.4567890;

	cout << setprecision(2) << x << endl;
	cout << setprecision(100) << x << endl; // Oh no! Life isn't perfect!
	cout << setprecision(10) << x << endl;
	cout << endl << fixed << "Fixed, includes 0s, from decimal" << endl;
	cout << setprecision(2) << x << endl;
	cout << setprecision(100) << x << endl;
	cout << setprecision(10) << x << endl;

	return 0;
}