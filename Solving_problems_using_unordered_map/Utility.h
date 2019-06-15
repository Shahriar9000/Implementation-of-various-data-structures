#ifndef STRING_UTILITY_H
#define STRING_UTILITY_H

#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <math.h>
#include <string>


using namespace std;

class n_gram{
public:
        n_gram(int n, const vector<string>& v):n_(n), words_(v){}

         bool operator == (const n_gram& str1) const;

         vector<string> getwords() const;

        friend ostream& operator<<(ostream& out, const n_gram& ng);
        friend class n_gram_hash;

private:
        int n_;
        vector<string> words_;

};

void Tokenize(string line, vector<string> & tokens, string delimiters = "\t ");



class n_gram_hash{

public:

    std::size_t operator() (const n_gram& str) const;


};

#endif