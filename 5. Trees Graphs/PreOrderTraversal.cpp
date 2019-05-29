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

vector<int> PreOrderIterative(node*root){
    vector<node*> stack;//acts as a stack. when traversing node, add to stack. after visiting right, pop off and go down the line.
    vector<int> res;
    if(root == NULL)
        return res;
    stack.push_back(root);
    auto it = root;
    //stack pops when done with all parts of the node. So root will be the last to go.
    while(!stack.empty()){
        it = stack.back();
            stack.pop_back();//so it won't print the value multiple times.
        res.push_back(it -> val);
        if (it -> right != NULL){   //pushback right bc in stack, we do FILO.
            stack.push_back(it -> right);
            it -> right = NULL;
        }
        if (it -> left != NULL){
            stack.push_back(it -> left);
            it -> left = NULL;
        }
        
    }
    return res;

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
    

    if(arr != vector<int>{1,2,4,5,3,6,7}){
        cout << "Error, wrong results - recursive. Expecting: 1 2 4 5 3 6 7"<<endl;
        cout << "Got: ";
        for(int i=0;i<arr.size();i++){
            cout << arr[i]<< " ";
        }
    }else{
        cout << "Got correct answer - recursive!"<<endl;
        cout << "Got: ";
        for(int i=0;i<arr.size();i++){
            cout << arr[i]<< " ";
        }
        cout <<endl;
    }

    auto arr2 = PreOrderIterative(one);
    if(arr2 != vector<int>{1,2,4,5,3,6,7}){
        cout << "Error, wrong results - iterative. Expecting: 1 2 4 5 3 6 7"<<endl;
        cout << "Got: ";
        for(int i=0;i<arr2.size();i++){
            cout << arr2[i]<< " ";
        }
    }else{
        cout << "Got correct answer - iterative!"<<endl;
        cout << "Got: ";
        for(int i=0;i<arr2.size();i++){
            cout << arr2[i]<< " ";
        }
        cout << "\n\n\n";
    }
    
    cout << "\"The true wealth of a nation lies not in it's gold or silver \nbut in it's learning, wisdom and in the uprightness of its sons.\"\n-Kahlil Gibran";
delete one, two, three, four, five, six, seven;
    string what;
cin  >>what;
}
