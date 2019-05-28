//Given a single linked, find the mth away from the end of the list.
//time and space efficient por favor.

#include <iostream>
using namespace std;

class node {
    public:
    node(int val): val(val),next(NULL){}
    int val;
    node* next;
};
void findMthaway(node * head, int m){
    auto tmp = head;
    while(m--){//offset head by m away from tmp
        head = head -> next;
        if(head == NULL){
            cerr << "Error, LL too small.\nCannot find the Mth away from end.\n";
            return;
        }
    }
    head = head -> next;
    while(head != NULL){
        head = head -> next;
        tmp = tmp -> next;
    }
    cout << tmp -> val;
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

    findMthaway(one, m);

    string what;
    cin >> what;

}