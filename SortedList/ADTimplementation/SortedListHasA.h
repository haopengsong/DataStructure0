/* A sorted list can maintain its entries within a list;
 * Use a list as a data field within the class that implements the sorted list;
 * This is called Composition => illustrates has-a relationshiop between the class of 
 * 	sorted lists and the class of lists;
 * ADT sorted list using the ADT list
 * Chapter 12-3
 * /
#ifndef SORTED_LIST_HAS_A_
#define SORTED_LIST_HAS_A_

#include <memory>
#include "SortedListInterface.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class SortedListHasA : public SortedListInterface<ItemType> {
private:
	std::unique_ptr<ListInterface<ItemType>> listPtr;

public:
	SortedListHasA();
	SortedListHasA(const SortedListHasA<ItemType>& alist);
	virtual ~SortedListHasA();
	
};
