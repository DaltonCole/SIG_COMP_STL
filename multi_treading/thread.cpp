// g++ -std=c++11 -pthread thread.cpp
#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread
#include <vector>         // std::vector
#include <mutex>		  // std::mutex

using namespace std;

atomic<int> only_one(0);
int many(0);
mutex mtx;

void append_char() {
	//mtx.lock();
	only_one++;
	//mtx.unlock();
}

void increase_many() {
	//mtx.lock();
	many++;
	//mtx.unlock();
}

int main() {
	vector<thread> threads;

	for(int i = 0; i < 10000; i++) {
		threads.push_back(thread(append_char));
	}

	for(int i = 0; i < 10000; i++) {
		threads.push_back(thread(increase_many));
	}

	for(auto& th : threads) {
		th.join();
	}

	// Might have to run multiple times to see difference
	// Use mutexs above to fix
	cout << only_one << endl;
	cout << many << endl;

	return 0;
}