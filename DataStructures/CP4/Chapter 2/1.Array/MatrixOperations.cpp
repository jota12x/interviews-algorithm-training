#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int=0;i<(n);++i);
using namespace std;

//Exercise 4
void printMatrix(int matrix[][4], int M, int N){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(j<N-1) cout<<matrix[i][j]<<" ";
            else cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

void printMatrixDoublePointer(int** matrix, int M, int N){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(j<N-1) cout<<matrix[i][j]<<" ";
            else cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

//vectors for matrixes.
int** initMatrix(int M, int N){
    int** matrix;
    matrix = new int*[N];
    for(int i=0;i<M;i++){
        matrix[i] = new int[N];
        for(int j=0;j<N;j++){
            matrix[i][j]=   0;
        }
    }
    return matrix;
}


void transpose(int matrix[][4], int M, int N){
    for(int i=0;i<M;i++){
        for(int j=i+1;j<N;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    cout<<"Transposed matrix"<<endl;
    printMatrix(matrix, M, N);
}

void rotate90(int matrix[][4], int M, int N, bool clockwise){
    int ** rotatedMatrix = initMatrix(M,N);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(clockwise) rotatedMatrix[j][N-i-1] = matrix[i][j];
            else rotatedMatrix[N-j-1][i] = matrix[i][j];
        }

    }
    cout<<"Matrix rotated 90 degrees "<<(clockwise? "clockwise": "counter-clockwise")<<endl;
    printMatrixDoublePointer(rotatedMatrix, M, N);
}

void mirrorMatrixVertically(int matrix[][4], int M, int N){
    int middle = int(ceil(M/2));
    for(int i=0;i<middle;i++){
        for(int j=0;j<N;j++){
            swap(matrix[i][j], matrix[i+middle][j]);
        }
    }
    cout<<"Matrix mirrored by the x-axis"<<endl;
    printMatrix(matrix, M, N);
}

void mirrorMatrixHorizontally(int matrix[][4], int M, int N){
    for(int i=0;i<M;i++){
        int middle = int(ceil(N/2));
        for(int j=0;j<middle;j++){
            swap(matrix[i][j], matrix[i][j+middle]);
        }
    }
    cout<<"Matrix mirrored by the y-axis "<<endl;
    printMatrix(matrix, M, N);
}
int main(){
    int matrix[4][4]= {{1,2,3,4}, {2,3,4,5},{3,4,5,6},{8,1,2,3}};
    cout<<"Original matrix"<<endl;
    printMatrix(matrix,4,4);
    // transpose(matrix, 4, 4);
    // rotate90(matrix, 4, 4, false);
    // rotate90(matrix, 4, 4, true);
    // mirrorMatrix(matrix, 4, 4, true);
    // mirrorMatrixHorizontally(matrix, 4, 4);
    mirrorMatrixVertically(matrix, 4, 4);
}
