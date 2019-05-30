//insertion sort implementation O(n^2)
//builds an array and inserts the elements one at a time.

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int arr[30];
    cout << "Before: ";
    for(int i=0;i<30;i++){
        arr[i] = rand()% 32767;
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    int newArr[30];
    for(int i=0;i<30;i++){
        newArr[i] = INT32_MAX;
    }
    int size = 0;
    
    for(int i=0;i<30;i++){
        int val = arr[i];
        size++;
        int temp;
        for(int j=0;j<size;j++){
            if(newArr[j]<=val)
                continue;
            else{
                temp = newArr[j];
                newArr[j] = val;
                val = temp;
            }
        }
    }

    cout << "After: ";
    for(int i=0;i<30;i++){
        cout << newArr[i] << " ";
    }
    cout << "\nIf you've reached here, congrats! We've implemented insertion sort!\n\n\n";

    cout << "\"Start by doing what's necessary, then what's possible; and suddenly you are doing the impossible.\" \n- Saint Francis";

    char what;
    cin >> what;

}
