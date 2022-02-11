// Codility: lesson 4
// Found on Rakuten coding interview - round 1
// https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/

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

#define MAX_NUMBER 1000002

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int integers[MAX_NUMBER];
    memset(integers,false, MAX_NUMBER);
    integers[0]= true;

    int N = A.size();
    int maxIntegerInArray = 0;
    int smallestPositiveInteger = MAX_NUMBER;

    for(int i=0;i<N;i++){
        if(A[i]>0) integers[A[i]]=true;
        maxIntegerInArray = max(maxIntegerInArray, A[i]);
    }
    for(int i=1;i<maxIntegerInArray+2;i++){
        if(!integers[i] && integers[i-1]){
            smallestPositiveInteger = min(smallestPositiveInteger, i);
        }
    }
    return smallestPositiveInteger!=MAX_NUMBER? smallestPositiveInteger: 1;

}
