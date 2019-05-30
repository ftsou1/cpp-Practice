//implement Selection Sort  O(n^2).
//Selects smallest element of the list and swaps with the first element.
//And so on and so on.
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
    cout << endl;
    for(int i=0;i<30;i++){
        int min = i;
        for(int j=i;j<30;j++){
            if(arr[min] > arr[j])
                min = j;
        }
        swap(arr[i],arr[min]);
    }
    cout << "After: ";
    for(int i=0;i<30;i++){
        cout << arr[i] << " ";
    }
    cout << "If you've reached here, congrats! We've implemented selection sort!\n\n\n";

    cout << "\"Success is no accident. It is hard work, perseverance, learning, studying, sacrifice and most of all, love of what you are doing or learning to do.\"\n-Pele";

    char what;
    cin >> what;

}
