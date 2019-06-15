#include <iostream>
#include <vector>
#include <algorithm>
#include "Utility.h"

using namespace std;


ostream& operator<<(ostream& out, const n_gram& ng){
                out << "(";
                for (int i=0; i<ng.n_-1; i++)
                        out << ng.words_[i] << ",";
                out << ng.words_[ng.n_-1]<< ")";
                return out;
        }

bool n_gram::operator== (const n_gram& str1) const
{

        if ((str1.n_ == n_) && (str1.words_ == words_))
                return true;
        else
                return false;



}

vector<string> n_gram::getwords() const
{
    return words_;
}


std::size_t n_gram_hash::operator () (const n_gram& str) const{


        int s=0;

        for (int i=0; i< str.words_.size(); i++)
        {
                string current_index = str.words_[i];

                for (int j = 0; j < current_index.size(); j++)
                {
                        s+= 2^i + (int)current_index[j];
                }
        }
                
                

        return s;
}


void Tokenize(string line, vector<string> & tokens, string delimiters){
	string token = "";
        string OneCharString = " ";
        for (int i=0; i<line.size(); i++)
                if (find(delimiters.begin(), delimiters.end(), line[i])!=delimiters.end()) // line[i] is one of the delimiter characters
                {
                        if (token != "")
                                tokens.push_back(token);
                        token = "";
                }
                else
                {
                        OneCharString[0] = line[i];
                        token +=OneCharString;
                }

        if (token != "")
                tokens.push_back(token);
}

