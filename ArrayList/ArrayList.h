/** ADT list: Array-based implementation
@file ArrayList.h
*/

#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

#include "../List/ListInterface.h"
#include "../LinkedList/PrecondViolatedExcept.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType> {
private:
	static const int DEFAULT_CAPACITY = 100; // Default capacity of the list
	
}