//write a function that reverses the order of the words in a string.
//Treat space as delim, punctuations are the same as letters.

//The std library can split at " ", and then print the resulting array backwards.
//But for practice, I won't use the function.

#include<iostream>
#include <regex>
using namespace std;
string reverseString(string str){//O(n)
    string res;
    auto pos = str.find_last_of(" ");//position of last space
    size_t last= str.size();    //position of last letter to find word length

    while(pos != string::npos){
        res += str.substr(pos,last - pos);
        last = pos;
        pos = str.find_last_of(" ",pos-1);
    }
    res += " "+str.substr(0,last);  //adds first word last.
    res = res.substr(1);//gets rid of the space in the beginning.
    return res;


}

int main(){
    string str= "Do or do not, there is no try.";
    string ans = "try. no is there not, do or Do";
    regex split("[^ ]+");
    smatch word;
    auto newstr = reverseString(str);
    if (newstr!= ans){
        cerr<< "Error, expecting different newstr\n";
        cerr<< "Got: "<<newstr<<endl;
    }
    string newStrReg;
    while(regex_search(str,word,split)){
        newStrReg = word.str() + " " + newStrReg;
        str = word.suffix();
    }
    newStrReg = newStrReg.substr(0,newStrReg.size()-1);//gets rid of the " " at the end
    if(newStrReg != ans){
        cerr<< "Error, expecting different newStrReg\n";
        cerr << "Got: "<<newStrReg<<endl;
    }

cout << "If you've made it here without errors, then Congrats! We've finished the reverse words challenge!\n\n\n";

cout << "\"Knowing is not enough; we must apply. \nWishing is not enough; we must do.\"\n- Johann Wolfgang Von Goethe";
string what;
cin >> what;
}