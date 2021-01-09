/*
1) Private inheritance enables you to use the methods of a base class without 
giving a client access to them
2) Just inherit members from the existing class 
3) ch 12.3.3
*/

#ifndef SORTED_LIST_AS_A_
#define SORTED_LIST_AS_A_

#include <memory>
#include "SortedListInterface.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class SortedListAsA : public SortedListInterface<ItemType>, private LinkedList<ItemType> {
public:
	SortedListAsA();
	SortedListAsA(const SortedListAsA<ItemType>& list);
	virtual ~SortedListAsA();
	//... same as SortedListHasA
		
};
#include "SortedListAsA.cpp"
#endif

