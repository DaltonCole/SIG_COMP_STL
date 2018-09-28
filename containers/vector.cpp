#include <iostream>
// Documentation: 
// http://www.cplusplus.com/reference/vector/vector/
#include <vector>

using namespace std;

int main() {
	// --- Initalization --- //
	// A vector is essentially a dynamicly allocated array
	vector<int> v(10, 0); // 10 elements with 0 in them

	// Dynamic array version
	int size = 10;
	int* dynamic_array = new int[size](); // "unknown" size for array
	//								   ^ Anything but this gives errors

	// Range based for loop
	for(auto& i : v) {
		//  ^ Allows me up update i in v
		// Update all values in v to 1
		i = 1;
	}

	// Updating value using indexing
	for(int i = 0; i < 10; i++) {
		v[i] = i;
	}

	// How to add elements push_back(x)
	for(int i = 10; i < 20; i++) {
		v.push_back(i);
	}

	// How to remove elements
	// Good way - last 5
	for(int i = 0; i < 5; i++) {
		v.pop_back();
	}
	// Bad way - first 5
	v.erase(v.begin(), v.begin() + 5); // Should have a guard here, can cause seg-fault if + 100 instead

	// Same idea with .insert

	if(v.empty() != true) {
		for(auto i : v) {
			cout << i << endl;
		}

		// How to clear out a vector
		v.clear();
	}

	// --- Clean up --- //
	// Vector = done, cleans itself up

	// Dynamic array
	delete[] dynamic_array;

	return 0;
}