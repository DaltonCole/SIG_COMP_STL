#include <iostream>
// Documentation: 
// http://www.cplusplus.com/reference/set/set/
#include <set> // Sorted based on < or function call

// Also a multiset variant

using namespace std;

struct Point {
	int x;
	int y;

	bool operator()(const Point& lhs, const Point& rhs) {
		return lhs.x + lhs.y < rhs.x + rhs.y;
	}

	void print() {
		cout << x << ", " << y << endl;
	}
};

int main() {
	set<char> s;

	for(int i = 65; i < 80; i++) {
		s.insert(i);
	}

	// Does nothing because already in set
	for(int i = 65; i < 80; i++) {
		s.insert(i);
	}

	if(s.find('A') != s.end()) {
		cout << "FOUND A" << endl;
	}

	for(auto i : s) {
		cout << i << endl;
	}

	// Example with class
	set<Point, Point> p_set;
	//  ^ Fill with point types
	// 		   ^ Use Point's () function for comparison
	//			Could make a whole class just to do this
	//			In Ninja's we made function classes
	Point p;

	for(int i = 0; i < 10; i++) {
		p.x = i;
		p.y = i + 1;
		p_set.insert(p);
	}

	cout << "\nPoint Set:" << endl;
	for(auto i : p_set) {
		i.print();
	}

	return 0;
}