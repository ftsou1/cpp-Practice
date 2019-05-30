//implement telephone iteratively or non-recursively.
//assume the given string is formatted correctly.

//First thoughts: Have a loop for every digit.
//having 7 loops is probably too long to implement and an inefficient solution.
//Second thoughts: have an array of 8 ints. Set all to -2.
//Run through the string to determine any numbers between 2 and 9 and mark them with a 0 on tracker.
//Keep another array of string that determines the letters which come next based on the index in the array above.
//Tracker: [-1][0][0][0][0][0][0][0]
//Strings: ["ABC"]["DEF"]["GHI"]["JKL"]["MNO"]["PRS"]["TUV"]["WXY"];
//If Tracker[i] < 0, append string as normal and tracker[i]--;
//If tracker[i] == 0-2, append strings[(int)str[i]-50][tracker[i]], increment tracker[i]. if tracker == 3, set tracker back to 0.
//while(tracker[0] == -1);

#include <iostream>
using namespace std;

void telephone(string str){
    string dict[8] = {"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
    int tracker[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    for(int i=0;i<7;i++){
        int letter = (int)str[i]-48;
        if(letter>1)
            tracker[i+1] = 0;
    }
    while(tracker[0] == -1){
        string res = "";
        for(int i=6;i>=0;i--){
            if(tracker[i+1]>-1){
                res = dict[(int)str[i]-50][tracker[i+1]] + res;
            }else if (tracker[i+1]<0){
                res  = str[i] + res;
            }
        }
        cout << res << endl;
        int j=7;
        while((tracker[j]>=2||tracker[j]<0)&& j > 0){
            if(tracker[j] >= 2)
                tracker[j]=0;
            j--;
        }
        tracker[j]++;
    }
    cout << "\n\n";
}


int main(){
    
    auto num1 = "4769381";
    auto num2 = "8748536";
    auto num3 = "1321287";

    auto nums = {num1,num2,num3};

    for( auto it = nums.begin();it != nums.end();it ++ ){
        cout << "Telephone "<<*it<<"!\n";
        telephone(*it);

    }

    cout << "Congrats! We've implemented telephone using iteration instead of recursion.\n"
    <<"The worst case is if we have to change all 7 numbers, so the runtime of this is 3^7\n\n";

    cout << "\"You can't use up creativity. The more you use, the more you have.\"\n-Maya Angelou";

    string what;
    cin >> what;
}
