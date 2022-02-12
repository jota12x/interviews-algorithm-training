//Based on CP4, Exercise 2.2.1.3, problem 7
// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <iomanip>
#include <unordered_map>
#include <map>
#define rep(i,n) for(int=0;i<(n);++i);
using namespace std;
using ll = long long;
using P = pair<int,int>;


//NOTE: Setting an array for all the possible values won't work because of memory limits!
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int,int> counts;
        int solution;
        for(int i=0;i<N;i++){
            counts[nums[i]]++;
        }
        for(int i=0;i<N;i++){
            if(counts[nums[i]]>N/2){
                solution = nums[i];
            }
        }
        return solution;
    }
};
