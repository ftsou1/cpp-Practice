//write function that removes all letters in string m from string n

//first thoughts -> using a map or a hash to determine if letters in m. 
// Using the char as a key, get true or false. o(n + m);
//Brute force: for every letter in n, check against every letter in m o(mn)
#include <iostream>
#include <regex>

using namespace std;
string removeChars(string str, string remove){
    string res;
    bool hash[128] = {false};
    for(int i=0;i<remove.length();i++)
        hash[(int)remove[i]] = true;
    for(int i=0;i< str.length();i++)
        if(!hash[(int)str[i]])
            res+= str[i];

return res;
}

int main(){
    string str = "Battle of the Vowels: Hawaii vs. Grozny";
    string remove = "aeiou";
    string result = "Bttl f th Vwls: Hw vs. Grzny";
    regex reg('['+remove+']');
    auto newstr = removeChars(str,remove);
    if(newstr!=result)
        cerr<< "Error, newstr and result not matched\n" << "Got: "<<newstr<<endl;
    auto s = regex_replace(str,reg,"");
    if(s != result)
        cerr<< "Error, newstr and result not matched\n"<<"Got: "<<s<<endl;

    cout << "If you've reached here without errors, congrats! We've finished the removeChar practice!\n\n\n";
    cout << "\"If you are working on something that you really care about, you don’t have to be pushed. \nThe vision pulls you.\" \n-Steve Jobs";
    string what;
    cin >> what;
    
}