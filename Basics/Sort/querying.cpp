#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <iomanip>
#include <map>
#define rep(i,n) for(int=0;i<(n);++i);
using namespace std;
using ll = long long;
using P = pair<int,int>;

//Based on Exercise 2.2.1.3 on CP4, page 58

int hasDuplicatesEasy(int arr[], int size){
    map<int,int> count;
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        if(count[i]>1) return true;
    }
    return false;
}

//O(N) and O(1) but with modification of the array
int hasDuplicatesHard(int arr[], int size){
    for(int i=0;i<size;i++){
        int absoluteIndex = abs(arr[i]);
        if(arr[absoluteIndex]<0) return  true;
        arr[absoluteIndex]= -1* arr[absoluteIndex];
    }
    return false;
}
int main(){
    int arr[] = {4, 2, 9, 5, 4, 3, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<(hasDuplicatesHard(arr, size)? "it has duplicates":"it doesn't have duplicates")<<endl;;

}
