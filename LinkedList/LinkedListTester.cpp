#include <iostream>
#include <string>
#include <vector>
#include "ListInterface.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ListInterface<string>* tester = new LinkedList<string>();
	vector<string> strs({"one", "two", "three", "four", "five"});

	for (string s : strs) {
		tester -> insert(1, s);
	}

	ListInterface<string>* curr = tester;
	int n = strs.size();

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