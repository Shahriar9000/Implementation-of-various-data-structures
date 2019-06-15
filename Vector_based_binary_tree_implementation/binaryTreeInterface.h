#ifndef BINARYTREEINTERFACE_H 
#define BINARYTREEINTERFACE_H

using namespace std;

template <typename E>
class binaryTreeInterface{
  public:
	virtual void addNode(E itm)=0;

	void remove_all(E itm);

	// tries removing one instance of itm
	// if the tree doesn't contain itm returns false
	bool remove_one(E itm);

	bool isEmpty();

	int size();

	void preOrderPrint();
	
	void postOrderPrint();

	void inOrderPrint();

	int height();
};


#endif

