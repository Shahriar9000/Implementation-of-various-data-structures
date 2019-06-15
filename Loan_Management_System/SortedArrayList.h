#include <iostream>
#include "ArrayList.h"

template <typename E>
class SortedArrayList: public ArrayList<E>{
public:
	SortedArrayList(int capacity): ArrayList<E>(capacity) {
	}

	bool add(const E& elem){
		if (this->n_+1> this->capacity_){
			std::cout << "adding " << elem << " failed!" << std::endl;
			return false;
		}
	
		int right_place = getRightPlace(elem);
		// shift everything right
		for (int i=this->n_-1; i>=right_place; i--)
			this->listArray_[i+1] = this->listArray_[i];

		this->listArray_[right_place] = elem;
		this->n_++;		

		return true;
	}

	bool fastSearch(const E& elem){
		return binarySearch(elem, 0, this->n_-1);			
	}

	~SortedArrayList(){
	}

protected:
	int getRightPlace(const E& elem){
		for (int i=0; i<this->n_; i++)
			if (this->listArray_[i]>= elem)
				return i;
		return this->n_;
	}

	bool binarySearch(const E& elem, int start_index, int end_index){
		if (start_index > end_index)
			return false;
		int middle_index = (start_index + end_index)/2;
		if (this->listArray_[middle_index]>elem)
			return binarySearch(elem, start_index, middle_index-1);
		else if (this->listArray_[middle_index]<elem)
			return binarySearch(elem, middle_index+1, end_index);
		else // this->listArray_[middle_index]==elem
			return true; 
	}
};
