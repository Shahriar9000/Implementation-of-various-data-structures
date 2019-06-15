#include "binaryTreeInterface.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>  





template <typename E>

class binaryTree: public binaryTreeInterface<E>{

	//protected:

public:

	vector <E> _array;
	vector <bool> _valid;
	//E parent;
	//E right_child;
	//E left_child;

public:

	/*binaryTree()
	{
		for (int i = 0; i < 50; i++)
			_valid.push_back(false);
	}*/

	
	virtual void addNode(E itm)
	{	
		//int index = 0;
		_array.push_back(itm); 
		_valid.push_back(true);


		/*if (_array.empty())
		{
			
			_array.push_back(itm);
			_valid[index]=true;
		}

		else
		{	
			
			 _array.push_back(itm);

			 index = _array.size() ; 

			 _valid[index] = true;

		}*/
	}

	int search_element(E itm)
	{

		for (int i =0; i <_array.size() ;i++)
		{
		
			if (_valid[i] == true && _array[i] == itm)
			{
				return i;
			}

		}

		return -1;

	}

	void remove_all(E itm)
	{			

		/*int index = search_element(itm);

		while (index != -1)
		{

			_array.erase(_array.begin() + index);
			_valid.erase(_valid.begin() + index);

			index = search_element(itm);
		}*/

		bool X = true;

		while (X != false)
		{
			X = remove_one(itm);
		}
		

	}


	bool remove_one(E itm)
	{	
		int index = search_element(itm);

		if (index != -1)
		{

			_array.erase(_array.begin() + index);
			_valid.erase(_valid.begin() + index);


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



	



































