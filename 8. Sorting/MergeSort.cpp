//Merge sort implementation. O(nlogn) time, O(n) space
//Merge sort divides the array into half and calls merge sort on both halves.
//then will join the two halves together and return.


#include <iostream>
#include <cstdlib>
#include <vector> //easier for various funcs.
using namespace std;
void debug(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i]<< " ";
    }
}

vector<int> mergeSort(vector<int> arr){
    if(arr.size() < 2)
        return arr;
    int mid = arr.size()/2;
    vector<int> left(arr.begin(),arr.begin()+mid);
    vector<int> right(arr.begin()+mid,arr.end());


    left = mergeSort(left);
    right = mergeSort(right);
    vector<int> res;
    int ltrack = 0, rtrack = 0;
    while(ltrack != left.size() || rtrack!= right.size()){
        if(ltrack == left.size()){
            res.push_back(right[rtrack]);
            rtrack++;
        }else if(rtrack ==right.size()){
            res.push_back(left[ltrack]);
            ltrack++;
        }else if(left[ltrack]>right[rtrack]){
            res.push_back(right[rtrack]);
            rtrack++;
        }else{
            res.push_back(left[ltrack]);
            ltrack++;
        }
    }
    return res;
    
}
int main(){
    vector<int> arr(30);
    cout << "Before: ";
    for(int i=0;i<30;i++){
        arr[i] = rand()% 32767;
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    
    auto newArr = mergeSort(arr);
    cout << "After: ";
    debug(newArr);

    cout << "\nCongrats! We've implemented merge sort!\n\n\n";
    cout << "\"Never give up on a dream just because of the time it will take to accomplish it. The time will pass anyway.\" \n- Earl Nightingale ";
    char what;
    cin >> what;

}