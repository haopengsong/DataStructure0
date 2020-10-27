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
						&& (nPosition <= itemCount + 1) 
						&& (itemCount < maxItems);
	if (ableToInsert) {
		// shifting all entries at positions from itemCount down to nPosition
		// no shift if nPosition == itemCount + 1
		for (int pos = itemCount; pos >= nPosition; pos--) {
			items[pos + 1] = items[pos];
		}
		items[nPosition] = nEntry;
		itemCount++;
	}
	return ableToInsert;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const 
throw(PrecondViolatedExcept) {
	bool ableToGet = (position >= 0) && (position <= itemCount);
	if (ableToGet) {
		return items[position];
	} else {
		std::string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcept(message));
	}
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position) {
	return false;
}

template<class ItemType>
void ArrayList<ItemType>::clear() {

}

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& nEntry)
throw(PrecondViolatedExcept) {
	return nullptr;
}



















