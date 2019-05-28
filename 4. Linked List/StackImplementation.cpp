//Implement a stack data structure using a LL or a dynamic arr.
//Stack is already in std, but for practice...
//Using int value for now.
#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* prev;
    Node(int value): value(value){}
    ~Node();
};

class Stack{
    Node* top;
    public:
    Stack(){};
    void push(int val){
        auto node = new Node(val);
        node -> prev = top;
        top = node;
    }
    int pop(){
        if (top != NULL){
        int val = top -> value;
        top = top -> prev;
        return val;
        }
        else
        {
            cerr << "Stack is empty\n";
        }
        
    }
    ~Stack(){}
};

/* Stack looks like:
31
15
7
3
5
*/
int main(){
    Stack * s = new Stack();
    s->push(5);
    s->push(3);
    s->push(7);
    s->push(15);
    s->push(31);
    cout << "Push success\n";

    if(s->pop() != 31)
        cerr<< "Error, expected 31.\n";
    if(s->pop() != 15)
        cerr<< "Error, expected 15.\n";
    if(s->pop() != 7)
        cerr<< "Error, expected 7.\n";
    if(s->pop() != 3)
        cerr<< "Error, expected 3.\n";
    if(s->pop() != 5)
        cerr<< "Error, expected 5.\n";
    cout << "Pop success\n";
    cout << "If you reached here with no errors, congrats!";
    string str;
    cin >> str;
}
