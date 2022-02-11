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

//Based on Exercise 2.2.1.1 on CP4, page 58


// NOTE: We only need the comparator for non-ascending order~
int pairsCmp (P a, P b){
    return a.first>=b.first;
}

int fractionsCmp(P a, P b){
    return (float(a.first)/float(a.second))<=(float(b.first)/float(b.second));
}

void print(vector<P> pairs_arr){
    for(int index=0;index<pairs_arr.size();index++){
        cout<<pairs_arr[index].first<< "-" << pairs_arr[index].second<<endl;
    }

}
int main(){
    vector<P> pairs_arr;

    pairs_arr.push_back(make_pair(4,3));
    pairs_arr.push_back(make_pair(2,3));
    pairs_arr.push_back(make_pair(2,1));
    pairs_arr.push_back(make_pair(1,5));

    sort(pairs_arr.begin(),pairs_arr.end(), pairsCmp);
    print(pairs_arr);


    vector<P> fractions;
    fractions.push_back(make_pair(4,3));
    fractions.push_back(make_pair(2,3));
    fractions.push_back(make_pair(2,1));
    fractions.push_back(make_pair(1,5));
    fractions.push_back(make_pair(1,2));

    sort(fractions.begin(),fractions.end(), fractionsCmp);
    cout<<"fractions sorted in ascending order"<<endl;
    print(fractions);



}
