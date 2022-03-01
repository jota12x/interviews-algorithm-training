//Based on CP4, exercise 2.2.1.3, problem 5.

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <iomanip>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int=0;i<(n);++i);
using namespace std;
using ll = long long;
using P = pair<int,int>;
//#include <bits/stdc++.h>

//O(n) solution

int computeMedian(int S[]){
    int median;
    // sort is somehow needed.
    // I can only think of a O(nlogn) solution
    return median;
}
int main(){
    int N;
    cin>>N;
    int S[N];
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    cout<<"median is: "<<computeMedian(S)<<endl;
}
