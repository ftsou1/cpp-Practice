//given a tree that is unbalanced, balance it. with the amount of nodes.

//first thoughts -> we need to count the height of the left and right side of the tree.
//if the difference in height of both sides are greater than one, we can rotate accordingly.

#include<iostream>
#include<vector>
using namespace std;
/*         20
        8       22
     4    12
        10  14

*/

class node {
    public:
    node(int val): val(val),left(NULL),right(NULL){}
    int val;
    node* left, *right;
};
int getHeight(node* n){
    if(n == NULL)
        return 0;
    return 1+ max(getHeight(n -> left), getHeight(n -> right));
}
void inOrder(node* root, vector<node*>&s){

    if(root != NULL)//want to store the null ptrs too
        inOrder(root -> left,s);
    s.push_back(root);
    if(root !=NULL)
        inOrder(root -> right,s);
}
node* Balance(node* n){
    if(n == NULL)
        return NULL;
    int diff = getHeight(n -> left) - getHeight(n -> right);
    if (diff > 1){// left > right
        auto newHead = n -> left;
        auto tmp = newHead;
        while(tmp -> right !=NULL)
            tmp = tmp -> right;
        tmp -> right = n;
        n -> left = NULL;
        return Balance(newHead);
    } else if(diff < -1){ //right > left
        auto newHead = n -> right;
        auto tmp = newHead;
        while(tmp -> left != NULL)
            tmp = tmp -> left;
        tmp -> left = n;
        n -> right = NULL;
        return Balance(newHead);
    }
    n -> left = Balance(n -> left);
    n -> right = Balance(n-> right);
    return n;
}
int main(){
    node * twenty = new node(20);
    node * eight = new node(8);
    node * twentytwo = new node(22);
    node * four = new node(4);
    node * twelve = new node(12);
    node * ten = new node(10);
    node * fourteen = new node(14);

    twenty -> left = eight;
    twenty -> right = twentytwo;
    eight -> left = four;
    eight -> right = twelve;
    twelve -> left = ten;
    twelve -> right = fourteen;
    cout << "Finished setup\n";
/*         20
        8       22
     4    12
        10  14
*/
    auto newHead = Balance(twenty);
    cout << "Finished balance\n";
    // Should look like:
/*
             12
        8        20
    4     10   14   22
*/    
    vector<node*> s;
    inOrder(newHead,s);
    if(s != vector<node*>{NULL,four,NULL,eight,NULL,ten,NULL,twelve,NULL,fourteen,NULL,twenty,NULL,twentytwo,NULL})
        cerr<< "Error, expecting different values for tree.\n";
    cout<< "If you've made it this far without errors, then congrats! We've successfully balanced the BST!\n\n\n";

    cout << "\"The way get started is to quit talking and begin doing.\"\n- Walt Disney";

string what;
cin >> what;
}