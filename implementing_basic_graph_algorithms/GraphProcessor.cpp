#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <list>
#include <cmath>

using namespace std;

unordered_map<int,vector<int>> G; // the adjacency list
int n = 0;
unordered_map<int,vector<int>> Edge_list;
vector<int> cycle;







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







bool search_for_cycle(int v, vector<bool>& visited, int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    cycle.push_back(v);
 
    for(auto i = Edge_list[v].begin(); i != Edge_list[v].end(); ++i)
    {
        
        if(!visited[(*i)])
        {
           if (search_for_cycle((*i), visited, v))
              return true;
        }

        else if ((*i) != parent)
           return true;
    }
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool if_cycle_exists()
{
    vector<bool> visited(n);
   
    for(int v = 0; v < n; v++)
        visited[v] = false;
 
    for (int u = 0; u < n; u++)
        if (!visited[u]) 
          if (search_for_cycle(u, visited, -1))
             return true;
 
    return false;
}


void DFS(int v, vector<bool>& visited, vector<int>& ret)
{
    
    visited[v] = true;
   // cout << v ;
    ret.push_back(v);
   
    for(auto i = Edge_list[v].begin(); i != Edge_list[v].end(); ++i)
        if(!visited[(*i)])
        {	//cout<<",";
    		
            DFS((*i), visited, ret);
        }
}

bool less_than(int small ,int large) { return (small<large); }

void find_minimum_edge()
{
	vector<bool> visited(n);

    for(int v = 0; v < n; v++)
        visited[v] = false;


	for (int i = 0; i < G.size(); i++)
	{	
		int min = RAND_MAX, min_index;
		int traversal_index = 0;

		for (auto it = G[i].begin(); it != G[i].end() ; it++)
		{   

			if ((*it) == 0)
			{	
				traversal_index++;
				continue;

			}

			if ((visited[traversal_index] == false || visited[i] == false) && (*it) < min)
			{
         			min = (*it);
         			min_index = traversal_index;
         			
   			}
			
			traversal_index++;

		}
		
		if (min == RAND_MAX)
				continue;
	
		if(min_index < i)
		{	
		
			cout << min_index << " " << i << endl;
		
		
		}
		else
			cout << i << " " << min_index << endl;
			
		visited[i] = true;
		visited[min_index] = true;
	}

}


int main(int argc, char** argv)
{
	if (argc!=2)
	{
		cout <<"Parameters: executale.o graph.txt" << endl;
		return 1;
	}
	

	fstream file;
	file.open(argv[1]);

	string line;

	while (getline(file,line).good()){
		vector<string> tokens;
		Tokenize(line, tokens, " \t");	
		for (int i = 0; i < tokens.size(); ++i)
		{

			int weight = atoi(tokens[i].c_str());
			
			G[n].push_back(weight);
			if (!weight==0)
				Edge_list[n].push_back(i);		
			
		}	

		n++;
			
		
	}

	file.close();



	cout << "Connected components:" << endl;
	vector<bool> visited(n);
   
    for(int v = 0; v < n; v++)
        visited[v] = false;
 
    for (int v=0; v<n; v++)
    {
        if (visited[v] == false)
        {
            
            vector<int> connected;

            cout << "{";
          
            DFS(v, visited, connected);

            sort (connected.begin(), connected.end(), less_than);

            for (int i = 0; i < connected.size()-1; ++i)
            {
            	cout << connected[i] << ",";
            }
 
            cout << connected[connected.size()-1] <<"}" <<"\n";
        }
    }

 //    vector<bool> existence_of_something_Change_koris_aita_PORE(n);

 //    for(int v = 0; v < n; v++)
 //        existence_of_something_Change_koris_aita_PORE[v] = false;


	// for (int i = 0; i < G.size(); i++)
	// {	
	// 	int min = RAND_MAX, min_index;
	// 	int traversal_index = 0;

	// 	for (auto it = G[i].begin(); it != G[i].end() ; it++)
	// 	{   

	// 		if ((*it) == 0)
	// 		{	
	// 			traversal_index++;
	// 			continue;

	// 		}

	// 		if ((existence_of_something_Change_koris_aita_PORE[traversal_index] == false || existence_of_something_Change_koris_aita_PORE[i] == false) && (*it) < min)
	// 		{
 //         			min = (*it);
 //         			min_index = traversal_index;
         			
 //   			}
			
	// 		traversal_index++;

	// 	}
		
	// 	if (min == RAND_MAX)
	// 			continue;
	
	// 	if(min_index < i)
	// 	{	
		
	// 		cout << min_index << " " << i << endl;
		
		
	// 	}
	// 	else
	// 		cout << i << " " << min_index << endl;
			
	// 	existence_of_something_Change_koris_aita_PORE[i] = true;
	// 	existence_of_something_Change_koris_aita_PORE[min_index] = true;
	// }





	if (if_cycle_exists())
	{	
		cout << "A cycle: " ;
		for (int i = 0; i < cycle.size(); ++i)
			cout<<cycle[i]<<" ";
		cout<<"\n";
	}
	else
		cout << "No cycles" << endl;

	cout<< "Edges in minimum spanning trees:" << endl;
	find_minimum_edge();

	
	return 0;
}
