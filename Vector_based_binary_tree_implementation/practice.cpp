#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class BinaryTree {

public:
    class Position {
    private:
        int key;
    public:
        Position(int k) : key(k) {}
        friend class BinaryTree;
    };


protected:

    vector<T> _array;

public:
    BinaryTree()
    : _array(1) {
    }

    int size() const {
        return int(_array.size() - 1);
    }

    BinaryTree& operator=(const BinaryTree& t) = default;

    BinaryTree(const BinaryTree& t) = default;

    void print() {
        cout << "size is: " << size() << endl;
        for (int i = 1; i <= size(); i++) {
            cout << _array.at(i) << "\t";
        }
    }

public:

    void swapElements(const Position& p1, const Position& p2) {
        swap(_array[p1.key], _array[p2.key]);
    }

    void replaceElement(const Position& p, const T& e) {
        _array[p.key] = e;
    }

    Position root() const {
        return Position(_array[1]);
    }

    static bool isRoot(const Position& p) {
        return p.key ==1;
    }

    static bool isLeft(const Position& p) {
        return p.key % 2 == 0;
    }

    Position parent(const Position& p) const {
        return Position(_array[p.key / 2]);

    }

    Position leftChild(const Position& p) const {
        return Position(_array[p.key * 2]);
    }

    Position rightChild(const Position& p) const {
        return Position(_array[p.key * 2 + 1]);
    }

    Position sibling(const Position& p) const {
        if (isLeft(p)) {
            return Position(_array[p.key + 1]);
        }
        return Position(_array[p.key - 1]);
    }

    bool isExternal(const Position& p) const {
        return p.key * 2 <= size();
    }
    bool isInternal(const Position& p) const {
        return !isExternal(p);
    }

    Position insert(const T& e) {
        _array.push_back(e);
        return
        (size());
    }

};



int main() {

    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.print();


}