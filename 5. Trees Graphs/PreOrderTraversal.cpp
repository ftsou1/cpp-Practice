//  The program is to show how to order PreOrder traversal practice
//  PreOrder is root -> left -> right;
#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    node(int val): val(val),right(NULL),left(NULL){};
    node* left, *right;
    int val;
    ~node(){};

};

void PreOrderRecursive(node* root, vector<int>&arr){
    if (root == NULL)
        return;
    arr.push_back(root -> val);
    PreOrderRecursive(root -> left, arr);
    PreOrderRecursive(root -> right, arr);
}
/*
           1
    2           3
4       5   6       7
*/
int main(){//driver
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

    vector<int> arr;
    PreOrderRecursive(one, arr);
    delete one, two, three, four, five, six, seven;

    if(arr != vector<int>{1,2,4,5,3,6,7}){
        cout << "Error, wrong results. Expecting: 1 2 4 5 3 6 7"<<endl;
        cout << "Got: ";
        for(int i=0;i<arr.size();i++){
            cout << arr[i]<< " ";
        }
    }else{
        cout << "Got correct answer!"<<endl;
        cout << "Got: ";
        for(int i=0;i<arr.size();i++){
            cout << arr[i]<< " ";
        }
    }

    string what;
cin  >>what;
}
