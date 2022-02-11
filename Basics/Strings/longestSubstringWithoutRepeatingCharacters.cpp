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
#define Hash map<int,int>


//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//There are three main approaches

//O(n^3)
// int areUniqueCharacters(string str, int i, int j){
//     bool visited[256];
//     fill_n(visited, 256, false);
//     for(int k=i;k<=j;k++){
//         if(visited[str[k]]) return false;
//         else visited[str[k]]=true;
//     }
//     return true;
// }
// int lengthOfLongestSubstring(string str) {
//     int maxLength = 0;
//     int N = str.length();
//     for(int i=0;i<N;i++){
//         for(int j=i;j<N;j++){
//             if(areUniqueCharacters(str,i,j))
//                 maxLength = max(maxLength, j-i+1);
//         }
//     }
//     return maxLength;
// }
// int lengthOfLongestSubstring(string str) {
//     int maxLength = 0;
//     int N = str.length();
//     for(int i=0;i<N;i++){
//         bool visited[256];
//         fill_n(visited,256,false);
//         for(int j=i;j<N;j++){
//             if(visited[str[j]]) break;
//             else{
//                 visited[str[j]]=true;
//                 maxLength = max(maxLength, j-i+1);
//             }
//         }
//         visited[str[i]]=false;
//     }
//     return maxLength;
// }

//O(n) bounded
int lengthOfLongestSubstring(string str) {
        int maxLength = 0;
        int N = str.length();
        Hash hashTable;
        int i=0;
        int j=i;
        while(i<N && j<N){
            if(hashTable[str[j]]){
                hashTable.erase(str[i]);
                i++;
            }else{
                hashTable[str[j]]=true;
                j++;
                maxLength = max(maxLength, j-i);
            }
        }
        return maxLength;
}
int main(){
    int ans = lengthOfLongestSubstring("abcabcbb");
    cout<<"ans: "<<ans<<endl;
}
