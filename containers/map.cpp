// Compile with: g++ -std=c++17 map.cpp
#include <iostream>
// Documentation: 
// http://www.cplusplus.com/reference/map/map/
#include <map>

// There is also a multi map version

// Random, for funsies
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main() {
	// Initalize random number generator with time
	srand (time(NULL));

	map<int, int> count;

	for(int i = 0; i < 10000; i++) {
		count[rand() % 10]++; // Default constructor to 0 if not in map
	}

	int erase_it = rand() % 10;

	// Create variable it in if statement scope. c++17 feature
	if(auto it = count.find(erase_it); it != count.end()) {
		cout << "Removing " << erase_it << endl;
		count.erase(it);
	}

	// Could not use variable "it" in this scope

	for(const auto& pair : count) {
		cout << pair.first << ": " << pair.second << endl;
	}

	return 0;
}