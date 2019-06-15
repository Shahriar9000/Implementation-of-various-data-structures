#include "tttboard.h"
#include <vector>
#include <iostream>

using namespace std;

const int X =1;
const int O =-1;
const int EMPTY = 0;



tttboard::tttboard(int n, vector<int>& board)
{
	n_ = n;
	for (int i=0; i< n*n; i++)
		b_.push_back(board[i]);
}



vector<tttboard> tttboard::possibleNextBoards(int turn) const{
	vector<tttboard> children;


	//vector <int> next_posssible_board = b_;

	for (int i = 0; i < b_.size(); i++)
	{	
		vector <int> next_posssible_board = b_;

		if (b_[i] == EMPTY)
		{
			next_posssible_board[i] = turn;
			tttboard next_board(n_, next_posssible_board);
			children.push_back (next_board);
		}

	}
	
	//ToDo for step 2

	return children;		
}


bool tttboard :: operator==(const tttboard& board) const
{
	if ((this->n_ == board.n_) && (this->b_ == board.b_))
        return true;
    else
        return false;
}



ostream& operator << (ostream& output, const tttboard& p)
{	
	
    output<< "{";
    for (int i=0; i <= p.b_.size()-2 ; i++)
    {
        output << p.b_[i] << ",";
    }
  
  	 output << p.b_[p.b_.size()-1] << "}";

    return output;
}

