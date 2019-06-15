#include "binaryTree.h"
#include <iostream>
#include <vector>
#include <algorithm>



template <typename E>

class binarySearchTree: public binaryTreeInterface <E> {

public:

	//vector <E>baalsaal;
	vector <E> _array;
	vector <bool> _valid;
	//E parent;
	//E right_child;
	//E left_child;

public:

	binarySearchTree()
	{
		for (int i=0; i < 100 ; i++)
			_valid.push_back(0);
	}

	
	void insert_item(int i, E itm)
	{	
		
		if(_valid.at(i) == false )
        {
            _array[i] = itm ;
            _valid[i] = 1;
        }

	    else if(_array[i] <= itm) 
	    {	
	          
	            insert_item(2*i +2, itm );
	            	
	    }

	    else  
	    {
	             
	            insert_item(2*i + 1, itm );
	    }
	            	
	            
    	

	}


	 void addNode(E itm)
	{
		
		int i = 0;

        if(_array.empty())
        {
            _array.push_back(itm);
            _valid[i]=1; 

        }

        else
        {
        	insert_item(i, itm);
        }

	}

	

	
	void remove_all(E itm)
	{			


		bool X = true;

		while (X != false)
		{
			X = remove_one(itm);
		}
		


	}
	int search_element(E itm)
	{

		int currentIndex = 0;

    	while (true) 
    	{

            if (_array[currentIndex] == NULL) {

           		return -1;
          
            }

            if (_array[currentIndex] == itm) 
            {
            	return currentIndex;
            }

            else if(array[currentIndex] <= itm) 
            {
            	currentIndex = (2 * currentIndex + 2);
        	}

            else if(array[currentIndex] > itm) 
            {
            	currentIndex = (2 * currentIndex + 1);
        	}
    	}

	}

	void delete_item(int i, E itm)
	{
		if (_valid[2*i +2] == true  )
			{
				_array[i] = _array[2*index+2];
				delete_item(2*index+2, _array[2*index+2]);
			}
		else
		{
			_array[i] = _array[2*index+1];
			delete_item(2*index+2, _array[2*index+1]);
		}	


			_array.erase(_array.begin() + i);
			_valid[i]= false;


	}

	bool remove_one(E itm)
	{	
		int index = search_element(itm);

		if (index != -1)
		{
			delete_item(index, itm)
			return true;

		}

		else
			return false;
	}



	bool isEmpty()
	{
		if (!_array.empty())
			return false;
		else
			return true;
	}

	int size()
	{	
		int count =0;
		for (int i =0; i< _valid.size(); i++)
		{
			if (_valid[i]==true)
				count = count + 1;
		}
		 return count;


	
	}


	int height()
	{
		
    	int count =0;
		for (int i =0; i< _valid.size(); i++)
		{
			if (_valid[i]==true)
				count = count + 1;
		}
		 return floor (log(count)/log(2));

	}

	bool node_exists (int i)
    {
    	if (((i*2)+1)>=_array.size() || ((i*2)+2)>=_array.size()) 
    		return true;
    	else 
    		return false;
    }
 
	void preorder(int i)
	{	
		if (node_exists(i))
    	{
    		cout<<_array [i]<<" ";
    	}
		
		else
		{
           cout << _array[i] << " ";      
           preorder( i*2  +1 );    
           preorder( i*2 + 2 );   
        }

	}


	void postorder (int i)
	{
		if (node_exists(i))
    	{
    		cout<<_array [i]<<" ";
    	}
		
		else
		{
           
           preorder( i*2  +1 );    
           preorder( i*2 + 2 );   
           cout << _array[i] << " ";      
        }


	}

	void inorder(int i)
	{
		if (node_exists(i))
    	{
    		cout<<_array [i]<<" ";
    	}
		
		else
		{
           
           preorder( i*2  +1 );   
            cout << _array[i] << " ";    
           preorder( i*2 + 2 );   
             
        }
	}



	void preOrderPrint()
	{
	  cout << _array[0] << " ";
	  preorder(2*0 + 1);
	  preorder(2*0 + 2);
	}
	
	void postOrderPrint()
	{	
	
	  preorder(2*0 + 1);
	  preorder(2*0 + 2);
	  	cout << _array[0] << " ";
	}

	void inOrderPrint()
	{	
		 preorder(2*0 + 1);
		 cout << _array[0] << " ";
	  preorder(2*0 + 2);
	  	
	}


};





