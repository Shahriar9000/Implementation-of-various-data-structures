#include "tttboard.h"
#include "gTree.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int X = 1;
const int O = -1;
const int EMPTY = 0; 


void next_boards(gTNode<tttboard>* parent, int turn)
{

	vector<tttboard> next_possible_boards = parent->getData().possibleNextBoards(turn);
	if (next_possible_boards.size() == 0)
		return;

	else
		for (int i=0; i < next_possible_boards.size(); i++)
		{
			parent->addChild(next_possible_boards[i]);
		}

		for (int i=0; i < parent->getChildren().size(); i++)
		{

			next_boards( parent->getChildren()[i], (turn* -1));
		}

}




int main(int argc, char** argv){
	if (argc!=2){
		cout << "usage: executable.o n-board";
		return 1;
	}

	int n =  atoi(argv[1]);

	vector<int> initial_empty_board;
	
	//Initially make an empty board
	for (int i=0; i< n*n; i++){      
		initial_empty_board.push_back(EMPTY);
	}

	if (n*n!= initial_empty_board.size()){
		cout<< "n and board are not consistent!\n";
		return 1;
	}

    gTree<tttboard> tttTree;
    tttboard root(n,initial_empty_board);
    tttTree.addNode(root, NULL);	




	gTNode<tttboard>* pointer_to_root = findItem(tttTree.getRoot(), root);

	int initial_turn = X;

	next_boards (pointer_to_root, initial_turn);

	
	cout << "preorder:\n" ;
	preorderPrint(tttTree.getRoot());
	cout <<"\npostorder:\n";
	postorderPrint(tttTree.getRoot());
	cout << "\nsize:" << size(tttTree.getRoot())<< endl;
	
	return 0;


}


