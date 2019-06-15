#ifndef GTREE_H 
#define GTREE_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename E>
class gTree;

template <typename E>
class gTNode{
  public:
	gTNode(E data, gTNode<E>* parent):data_(data),parent_(parent){}
	E getData(){ return data_;}

	gTNode<E>* getParent(){return parent_;};

	std::vector<gTNode<E>*> & getChildren() {return children_;}

	void addChild(E data){
		gTNode<E>* c= new gTNode<E>(data, this);
		children_.push_back(c);
	}

	~gTNode(){
		for (int i=0; i< children_.size(); i++){
			delete children_[i];
			children_[i]=NULL;
		}
	}

	bool remove(){
		if ((parent_==NULL) && (children_.size()>0)){
			cout << "can't remove the root if it has children\n";
			return false;
		}
		else{

			parent_->children_.erase(std::remove(parent_->children_.begin(), parent_->children_.end(), this), parent_->children_.end());		
	
			for (int i=children_.size()-1;i>=0; i--){
				//ToDo
				children_[i]-> parent_=parent_;
                parent_->children_.push_back(children_[i]);
                children_[i]= NULL;
            }
                
            delete this;
            return true;
		}
	}	

	friend class gTree<E>;

  private:
	E data_;
	gTNode<E>* parent_;
	std::vector<gTNode<E>*> children_;
};

template <typename E>
class gTree{
  public:
	gTree():root_(NULL){}

	bool addNode(E itm, gTNode<E>* parent){
		if (parent == NULL){
			if (root_ == NULL)
				root_ = new gTNode<E>(itm, NULL);
			else{
				cout << "Tree already has a root. " << itm << " was not added. \n";
				return false;
			}
		}
		else {
			parent->addChild(itm);
		}
		return true;
	}

	gTNode<E>* getRoot(){ return root_; }

	bool isEmpty(){ return root_==NULL; }

	~gTree(){ delete root_; }

  private:
	gTNode<E>* root_;
};

template <typename E>
gTNode<E>* findItem(gTNode<E>* v, E itm){
	if (v==NULL)
		return NULL;
        if (v->getData()==itm)
                return v;
        gTNode<E>* result_sofar = NULL;
        vector<gTNode<E>*> ch = v->getChildren(); // list of children
	
        for (int i=0; i < ch.size(); i++){
                result_sofar = findItem(ch[i], itm);
                if (result_sofar != NULL)
                        return result_sofar;
        }
        return result_sofar;
}

template<typename E>
void preorderPrint(gTNode<E>* v) {
     	if (v==NULL)
		return;
	cout << v->getData(); // print element
        vector<gTNode<E>*> ch = v->getChildren(); // list of children
        for (int i=0; i < ch.size(); i++) {
                cout << " ";
                preorderPrint(ch[i]);
        }
}

template<typename E>
void postorderPrint(gTNode<E>* v) {
	//ToDo : implement the post order traversal 
	if (v==NULL)
		return;
	vector<gTNode<E>*> ch = v->getChildren();
	for (int i=0; i < ch.size(); i++) 
	{		
		postorderPrint(ch[i]);
		cout << " ";
	}

	cout << v->getData();
}

template<typename E>
int size(gTNode<E>* v) {
  // ToDo: recursively compute the size of the sub-tree rooted at the given node and return it
  	unsigned int s = 1;


  	if (v == NULL)
  	{
  		return 0;
   	}	
  		
    for (int i=0; i < v->getChildren().size(); i++)
    {
       gTNode<E>* ch = v->getChildren()[i];
       s= s + size(ch);
    }
    
    return s;
  	
     
}

#endif


