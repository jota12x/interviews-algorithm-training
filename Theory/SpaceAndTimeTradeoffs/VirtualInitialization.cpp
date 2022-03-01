
// This program is based on Exercise 7 of Section 7.1 by [LEV2012]

/*The input goes as follows.
First you have to read the number of items.
Then, the input presents the list of variable assignments until -1 -1.

Finally you have the query section. Each query contains an index of th array
Print if the array has been initialized at that index, and if yes, also print the value.
//A -1 indicates the end of the input file

    N (number of items in the array)
    i1 v1 (arr[i1] = v1)
    i2 v2 (arr[i2] = v2)
    .....
    -1 -1 (end of variable assignments)
    q1
    q2
    ...
    -1 -1(end of queries)
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
using ll = long long;
using P = pair<int,int>;


void virtualInitialization(int N){
    int arr[N]; // array of initialized and uninitiliazed values.
    int positions[N]; // positions[k] contains the index of the kth initialization.
    int initNumbers[N]; // if A[i] was the kth element to be initialized, then initNumbers[i]=k.

    int initCount = 0;
    int inputIndex;
    int value;
    while(true){
        cin>>inputIndex>>value;
        if(inputIndex==-1 && value == -1) break;
        arr[inputIndex] = value;
        initNumbers[inputIndex] = initCount;
        positions[initCount] = inputIndex;
        initCount++;
    }

    int queryIndex;
    while(true){
        cin>>queryIndex;
        if(queryIndex == -1) break;
        if(initNumbers[queryIndex]>0 && initNumbers[queryIndex]< initCount
            && positions[initNumbers[queryIndex]]==queryIndex)
            cout<<"arr["<<queryIndex<<"] was initialized with "<<arr[queryIndex]<<"."<<endl;
        else cout<<"arr["<<queryIndex<<"] hasn't been initialized."<<endl;
    }
}


int main(){
    int N;

    cin>>N;

    virtualInitialization(N);
}
