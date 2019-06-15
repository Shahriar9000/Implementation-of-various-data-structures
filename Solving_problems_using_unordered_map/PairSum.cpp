#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include "Utility.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "usage: executable.o a vector and an integer\n";
        return 1;
    }

    vector<string> tokens;
    Tokenize(argv[1], tokens, " {,}");

    unordered_map<int, int> table;
    unordered_map<int, int>::iterator p;

    vector<int> integer_array;
    int number = 0;
    for (int i=0; i<tokens.size(); i++)
    {   
        number = atoi(tokens[i].c_str());
        integer_array.push_back(number);
        table[integer_array[i]]++;
    }
    
    
    int index1=0;
    int index2=0;

    while(index1 < integer_array.size())
    {
        p = table.find(atoi(argv[2]) - integer_array[index1]);
        if (p != table.end())
            break;

        index1++;
    }
    
    if (p == table.end())
    {
            cout << "answer: " << "(-1,-1)" << endl;
            return 0;
    }

     while(index2 < integer_array.size())
    {
            if (p->first == integer_array[index2])
                break;
            index2++;
    }
   

    cout << "answer: " << "(" << index1 << "," << index2 << ")" << endl;


    return 0;
}