#include <iostream>
#include <vector>
#include <execution>
using namespace std;

int main() {
	vector<int> v;

	for(int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	// Multi-threaded find
	// SUPER cool, but my comipler doesn't support it yet. :(
	// c++17 ...
	auto found = find(std::execution::par, std::begin(v), std::end(v), 2);

	cout << found << endl;

	return 0;
}