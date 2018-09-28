#include <iostream>
#include <memory>

using namespace std;

int main() {
	// Normal pointer
	int* normal_p = new int(10);
	int* other_norm_p = nullptr; // nullptr is c++11

	if(other_norm_p == nullptr) {
		other_norm_p = normal_p;
	}

	cout << *normal_p << endl;
	cout << *other_norm_p << endl;

	delete normal_p;

	// Shared pointer
	// http://www.cplusplus.com/reference/memory/shared_ptr/
	shared_ptr<int> sp1(new int(10));
	shared_ptr<int> sp2(sp1);

	cout << "Usage count: " << sp1.use_count() << endl;
	cout << "Is unique?: " << sp1.unique() << endl;

	sp1.reset(new int(11)); // 10 still exists because another pointer points to it
	cout << *sp1 << endl;
	cout << *sp2 << endl;

	cout << "Is unique now?: " << sp1.unique() << endl;

	// Unique Pointer
	unique_ptr<int> up1(new int(9));
	// unique_ptr<int> up2 = up1; // Brakes because unique!
	cout << *up1 << endl;

	return 0;
}