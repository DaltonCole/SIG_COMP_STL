// Compile with: g++ -std=c++17 map.cpp
#include <iostream>
// Documentation: 
// http://www.cplusplus.com/reference/deque/deque/
#include <deque>

// Pronounced DECK
// IT'S LIKE A STACK AND A QUEUE IN ONE!!!! :D

// Random, for funsies
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main() {
	// Initalize random number generator with time
	srand (time(NULL));

	deque<int> deck;

	for(int i = 0; i < 10; i++) {
		if(rand() % 2 == 0) {
			deck.push_front(i);
			// Don't do this, use and else instead
			continue;
		}
		deck.push_back(i);
	}

	while(!deck.empty()) {
		if(rand() % 2 == 0) {
			cout << "Front: \t" << deck.front() << endl;
			deck.pop_front();
		} else {
			cout << "Back: \t" << deck.back() << endl;
			deck.pop_back();
		}
	}
}