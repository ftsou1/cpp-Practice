//write an efficient function to find the first nonrepeated character in a string.

//First thoughts -> Hash table scan and insert string.
//Then go through the string and see which character count == 1.
//will take O(n) time and O(128) space.

#include<iostream>
using namespace std;

char nonRepeat(string str){
    int arr[128] = {0};
    for(int i=0;i<str.length();i++){
        arr[(int)str[i]]++;
    }
    for(int i=0;i<str.length();i++){
        if(arr[(int)str[i]]==1)
            return str[i];
    }
}

int main(){
    string str;
while(cin >> str){
    cout << nonRepeat(str)<< "\n\n";
}
}