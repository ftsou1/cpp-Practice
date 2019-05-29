//write two funcs. One that takes a properly formatted string into a signed integer,
//One that converts an int to a string.

//There are libraries that do this like atoi and itoa.

#include<iostream>
using namespace std;

int ToInt(string str){
    int res=0;
    int mult = 1;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i] == '-'){//delim the end of the string. Can't have double negative.
            res *= -1;
            return res;
        }
        else
            res +=((int)str[i] - 48) * mult;
        mult *= 10;
    }
    return res;

}
string ToString(int n){
    string dec;
    string res;
    if(n < 0){
        res += "-";
        n *= -1;
    }
    while(n/10){
        dec= char(n%10 + 48) + dec;
        n/=10;
    }
    dec = char(n + 48) + dec;
    res += dec;
    return res; 
}

int main(){

    string str = "1582", negstr = "-39194";
    int num = 1582,negnum = -39194;
    auto strNum = ToInt(str);
    auto numStr = ToString(num);
    if(strNum != num)
        printf("Error ToInt, expecting %d, got %d\n",num,strNum);
    if(numStr != str)
        printf("Error ToString, expecting %s, got %s\n",str,numStr);
    auto negNumStr = ToString(negnum);
    auto negStrNum = ToInt(negstr);
    if(negStrNum != negnum)
        printf("Error ToInt, expecting %d, got %d\n",negnum,negStrNum);
    if(negNumStr != negstr)
        printf("Error ToString, expecting %s, got %s\n",negstr,negNumStr);

        cout << "If you've got this far without errors, Congrats! We've implemented to_int and to_string!\n\n\n";



        cout << "\"The only limit to our realization of tomorrow will be our doubts of today.\"\n-Franklin D. Roosevelt";
        string what;
        cin >> what;
    

}