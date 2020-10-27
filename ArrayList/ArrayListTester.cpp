#include <iostream>
#include <string>
#include "ArrayList.h"

using namespace std;

const int item_count = 6;

int main() {
	ListInterface<string>* listPtr = new ArrayList<string>();
	string data[] = {"one", "two", "three", "four", "five"
					, "six"};
	cout << "isEmpty: returns " << listPtr -> isEmpty() << 
	" should be 1 (true) " << endl;

	for (int i = 0; i < item_count; i++) {
		if (listPtr -> insert(i, data[i])) {
			try {
				cout << "Inserted: " << listPtr -> getEntry(i) <<
				" at position " << i << endl;

			} catch (logic_error except) {
				cout << "failed to get entry at position" 
						<< i << endl;
			}
		} else {
			cout << "Cannot insert " << data[i] 
			<< "at position " << i << endl;
		}
	}

	cout << "isEmpty(): " << listPtr -> isEmpty() << endl;

	return 0;
}