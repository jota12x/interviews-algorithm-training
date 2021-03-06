// This program is based on CH 7.1 of [LEV2012].
// The idea is to sort an array of elements by counting its constituents.
// Keywords: input-enhancement
// References: [LEV2012] [HALLIM 2021]

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

//ASK why is it necessary to pass an array N: https://stackoverflow.com/questions/25260079/sizeof-operator-returns-size-of-pointer-instead-of-array
// TODO: move to Utils function
void print(int arr[], int N){
    for(int i=0;i<N-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[N-1]<<endl;
}
void printVector(vector<int> arr, int N){
	for(int i=0;i<N;i++){
		cout<<(i!=0?" ":"")<<arr[i];
	}
	cout<<endl;
}

// Complexity
//  - O(n^2) comparisons.
//  - O(n) linear extra space
// + minimum number of key moves (just one per each element)
void naiveCountingSort(int arr[], int N){

    int counts[N];
    int sorted_arr[N];
    memset(counts, 0, sizeof(counts));
    memset(sorted_arr, -1, sizeof(sorted_arr));

    //preprocessing
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]>arr[j]){
                counts[i]++;
            }else{
                counts[j]++;
            }
        }
    }
    for(int i=0;i<N;i++){
        int position = counts[i];
        if(sorted_arr[position]>0){
            sorted_arr[position+1] = arr[i]; // This line allows for duplicates
        }else{
            sorted_arr[position] = arr[i];
        }
    }
    print(sorted_arr, N);
}

//See UVA11462 - Age Sort for a concrete example
void betterCountingSort(int arr[], int N, int l, int u){
    int counts[u+2];

    memset(counts, 0, sizeof(counts));

    for(int i=0;i<N;i++){
			counts[arr[i]]++;
	}
    int arr_index = 0;
    // overwrite the previous array
    for(int i=0;i<u-l;i++){
        for(int j=0;j<counts[i];j++){
            arr[arr_index++]= i;
        }
    }
     print(arr, N);
}

//Explanation is on [LEV2012], the cumulative distributions determine the last position of the element in the array.
//Complexity:
// O(N + K) comparisons, where K is the range of the values.
// O(N) extra espace
//NOTE: This algorithm is stable, for another explanation see [HALIM2021] page 60.
void distributionCountingSort(int arr[], int N, int l, int u){
    int freqDistrib[u-l+1]; // NOTE: we can reduce the size of the array by just taking the range of values and transforming the index. (0->l, u-> u-l)
    int freq[u-l+1];
    int sortedArr[N+1];

    memset(freq, 0, sizeof(freq));
    memset(freqDistrib, 0, sizeof(freqDistrib));

    for(int i=0;i<N;i++){
        freq[arr[i]-l]++;
    }
    for(int i=0;i<=u-l;i++){
        if(i>0) freqDistrib[i] = freqDistrib[i-1] + freq[i];
        else freqDistrib[i] = freq[i];
    }
    for(int i=N-1;i>=0;i--){
        int freqIndex = arr[i]-l;
        sortedArr[freqDistrib[freqIndex] - 1] = arr[i];
        freqDistrib[freqIndex]--;
    }
    print(sortedArr, N);
}

int main(){
    int arr[] = {62,31,84,31,96,19,47};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout << "naive counting sort"<<endl;
    naiveCountingSort(arr, N);
    cout << "better-counting sort"<<endl;
    betterCountingSort(arr, N, 0, 100);
    cout << "distribution counting sort"<<endl;
    distributionCountingSort(arr, N, 19, 96);
}
