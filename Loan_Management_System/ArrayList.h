#include "ListInterface.h"
#include <iostream>

//using namespace std;

template <typename E>
class ArrayList: public ListInterface<E>{
public:
	ArrayList(int capacity){
		listArray_ = new E[capacity]; 
		n_=0; 
		capacity_ = capacity;
	}
	
	bool empty() const{return n_==0;};
	
	int count() const{return n_;}
	
	void print() const{ 
		for (int i=0; i<n_; i++) 
			std::cout << listArray_[i] << " ";
		std::cout << std::endl;
	}

	bool removeFirst(const E& elem){
		int index = findFirst(elem); 
		if (index==-1){
			std::cout << "removing " << elem << " failed!\n";
			return false;
		}
		for (int i=index; i<n_-1; i++)
			listArray_[i] = listArray_[i+1];
		n_--;	
		return true;	
	}

	bool add(const E& new_entry){
		if (n_+1 > capacity_){ // array is full
			std::cout << "adding " << new_entry << " failed\n";
			return false;
		}
		listArray_[n_] = new_entry;
		n_++;
		return true;
	}

	~ArrayList() {
		delete [] listArray_; 
	}

	E& operator[] (int &index)
	{
		return this->listArray_[index];
	}

protected:
/** Finds the first time elem apears in the list.
    @param elem The object to be found.
    @return -1 if the list does not contain elem and index of elem in listArray_ otherwise. */
int findFirst(const E& elem) const{
	for (int i=0; i<n_; i++)
		if (listArray_[i] == elem)
			return i;
	return -1;
}

	E* listArray_;
	int n_, capacity_;
};