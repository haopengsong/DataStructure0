#include <iostream>
#include <string>
#include <vector>
#include "LinkedSortedList.h"
#include "SortedListInterface.h"

using namespace std;

int main() {
	SortedListInterface<string>* tester = new LinkedSortedList<string>();
	vector<string> inputs({"bro", "apple", "gray", "dog", "code"});
	
	for (string input : inputs) {
		tester -> insertSorted(input);
	}	

	SortedListInterface<string>* curr = tester;

	int n = inputs.size();

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
