template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY) {

} // end default constructor

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
	return itemCount == 0;
} // end isEmpty

template<class ItemType>
int ArrayList<ItemType>::getLength() const {
	return itemCount;
} // end getLength


/* to insert a new entry at a given position in the array items, must create
room for the new entry by shifting the entries at and beyond this position toward
the end of array */
template<class ItemType>
bool ArrayList<ItemType>::insert(int nPosition, const ItemType& nEntry) {
	bool ableToInsert = (nPosition >= 0) 
						&& (nPosition <= itemCount) 
						&& (itemCount < maxItems);
	if (ableToInsert) {
		
	}
}

