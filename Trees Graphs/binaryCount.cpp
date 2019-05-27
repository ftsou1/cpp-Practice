/* Create a program that, given a BST, count the amount of nodes between x and y inclusive. X and y are using streams */
#include <iostream>
#include <vector>

using namespace std;
void debug(vector<float> arr){
    cout << "Debug:\n";
    for(int i=0;i<arr.size();i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
}
class node{
    public:
    float val;
    node* left;
    node* right;
    node(float val):val(val),left(NULL),right(NULL){}
    ~node();
};
/*
           4
    2           6
1       3   5       7
*/
void getArr(node* root, vector<float>&arr){
    if(root == NULL)
        return;
    getArr(root-> left, arr);
    arr.push_back(root->val);
    getArr(root->right, arr);

}
int bs(vector<float> &arr, int x,int l, int r){ //binary search O(logN)
    int mid = (l+r)/2;
        if(arr[mid]>=x && arr[mid-1]<x)
            return mid;
        if(arr[mid]<x)
            return bs(arr, x, mid, r);
        if(arr[mid]>=x)
            return bs(arr, x, l, mid);
}
void binaryCountRepeat(node* root){ //Total Runtime: O(n + m * logn)
    int x,y;
    while(cin>>x>>y){
        vector<float> arr;
        getArr(root,arr);   //O(N) to copy values to an array.
        if(x > y || x > arr[arr.size()-1] || y < arr[0])
            cout << "Count: 0\n\n";
       else{
        int indX,indY;
        if(x <= arr[0])
            indX = 0;
        else
            indX = bs(arr,x,0,arr.size()-1);
        if(y >= arr[arr.size()-1])
            indY = arr.size();
        else
            indY = bs(arr,y,0,arr.size()-1);    //O(logN), 
        
        if(arr[indY] != y)
            indY--;
        cout <<"Count: "<<indY - indX +1<<"\n\n";
        }
    }
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

    binaryCountRepeat(four);
}