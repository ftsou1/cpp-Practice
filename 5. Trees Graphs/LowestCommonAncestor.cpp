//Given an BST, find the lowest common ancestor.
//Assume the given nodes are in the tree

//First thought = compare the value of the current node to the value of the two given nodes.
//if both are < curr-> val; recurse on curr -> left
//if both are > curr-> val; recurse on curr -> right
//if one is <= and one is >= then return the current node.
#include <iostream>
using namespace std;

class node {
    public:
    node(int val): val(val),left(NULL),right(NULL){}
    int val;
    node* left, *right;
};

/*
           4
    2           6
1       3   5       7
*/
node* LCA(node* root, node* x, node*y){
    if(root == NULL)
        return NULL;
    if(root -> val > x -> val && root -> val > y -> val)
        return LCA(root -> left, x, y);
    if(root -> val < x -> val && root -> val < y -> val)
        return LCA(root -> right, x, y);
    else return root;
}


int main(){
    node* one = new node(1);
    node* two = new node(2);
    node* three = new node(3);
    node* four = new node(4);
    node* five = new node(5);
    node* six = new node(6);
    node* seven = new node(7);

    four -> left = two;
    four -> right = six;
    two -> left = one;
    two -> right = three;
    six -> left = five;
    six -> right = seven;

    if(LCA(four, two, six)!= four)
        cerr<< "Error, expecting 4\n";
    if(LCA(four, one, three)!= two)
        cerr<< "Error, expecting 2\n";
    if(LCA(four, two, two)!= two)
        cerr<< "Error, expecting 2 in same ptr parameters\n";
    if(LCA(four, five, six)!= six)
        cerr<< "Error, expecting 6\n";

cout << "If there are no errors, then congrats, we've implemented LCA!\n\n\n";

cout << "\"I can give you a six-word formula for success: \nThink things through, then follow through.\" \n-Captain Edward V. Rickenbacker ";


string what;
cin >> what;
}