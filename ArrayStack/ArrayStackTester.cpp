#include <iostream>
#include <string>
#include "ArrayStack.h"

int main() {
	StackInterface<std::string>* stackPtr = new ArrayStack<std::string>();
	std::string i1 = "item 1";
	std::string i2 = "item 2";
	
	stackPtr -> push(i1);
	stackPtr -> push(i2);

	std::cout << stackPtr -> peek() << std::endl;
	stackPtr -> pop();
	std::cout << stackPtr -> peek() << std::endl;

	delete stackPtr;

	return 0;
}