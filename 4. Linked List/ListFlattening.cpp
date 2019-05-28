//Given a double linked list with child pointers, flatten the list to a single linked list.
//  5 - 33 - 17         -      2 - 1
//  |_6 - 25 -  6              |_2 - 7
//        |_8   |_9             |_12 - 5
//                |_7           |_21 - 3

//should look like: 5-6-25-8-6-9-7-33-17-2-2-12-21-3-5-7-1 at the end


#include <iostream>
using namespace std;

class Node{
    public:
    Node(int val): val(val),next(NULL),prev(NULL),child(NULL){}
    Node *next,*prev,*child;
    int val;
};

Node* flatten(Node *n){
    //if node = NULL return;
    //if node has child, 
        //flatten child
        //child -> end -> next = node -> next
        //node -> next = child
    //flatten node -> next

    if(n == NULL)
        return NULL;
    if(n -> child != NULL){
        auto child = flatten(n -> child);
        auto next = n -> next;
        auto childEnd = child;
        while(childEnd-> next != NULL)
            childEnd = childEnd -> next;
        n -> next = child;
        child -> prev = n;
        childEnd -> next = next;
        if(next != NULL)
            next -> prev = childEnd;
        n -> child = NULL;
    }
        n -> next = flatten(n -> next);
    return n;
}
void print(Node* n){
    cout << "Printing: \n";
    for(auto it = n; it != NULL; it = it -> next){
        cout << it -> val<<" ";
    }
    cout << endl;
}

int main(){
    auto five1 = new Node(5);
    auto six1 = new Node(6);
    auto twentyfive = new Node(25);
    auto eight = new Node(8);
    auto six2 = new Node(6);
    auto nine = new Node(9);
    auto seven1 = new Node(7);
    auto thirtythree = new Node(33);
    auto seventeen = new Node(17);
    auto two1 = new Node(2);
    auto two2 = new Node(2);
    auto seven2 = new Node(7);
    auto twelve = new Node(12);
    auto five2 = new Node(5);
    auto twentyone = new Node(21);
    auto three = new Node(3);
    auto one = new Node(1);

    five1 -> next = thirtythree;
    thirtythree -> prev = five1;
    thirtythree -> next = seventeen;
    seventeen -> prev = thirtythree;
    seventeen -> next = two1;
    two1 -> prev = seventeen;
    two1 -> next = one;
    one -> prev = two1;
    five1 -> child = six1;
    two1 -> child = two2;
    six1 -> next = twentyfive;
    twentyfive -> prev = six1;
    twentyfive -> next = six2;
    six2 -> prev = twentyfive;
    two2 -> next = seven2;//right 7
    seven2 -> prev = two2;
    twentyfive -> child = eight;
    six2 -> child = nine;
    two2 -> child = twelve;
    twelve -> next = five2;
    five2 -> prev = twelve;
    nine -> child = seven1;//left 7
    twelve -> child = twentyone;
    twentyone -> next = three;
    three -> prev = twentyone;
    cout << "Setup Finished\n";
    flatten(five1);
    cout << "Flatten Finished\n";
    print(five1);


    cout << "\n\n\n\"When we have respect for ourselves and others, \nwe gravitate towards connections that encourage that.\" \n-Simeon Lindstrom";
    string what;
    cin >> what;


}
