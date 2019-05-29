//Given an unordered binary tree, use an array sorting routine to transform the tree into a heap
//that uses a balanced binary tree as its underlying data structure.

//First thoughts -> I don't understand the problem.
//I understand the question. Given an array of integers unsorted, create a heap using a binary tree as an underlying data structure.
//Much simpler than what I was trying to do...


#include <iostream>
#include <vector>
using namespace std;
class node {
    public:
    node(int val): val(val),left(NULL),right(NULL){}
    int val;
    node* left, *right;
};

/*         20
        8       22
     4    12
        10  14

*/
void BTToHeap(node* root, vector<node*> &s){
    if(root == NULL)
        return;
    BTToHeap(root -> right, s);
    s.push_back(root);
    BTToHeap(root -> left, s);
}
void inOrder(node* root, vector<int>&s){
    if(root == NULL)
        return;
    inOrder(root -> left,s);
    s.push_back(root -> val);
    inOrder(root -> right,s);
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

    vector<node*> arr;
    BTToHeap(twenty, arr);
    //Arr should look like: 22, 20, 14, 12, 10, 8, 4.
    
    //to convert to a heap, we need to take elem and place each in the next available spot.
    //this is index 0 is head, 1 and 2 are connected to 0,
    // 3,4 is connected to 1. 5,6 is connected to 2 
    //(index *2)+1 is left, (index *2) + 2 is right,
    //But let's set everything to NULL first.
    auto head = arr[0];
    for(int i = 0; i<arr.size();i++){   //O(n);
        if(i*2 + 1 < arr.size())
            arr[i] -> left = arr[i*2+1];
        else arr[i] -> left = NULL;

        if(i*2+2 < arr.size())
            arr[i] -> right = arr[i*2+2];
        else arr[i] -> right = NULL;
    }
    //heap should look like:
    /*     22
        20      14
     12    10  8   4

    */
    //Let's do inOrder traversal to see if the numbers are as expected

    vector<int> arr2;
    inOrder(head,arr2);
    if(arr2 != vector<int>{12, 20, 10, 22, 8, 14, 4})
        cerr<< "Unexpected values received in arr2.\n";

    cout << "If you've reached here with no errors, congrats! We've successfully implemented BTToHeap\n\n\n";

    cout << "\"Make a conscious effort to let go of fear and act from a sense of consciousness that will empower and protect you. \nYou are strong. \nYou are greater than the fear!\"\n-Les Brown";
    
    string what;
    cin >> what;
}