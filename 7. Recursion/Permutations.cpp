//implement a routine that prints all possible orderings of the characters in a string.
//each character will be distinct even if it is repeated.

//Thoughts: take one letter, recursive call on the rest of the string. append on the result string.
//if the string is empty, cout results.

#include <iostream>
using namespace std;

void permutate(string s, string result){
    if(s.length() == 0){
        cout<< result<< endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        auto sub = s.substr(0,i) + s.substr(i+1);
        string newStr = result + s[i];
        
        permutate(sub, newStr);
    }
}

int main(){
    string Hello = "Hello";
    string hat = "hat";
    string aaa = "aaa";

    cout << "Permutating Hello: \n";
    permutate(Hello, "");
    cout << "Permutating hat: \n";
    permutate(hat, "");
    cout << "Permutating aaa:\n";
    permutate(aaa,"");


    cout << "If you've made it this far and the amount of strings printed is strings.length()!, then congrats! \nWe've successfully permutated strings recursively.\n\n\n";
    cout << "\"You are never too old to set another goal or to dream a new dream.\"\n-C.S. Lewis";

    string what;
    cin >> what;
}
