#include <cstring>
#include <iostream>
using namespace std;

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

void printMatrix(int** matrix, int M, int N){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(j<N-1) cout<<matrix[i][j]<<" ";
            else cout<<matrix[i][j];
        }
        cout<<endl;
    }
}
