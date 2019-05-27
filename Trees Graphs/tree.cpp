//create a program to return if two trees are equal or not.
#include <iostream>

using namespace std;

class node{
	public:
	node(int val): val(val),left(NULL),right(NULL){}
	int val;
	node* left;
	node* right;

    ~node();
};

bool treeCompare(node* t1, node* t2){
	if(t1 == NULL && t2 == NULL)
		return true;
	if(t1 == NULL && t2 != NULL || t1 != NULL && t2 == NULL)
		return false;

	if(t1 -> val == t2 -> val)
		return treeCompare(t1-> left, t2 -> left) && treeCompare(t1 -> right, t2 -> right);

	return false;
}
//          1
//        2    3
//      4  5  6 7

//          1
//        2    3
//      4  5  6

//      NULL, NULL;
int main(){
    node* one = new node(1);
    node* two = new node(2);
    node* three = new node(3);
    node* four = new node(4);
    node* five = new node(5);
    node* six = new node(6);
    node* seven = new node(7);

    one -> left = two;
    one -> right = three;
    two -> left = four;
    two -> right = five;
    three -> left = six;
    three -> right = seven;

	if(!treeCompare(one, one)){
		cerr<< "Error, expecting the trees to be the same.\n";
	}
	node* oneCopy = new node(1);
    node* twoCopy = new node(2);
    node* threeCopy = new node(3);
    node* fourCopy = new node(4);
    node* fiveCopy = new node(5);
    node* sixCopy = new node(6);

    oneCopy -> left = twoCopy;
    oneCopy -> right = threeCopy;
    twoCopy -> left = fourCopy;
    twoCopy -> right = fiveCopy;
    threeCopy -> left = sixCopy;
	if(treeCompare(one, oneCopy)){
		cerr<< "Error, expecting the trees to be different.\n";
	}
	if(!treeCompare(NULL,NULL)){
		cerr<< "Error, expecting NULL ptrs to return true.\n";
	}
	cout<< "If no errors, Hurray!";
	string what;
	cin >> what;
	return 0;


}