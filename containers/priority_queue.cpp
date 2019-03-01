#include <iostream>
// Documentation: 
// http://www.cplusplus.com/reference/queue/priority_queue/
#include <queue>

// Random, for funsies
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

// I pretty much always use my own class for priority queue
// If you use priority queue with ints, you'll get a max heap
// You can easily reverse this by making a function class

class Point {
	public:
		Point(int a, int b): x(a), y(b) {}
		// Top returns a const reference to top value, so we need const
		void print() const {cout << x << ", " << y << endl;}

		bool operator()(const Point& a, const Point& b) {
		if(a.x != b.x) {
				return a.x > b.x;
			}
			return a.y > b.y;
		}

	private:
		int x;
		int y;
		//friend class Point_comparison;
};

struct Point_comparison {
	// Smallest first
	
};

int main() {
	// Initalize random number generator with time
	srand (time(NULL));

	priority_queue<Point, vector<Point>, Point> pq;

	for(int i = 0; i < 10; i++) {
		pq.emplace(rand() % 10, rand() % 10);
	}

	while(!pq.empty()) {
		pq.top().print();
		pq.pop();
	}

	return 0;
}