//Gets height of tree based off of root. Root = height 1
#include<iostream>
using namespace std;
class node {
    public:
    node(int val): val(val),left(NULL),right(NULL){}
    int val;
    node* left, *right;
};
/*
           1
    2           3
4       5   6       7
*/
int getHeight(node * n){
    if(n == NULL)
        return 0;
    return 1 + max(getHeight(n -> left), getHeight(n -> right));
}

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

    if(getHeight(NULL)!=0)
        cerr<<"Error, expecting 0.\n";
    if(getHeight(one)!= 3)
        cerr<< "Error, expecting 3.\n";
    
    three -> left = NULL;
    seven -> left = six;
/*        1
    2           3
4       5          7
                6*/
    if(getHeight(one)!= 4)
        cerr<< "Error, expecting 4.\n";
    one -> left = NULL; one -> right = NULL;
    
    if(getHeight(one) != 1)
        cerr<< "Error, expecting 1.\n";


    cout << "If no errors, congrats! We've successfully completed the getHeight problem.\n\n\n\n";
    
    cout << "\"Appreciate those early influences and what they've done for you.\"\n -Willie Davis";
    string what;
    cin >> what;
}