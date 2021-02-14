#include <iostream>
#include <string>
#include <vector>
#include "ListInterface.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ListInterface<string>* tester = new LinkedList<string>();
	ListInterface<string>* tester2 = new LinkedList<string>();

	vector<string> strs({"one", "two", "three", "four", "five"});
	vector<string> strs2({"iphone", "ipad", "airpod", "imac", "pro display", "macbook"});

	for (string s : strs) {
		tester -> insert(1, s);
	}

	for (string s : strs2) {
		tester2 -> insert(1, s);
	}
	
	// test for equality operator
	bool equal = tester == tester2;
	cout << "equal ?: " << equal << endl;
	cout << "t1 size: " << tester -> getLength() << endl;	
	
	// test for assignment operator
	tester = tester2;
	cout << "t1 size after: " << tester -> getLength() << endl;	
	
	ListInterface<string>* curr = tester;
	int n = strs2.size();

	while (n >= 1) {
		try {
			cout << "Got element : " << curr -> getEntry(n) << " at " << n << endl;
		} catch (logic_error except) {
			cout << "failed to get entry at position" 
						<< n << endl;
		}
		n--;
	}

	tester -> clear();

	return 0;
}
