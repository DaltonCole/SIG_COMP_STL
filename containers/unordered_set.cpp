// Requires c++11
// Compile with: g++ -std=c++11 unordered_map.cpp
#include <iostream>
// Documentation:
// http://www.cplusplus.com/reference/unordered_set/unordered_set/
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<int> set({3, 4, 5}); // Initalization list constructor, could just be () or nothing

	// Constant time insert (usually)
	for(int i = 0; i < 10; i++) {
		set.insert(i);
	}

	// Does nothing because set...
	for(int i = 0; i < 10; i++) {
		set.insert(i);
	}

	// See if element is in set
	// Constant time (usually)
	if(set.find(12) == set.end()) {
		cout << "12 is not in set" << endl;
	}

	// NO ORDERING!!!
	for(auto i : set) {
		cout << i << ", ";
	}
	cout << endl;

	return 0;
}