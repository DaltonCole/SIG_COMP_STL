#include <iostream>
// Documentation: 
// http://www.cplusplus.com/reference/queue/queue/
#include <queue>

using namespace std;

int main() {
	queue<int> q;

	// Insert
	for(int i = 0; i < 10; i++) {
		q.push(i);
	}

	// Emplace example
	// Calls constructor of templated type
	q.emplace(12); // will call int(12) and push()

	// Pop
	while(q.empty() != true) {
		cout << q.front() << endl; // Differnt from stack
		q.pop(); // Just like stack
	}

	return 0;
}