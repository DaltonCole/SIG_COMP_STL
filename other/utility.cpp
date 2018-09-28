#include <iostream>
#include <utility>

using namespace std;

int main() {
	pair<int, char> x(10, 'A');

	auto y = make_pair(11, 'B');

	cout << x.first << " " << x.second << endl;

	cout << y.first << " " << y.second << endl;

	return 0;
}