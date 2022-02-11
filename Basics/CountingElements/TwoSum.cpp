
// Based on CP4, Exercise 2.2.1.3, problem 2 and 3.
// https://leetcode.com/problems/two-sum/

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
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hashTable;
        vector<int> solutions;
        //O(nlog(n))
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            //We check if the complement has already been seen
            if(hashTable.count(complement)){
                //The complement has already been checked, so we found the numbers
                int firstIndex = min(hashTable[complement],i);
                int secondIndex = max(hashTable[complement], i);
                solutions.push_back(firstIndex);
                solutions.push_back(secondIndex);
                break;
            }else{
                hashTable[nums[i]]=i;
            }
        }
        return solutions;
    }

};
