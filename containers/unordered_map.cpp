// Requires c++11
// Compile with: g++ -std=c++11 unordered_map.cpp
#include <iostream>
// Documentation:
// http://www.cplusplus.com/reference/unordered_map/unordered_map/
#include <unordered_map>

// Just like with unordered_multiset, there is a unordered_multimap

using namespace std;

int main() {
	// Unordered map
	// Requires the key to be hashable
	// Any primitive is hashable
	// For your own class, do some weird stuff I can show you
	unordered_map<string, int> map;

	// Add elements = constant time (usually)
	map["apple"] = 10;
	map["banana"] = 3;
	map["orange"] = 12;

	// Access elements = constant time (usually)
	cout << map["apple"] << endl;

	// Access in range based for loop
	for(auto pair : map) {
		cout << pair.first << ": " << pair.second << endl;
	}

	// Find if key exists
	if(map.find("apple") != map.end()) {
		cout << "FOUND APPLE! :D" << endl;
	}

	// Default constructor for new keys
	cout << map["this key does not exist"] << endl;

	// See what the hash function would print out (never used this, but looked cool)
	// fn is of type unordered_map<string, int>::hasher
	auto fn = map.hash_function();
	cout << "hash(\"bob\") = " << fn("bob") << endl;

	return 0;
}