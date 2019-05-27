//Practice implementing quicksort
#include <iostream>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <vector>

using namespace std;

void quickSort(vector<int>&);
int main(){
    srand(time(NULL));
    vector<int> arr(32);
    cout<< "Before: \n";
    for(int i= 0;i<32;i++){
        arr[i] = rand()% SHRT_MAX;
        cout << arr[i]<<endl;
    }

    quickSort(arr);
    cout << "\n\n\nAfter: \n";
    for(int i=0;i<arr.size();i++){
        cout<< arr[i]<<endl;
    }
    cin >> arr[0];
}
void copyToarr(vector<int>&left, int pivot,vector<int>&right,vector<int>&arr){
    int i=0;
    for(;i<left.size();i++)
        arr[i] = left[i];
    arr[i++] = pivot;
    for(int j = i;i-j<right.size();i++){
        arr[i] = right[i-j];
    }

}
void quickSort(vector<int>&arr){//O(logN)
    if(arr.size()<2)
        return;
    int mid = arr.size()/2;
    int pivot = arr[mid];
    int lCount = 0;
    vector<int> left;
    vector<int> right;
    //go through the list and push to left,right vecs.
    for(int i=0;i<arr.size();i++){
        if( i == mid)
            continue;
        if(arr[i] < pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    //call on left and right
    quickSort(left);
    quickSort(right);
    copyToarr(left,pivot,right,arr);

}
