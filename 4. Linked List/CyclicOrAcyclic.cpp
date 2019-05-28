//Given the head of a SLL, work out if the list is cyclic or acyclic
//If LL.size() == 0, return true
//a cyclic list can be as small as 1 node pointing to itself.

//My first thought is if we store the address of the ptr of each node to an array
//we can determine if we cross over one of them.
//The issue is that if we store the address in an array
//this is an O(n^2) time and O(n) space complexity.

//There's no need to create a new list since we're making a duplicate of the original list
//For each node we visit, we can compare the next node to all the previous nodes we've visited.
//So for the third node, we'll compare the third -> next to nodes from head to current.
//This method is O(n^2), but can't think of another method...

#include <iostream>
using namespace std;
class node {
    public:
    node(int val): val(val),next(NULL){}
    int val;
    node* next;
};
bool isCyclic(node* n){
    if(n == NULL)
        return false;
    auto back = n;
    for(auto it = n; it != NULL; it = it -> next){
        for(back = n; back != it; back = back -> next){
            if(it -> next == back)
                return true;
        }
        if(back == it-> next)//back == it
            return true;
    }
    return false;

}
int main(){
    int m = 6;
    node* one = new node(1);
    node* two = new node(2);
    node* three = new node(3);
    node* four = new node(4);
    node* five = new node(5);
    node* six = new node(6);
    node* seven = new node(7);
// 1 - 2 - 3 - 4 - 5 - 6 - 7//
    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = seven;

    if(isCyclic(NULL))
        cerr<< "Error, expecting NULL parameter to return false\n";
    if(isCyclic(one))
        cerr<< "Error, should not be cyclic\n";
    
    seven -> next = one;
    if(!isCyclic(one))
        cerr<< "Error, should be cyclic\n";
    
    one -> next = one;
    if(!isCyclic(one))
        cerr<< "Error, one pointing to itself should be cyclic\n";
    
    cout << "If no errors, then congrats! We have finished the cyclic practice\n\n"
        <<"\"I have always believed that each man makes his own happiness and is responsible for his own problems. \nIt is a simple philosophy.\" \n-Ray Kroc\n";
    string what;
    cin >> what;

}