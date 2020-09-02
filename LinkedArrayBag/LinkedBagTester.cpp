#include <iostream>
#include <string>
#include "LinkedBag.h"

using namespace std;

void printBag(LinkedBag<string>* test) {
	vector<string> out = test->toVector();
	for(string s : out) {
		printf("%s\n", s.c_str());
	}
}

int main(int argc, char const *argv[])
{
	LinkedBag<string>* test1 = new LinkedBag<string>();
	test1->add("no1");
	test1->add("no2");
	test1->add("no3");
	printBag(test1);
	return 0;
}