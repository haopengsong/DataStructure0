#include <iostream>
#include "QueueInterface.h"
#include "ArrayQueue.h"
#include <string>

int main() {
	QueueInterface<std::string>* qq = new ArrayQueue<std::string>(5);
	qq -> enqueue(" test1 ");
	qq -> enqueue(" test2 ");
	qq -> enqueue(" test3 ");
	qq -> enqueue(" test4 ");
	std::cout << qq -> enqueue(" test5 ") << std::endl;
	std::cout << qq -> enqueue(" test6 ") << std::endl;
	std::cout << qq -> Front() << std::endl;
	std::cout << qq -> Rear()  << std::endl;	
	return 0;
}
