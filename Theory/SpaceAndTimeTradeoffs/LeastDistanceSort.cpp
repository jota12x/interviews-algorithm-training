
// This program is based on Exercise 8 of Section 7.1 by [LEV2012]

/*
    Premature optimization is the root of all evil
    - Donald Knuth
*/


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <iomanip>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int=0;i<(n);++i);
using namespace std;

void print(int arr[], int N){
    for(int i=0;i<N-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[N-1]<<endl;
}

void sortStatues(int statues[], int N){
    int counts[N+1];
    int sorted_statues[N];

    memset(counts,0, sizeof(counts));

    //O(n^2) in comparisons
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(statues[i]<statues[j]) counts[j]++;
            else counts[i]++;
        }
    }

    //O(n) in movements!!
    for(int i=0;i<N;i++){
        sorted_statues[counts[i]] = statues[i];
    }

    print(sorted_statues, N);
}


int main(){
    int N;
    cin>>N;

    int statues[N+1];
    int i=0;

    while(i<N){
        cin>>statues[i];
        i++;
    }
    sortStatues(statues, N);
}
