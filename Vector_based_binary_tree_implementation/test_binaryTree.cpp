#include "binaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
	binaryTree<int> ibt;
	vector<int> v={10, 12, 102, 11, 83, 51, 23, 4, 91, 51, 23, 51};
        for (int i=0; i<v.size(); i++)
                ibt.addNode(v[i]);

	cout << "pre-order: ";
	ibt.preOrderPrint();
	cout << endl;
	cout << "post-order: ";
	ibt.postOrderPrint();
	cout << endl;
	cout << "in-order: ";
	ibt.inOrderPrint();
	cout << endl;
	cout << "height:" << ibt.height() << endl;

	cout << "removing 10, 5, 12, 83, and all instances of 51 ...\n";
	
	ibt.remove_one(10);
	ibt.remove_one(5);
	ibt.remove_one(12);
	ibt.remove_one(83);
	ibt.remove_all(51);

	cout << "pre-order: ";
	ibt.preOrderPrint();
	cout << endl;
	cout << "post-order: ";
        ibt.postOrderPrint();
	cout << endl;
	cout << "in-order: ";
        ibt.inOrderPrint();
	cout << endl;
	cout << "height:" << ibt.height() << endl;

	cout << "\n Now working with strings:\n\n";

	binaryTree<string> sbt;
        vector<string> vs={"10", "12", "102", "11", "83", "51", "23", "4", "91", "51", "23", "51"};
        for (int i=0; i<vs.size(); i++)
                sbt.addNode(vs[i]);

	cout << "pre-order: ";
        sbt.preOrderPrint();
        cout << endl;
	cout << "post-order: ";
        sbt.postOrderPrint();
        cout << endl;
	cout << "in-order: ";
        sbt.inOrderPrint();
        cout << endl;
        cout << "height:" << sbt.height() << endl;

	cout << "removing \"10\", \"5\", \"12\", \"83\", and all instances of \"51\" ...\n";

        sbt.remove_one("10");
        sbt.remove_one("5");
        sbt.remove_one("12");
        sbt.remove_one("83");
        sbt.remove_all("51");

	cout << "pre-order: ";
        sbt.preOrderPrint();
        cout << endl;
	cout << "post-order: ";
        sbt.postOrderPrint();
        cout << endl;
	cout << "in-order: ";
        sbt.inOrderPrint();
        cout << endl;
        cout << "height:" << sbt.height() << endl;
}

