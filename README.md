# Implementing basic graph algorithms
      In this assignment, we will receive the adjacency matrix of a weighted undirected graph from a text file and do the following:

     1. output its connected components, one per line when each connected component is represented as the set of its vertices; 30%
    2. output one cycle as u_1 u_2 ...u_i .... u_1 if the graph has any cycles, or output "No cycles" if it doesn't; 40%
    3. output all the edges in the minimum spanning trees of each of its components. 30%

# Loan management system
      You are writing a start-up-loan approval system for a bank.

      The bank takes a maximum of 5000 loan applications and deny them only if the applicant doesn't qualify (he/she is not educated or experienced in the field). If the applicant qualifies, the loan will be eventually approved (although there is no guarantee if that happens in the lifetime of the applicant!).

        The bankers may write commands like the following:
      save_application
       parameters:
      string applicant_full_name // This is unique and identifies a loan_application.
    int years_of_relevant_education
    int years_of_relevant_experience
    int loan_amount
    int* estimated_yearly_profits // A sequence for how much the bank would profit from the customers' payback in each year (for up to 30 years)
    explanation: saves the incoming application into an active_applications list

      make_decisions
      parameters:
    string decision_date
    int budget
    explanation: denies the applications (i.e. removes them from active_applications and saves them to denied_applications list) where the sum of education and experience years is smaller than 10. Approves applications (i.e. removes them from active_applications and saves them to approved_applications list) in the order of their priority (defined later) if enough money is left from the given budget. priority 
 
# Game tree of tic-tac-toe
    Many two-player games in computer science can be represented via general trees. Game trees are of interest because they are helpful for finding the best next move or for determining if there is any chance of winning (otherwise one could resign). Given any state of a game, if all next states are winning states (for the other player), this state is a losing state (because no matter what move the current player plays, he/she will end up in a state that the other player can win); and if at least one of the next states are a losing state (for the other player) this state is a winning state because the current player has one move that he/she can play that leads to the ultimate loss of the other player. While not all games can be played only based on game trees, some are simple enough that this approach is attemptable. An example of such simple game is Tic-Tac-Toe.

      Tic-Tac-Toe can be represented as a tree where nodes are boards and children of a board are all possible boards that we can get from the current board by playing only one move. The following figure shows a subtree of Tic-Tac-Toe tree rooted at a losing board (O must play and it can't win). 

      Assignment steps

     1. Implement a class tttboard that represent one node in the tic-tac-toe tree (one given board) which can be used as the base type in the generic implementation of the general tree you completed in lab4. 30%
    You are given the header and implementation files of the class as well as a tester file. The tester takes the representation of a board as input and tries adding some other board (not necessarily a valid next board) as its child. You need to add any constructor, function, operator, etc. that is needed for the tester file to work.
    2. Implement the tttboard::possibleNextBoards function that returns a vector of ALL immediately next boards from the current board. Even though it is possible to determine whose turn it is given a board, this function takes the turn as input for simplicity.
    3. Make a tic_tac_toe.cpp file that takes an n as an input, makes a complete game tree for a tic-tac-toe on a board of size n*n, prints it in pre-order and post-order traversal fashion and gives the size of the tree at the end. 35%
    4. Expand the tic_tac_toe.cpp in a way that if a board is given to it as the second argument, it would print one of the following: "winning board", "losing board", or "not sure". 20%
      Remember that a "winning board" is a winning board for the player who should play it and not the player who has just played               his/her move
      
# Vector based binary tree implementation
   Steps

    1. Inherit a class "binaryTree" from binaryTreeInterface.h and overload all the functions. When adding and removing items, the order doesn't matter at all. You can add anywhere in the tree and move items around when removing an item if you need to. 30%
    2. Inherit a class "binarySearchTree" from "binaryTree" of the previous step or the binaryTreeInterface.h and overload at least the addNode, remove_one, and remove_all functions. Remember that in a binary search tree, in-order traversal of the tree visits the items in the increasing order. Overloading the addNode is worth 30% of the mark, overloading remove_one is worth another 30% and overloading remove_all is worth 10% of the mark.

# Solving problems using unordered_map
 Steps
There are three steps in this assignments and they are independent of each other:

    1. 40% Implement operator== for n_gram class and define and implement a hash code class n_gram_hash for it so that ngram.cpp compiles and runs. If it runs correctly, it will produce unigrams.txt and bigrams.txt, two files that will list unigrams (words) and bigrams (pairs of consequent words) in corpus.txt along with their frequencies. You may find lab7 useful while completing this step. You must declare n_gram_hash class in Utility.h and implement it in Utility.cpp. 
    2. 30% Write a C++ program that takes a file containing n pairs of strings as input, and tells us which pair appeared together most often in O(n). If there are more than one pair that co-occur most often, output any of them. The order in the pair doesn't matter (for example (str1,str2) is the same as (str2, str1)). Each line in the input file contains a pair of strings separated by a tab character ('\t'). The program MUST compile and run as follows:

      g++ -c Utility.cpp 
      g++ --std=c++0x -o MostOftenPair.o MostOftenPair.cpp Utility.o
      ./MostOftenPair.o MostOftenPair_input.txt
      Str2 and Str3 occurred together most often: #occurrence=3

    3. 30% Write a C++ program that takes a vector of n integers and an integer S as input and outputs the indices of a pair of items in V that sum to S. If such a pair doesn't exist, the program announces (-1,-1) as the answer. The program must be of O(n) and MUST compile and run as follows: 

# Evaluating an arithmetic expression

      Introduction

      As it is defined in question C-5.8 in your textbook, postfix notation is an unambiguous way of writing an arithmetic expression without parentheses. It is defined so that if "(exp1 ) ⊗ (exp2 )" is a normal fully parenthesized expression whose operation is "⊗", then the postfix version of this is "pexp1 pexp2 ⊗", where pexp1 is the postfix version of exp1 and pexp2 is the postfix version of exp2 . The postfix version of a single number or variable is just that number or variable. So, for example, the postfix version of "((5 + 2) * (8 - 3))/4" is "5 2 + 8 3 - * 4 /".

      A normal expression may have more than one acceptable fully parenthesized version though. For example 2 + 3 + 4 + 5 can be fully parenthesized as ((2 + 3) + (4 + 5)) or (((2 + 3) + 4 ) + 5). It follows that a normal expression may have more than one equivalent postfix notation. Here are some examples of normal (not necessarily fully parenthesized) expressions and one possible postfix notation for them.
     normal expression 	  postfix notation
       (5+2+3*4)*((2+3)*(5-3))   	  5 2 + 3 4 * + 2 3 + 5 3 - * *   
    ((8-12) + 4 * 20) / (14 - 12) + 7   	  8 12 - 4 20 * + 14 12 - / 7 +  
      12 + 3 - 6 + 8   	  12 3 + 6 - 8 +  
       5 * 2 / 4 * 3   	  5 2 * 4 / 3 *  
    ( 12 + 3 ) - (6 + 8)   	  12 3 + 6 8 + -  
      The assignment

      postfix expressions can be evaluated non-recursively using stack ADT. The goal of this assignment is to write a program that evaluates a given normal (not necessarily fully parenthesized) expression by transforming it into an equivalent postfix notation, and evaluating that using stacks.

      The assignment is broken into 4 steps for you:

    Implement a generic stack based on a Linked List. The name of the class MUST be genericLinkedListStack and you MUST put it in genericLinkedListStack.h file. You are not allowed to use any of the STL containers but you are welcome to use whatever code that is provided for you on the course homepage or on the slides. Also, make sure you add a print() function so that we can test this class independently. (15%)
    Write a function getPostfix (with the following signature) that takes a normal (not necessarily fully parenthesized) expression and returns one of its equivalent postfix notations. You can do this recursively if you wish. Put this function in the postfixUtility.h file. (40%)

    string getPostfix(string nexp) 

    Write a function evaluatePostfix (with the following signature) that takes a postfix expression and evaluates it. Put this function in postfixUtility.h and .cpp files. You will get a full mark for this step even if you use the STL stack. To get a full mark on the next step however, you MUST use your implementation of genericLinkedListStack in evaluatePostfix function. (30%)

    float evaluatePostfix(string pexp)

    Write a main function in main.cpp file that takes a string containing a normal (not necessarily fully parenthesized) expressions as an argument and prints its numerical equivalent to the standard output. You MUST use the functions you implemented in postfixUtility.h. If you want a full mark on this step, you MUST use your implementation of genericLinkedListStack in your implementation of evaluatePostfix function. Your file MUST compile and run as follows: (15%)

    g++ -c postfixUtility.cpp
    g++ -o main.o main.cpp postfixUtility.o
    ./main.o "(4+3* 12)/ ( 12+ 3/ 2+ 46 /4)"
    1.6

