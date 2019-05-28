//Maintain LL pointers. Implement a delete and insertAfter function
//pt2: implement removeHead;
#include <iostream>
using namespace std;

class node {
    public:
    node(int val): val(val),next(NULL){}
    int val;
    node* next;
};

class LL{
    public:
    node* head, *tail;
    LL():head(NULL),tail(NULL){}
    bool remove(node* node){
        if(head == NULL)
            return false;
        if(node == NULL)
            return true;
        for(auto it = head;it != NULL; it = it -> next){
            if( it -> next == node){
                it -> next = it -> next -> next;
                free(node);
                return true;
            }
        }
        return false;
    }
    bool insertAfter(node *after, int val){
        auto newNode = new node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return true;
        }
        if(after == NULL){
            newNode -> next = head;
            head = newNode;
            return true;
        }
        for(auto it = head; it != NULL; it = it -> next){
            if( it == after ){
                newNode -> next = after -> next;
                after -> next = newNode;
                if(it == tail){
                    tail = newNode;
                }
                return true;
            }
        }
        return false;
    }
    bool removeHead(){
        if (head == NULL)
            return false;
        auto tmp = head -> next;
        free(head);
        head = tmp;
    }
};

// 1-2-3-4-5-6;
//will delete 4, print;
//will insert 4, print;

void print(LL*ll){
    cout << "Printing: ";
    for(auto it = ll->head; it != NULL; it = it -> next){
        cout << it -> val<< " ";
    }
    cout << endl;
}
int main(){
    cout << "Begin\n";
    auto l = new LL();
    if(!l-> insertAfter(NULL,1))
        cout << l -> tail -> val <<endl;
    if(!l -> insertAfter(l->tail, 2))
        cout << l -> tail -> val <<endl;
    if(!l -> insertAfter(l->tail, 3))
        cout << l -> tail -> val <<endl;
    if(!l -> insertAfter(l->tail, 4))
        cout << l -> tail -> val <<endl;
    if(!l -> insertAfter(l->tail, 5))
        cout << l -> tail -> val <<endl;
    if(!l -> insertAfter(l->tail, 6))
        cout << l -> tail -> val <<endl;


    print(l);

    auto tmp = l -> head;
    while( tmp -> val != 4)
        tmp = tmp -> next;
    
    cout << "Removing 4\n";
    if(!l -> remove(tmp))
        cout << "Error removing 4\n";
    

    print(l);

    tmp = l-> head;
    while(tmp -> val != 3)
        tmp = tmp -> next;

    cout << "Inserting 4\n";

    if(!l -> insertAfter(tmp, 4))
        cout << "Error inserting 4\n";
    print(l);

    cout << "Removing head\n";
    l -> removeHead();
    print(l);


    cout << "\n\n\n\"Anger is the ultimate destroyer of your own peace of mind.\"\n -Dalai Lama";

string what;
cin >> what;

}
