//Write a program that prints out all permutations of phone number words given a 7 digit number
//Starting from 2 = ABC, 3 = DEF,... 9 = WXY, and skipping Q,
//Numbers will not include the actual numbers. For example, a given number 2 will not ever be the number 2.
#include<iostream>
using namespace std;

void printWord(string num, int index, string results, string arr[]){
    if(index == num.length()){
        cout << results<<endl;
        return;
    }else if( num[index] == '0' || num[index] == '1'){
        results[index] = num[index];
        printWord(num, index+1, results, arr);
    }
    else
        for(int i=0;i<3;i++){
                results[index] = arr[(int)num[index]-50][i];
            printWord(num, index+1, results, arr);
        }
}

int main(){
    string arr[8] = {"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
    string test [3]={"5111631","1010101","6861062"};

    for( int i= 0;i<3;i++){
        string placeHolder = "-------";
        cout << "Test "<< test[i] << endl;
        printWord(test[i], 0, placeHolder, arr);
        cout << "\n\n";
    }

    cin >> arr[0];
    return 0;

}