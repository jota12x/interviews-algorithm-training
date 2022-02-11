//Based on CP4 , Exercise 2.2.3, problem 5
// Found on leetcode as well https://leetcode.com/problems/longest-continuous-increasing-subsequence/

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
//#include <bits/stdc++.h>

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i =0, j=1;
        int N = nums.size();
        int lcisLength = -1;
        while(i<N && j<N){
            if(nums[j]>nums[j-1]){
                j++;
                if(j==N) lcisLength = max(lcisLength, j-i);
            }else{
                lcisLength = max(lcisLength, j-i);
                i++;
                if(i==j) j++;
            }
        }
        return lcisLength != -1? lcisLength: j-i;
    }
};
