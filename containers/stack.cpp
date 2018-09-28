#include <iostream>
// Documentation:
// http://www.cplusplus.com/reference/stack/stack/
#include <stack>

// Random, for funsies
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main() {
	// Initalize random number generator with time
	srand (time(NULL));

	stack<int> s;

	for(int i = 0; i < 10; i++) {
		// Push element on top of stack
		s.push(rand() % 100);
	}

	for(int i = 0; i < 10; i++) {
		// Print top element
		cout << s.top() << endl;
		// Pop off what was on top
		s.pop();
	}

	return 0;
}