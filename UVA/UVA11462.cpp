#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
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

void print(vector<int> arr, int N){
	for(int i=0;i<N;i++){
		cout<<(i!=0?" ":"")<<arr[i];
	}
	cout<<endl;
}
int main(){
	int N;
	while(cin>>N){
		if(N == 0) break;
		int arr[N+2];
		int freq[102];
		memset(freq, 0, sizeof(freq));
		for(int i=0;i<N;i++){
			cin>>arr[i];
			freq[arr[i]]++;
		}
		vector<int> sorted_arr;
		for(int i=1;i<=100;i++){
			for(int j=0;j<freq[i];j++){
				sorted_arr.push_back(i);
			}
		}
		print(sorted_arr,sorted_arr.size());
	};
}
