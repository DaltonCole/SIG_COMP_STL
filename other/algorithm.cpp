// g++ -std=c++14 algorithm.cpp
#include <iostream>
#include <algorithm>
#include <vector>

// Random, for funsies
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>

using namespace std;

void print(const auto& v) { // Requires c++14 for type inference. Essentially makes a template
	for(const auto& i : v) {
		cout << i << ", ";
	}
	cout << endl;
}

auto compare(const int& lhs, const int& rhs) { // C++14 deduce return type
	cout << lhs << " " << rhs << endl;
	return lhs < rhs;
}

int main() {
	// Initalize random number generator with time
	srand (time(NULL));

	vector<int> x;

	for(int i = 0; i < 10; i++) {
		x.push_back(rand() % 100);
	}
	print(x);
	
	cout << "Sort" << endl;
	sort(x.begin(), x.end()); // On average O(n*log(n)) complexity
	print(x);
	
	cout << "Compare sort, " << endl;
	sort(x.begin(), x.end(), compare);
	print(x);

	cout << "Reverse first 5 elements" << endl;
	reverse(x.begin(), x.begin() + 5);
	print(x);
	

	auto lambda = [](const int& a, const int& b) -> bool {return a < b;};

	cout << "Lambda sort" << endl;
	sort(x.begin(), x.end(), lambda);
	print(x);

	cout << "Shuffle hard!" << endl;
	shuffle(x.begin(), x.end(), default_random_engine(time(NULL)));
	print(x);
	


	// Lambda fun
	cout << "LAMBDA FUN" << endl;
	int a = 5;
	int b = 10;
	int c = 15;
	auto l1 = [&](){a = -1;};
	l1();
	cout << a << endl;

	auto l2 = [=](){cout << b << " b is read only" << endl;};
	l2();

	auto l3 = [a, &c](){/* Cant change a */ c = 3;};
	l3();
	cout << c << endl;

	// Other stuff
	if(binary_search(x.begin(), x.end(), 10)) {
		cout << "10 is in x!" << endl;
	}

	cout << "Upper bound of x: ";
	cout << *upper_bound(x.begin(), x.end(), 10) << endl;

	cout << "Max element: ";
	cout << *max_element(x.begin(), x.end()) << endl;


	cout << "Merge" << endl;
	auto y = x; // Copy constructor
	vector<int> z; 
	z.resize(20); // Needs to be big enough to hold everything
	merge(y.begin(), y.end(), x.begin(), x.end(), z.begin());
	print(z);

	// Heap - Just use a priority queue instead...
	make_heap(y.begin(), y.end());
	cout << "HEAP" << endl << y.front() << endl;
	pop_heap(y.begin(), y.end()); // Makes first element second largest, moves largest to back
	y.pop_back();
	cout << "New max: " << y.front() << endl;

	// Permuations!
	cout << "Permuations" << endl;
	z.clear();
	z = {1, 2, 3};

	do {
		print(z);
	} while(next_permutation(z.begin(), z.end()));
	// prev_permutation

	// Unique
	cout << "Unique" << endl;
	y = {1, 2, 3, 1, 2, 3};
	sort(y.begin(), y.end()); // Sort first
	auto it = unique(y.begin(), y.end()); 
	y.resize(distance(y.begin(), it)); // Resize vector (cuts off the last 3 elements)
	print(y);


	return 0;
}