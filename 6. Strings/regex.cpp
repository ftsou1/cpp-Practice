//Regex practice
#include <iostream>
#include <regex>

using namespace std;

int main(){
    string regString = "[A-Z]+";
    regex reg(regString);
    smatch match;
    string sample = "THIS IS A TEST TYPE STRING. the LetTeRS SHouLd bE UPPERCASE";
    while(regex_search(sample,match,reg)){
        cout << "Match: "<<match.str()<<endl;
        sample = match.suffix().str();
    }
    cin.get();
    return 0;
}