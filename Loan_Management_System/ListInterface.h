/** @file ListInterface.h 
    Defines ADT List.
*/

template <typename E>
class ListInterface{
public:
	/** Adds a new entry to this list.
	    @post If successful, newEntry is stored in the list and
	    the count of items in the bag has increased by 1.
	    @param newEntry The object to be added as a new entry.
	    @return True if addition was successful, or false if not. */
	virtual bool add(const E& newEntry) = 0;   

	/** Removes the first instance of elem from this list.
            @post If successful, the count of items in the list has decreased by 1.
            @param elem The object to be removed.
            @return True if removal was successful, or false if not. */
	virtual bool removeFirst(const E& elem) = 0;

	/** Determines if the list is empty.
            @return True if the list contains no element, or false if not. */
	virtual bool empty() const = 0;

	/** @return The number of elements in the list.*/
	virtual int count() const = 0; 

	/** Destructs the object.
	    @post all allocated memory is released.*/
	virtual ~ListInterface() {};

	/** prints the list to standard output.*/
	virtual void print() const = 0;
};
