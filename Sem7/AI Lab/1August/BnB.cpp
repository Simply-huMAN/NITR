#include <bits/stdc++.h>
using namespace std;

bool checkRedundantMatrix(vector<vector<int>> &matrix, int N){
    int rowZeros=0, colZeros=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(matrix[i][j]==0) rowZeros++;
        }
        for(int j=0;j<N;j++){
            if(matrix[j][i]==0) colZeros++;
        }
    }
    if(rowZeros==N || colZeros==N) return true;
    return false;
}

void PrintMatrix(vector<vector<int>> &matrix, int N){
    cout << "Matrix: \n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void branchAndBoundApproach(vector<vector<int>> &matrix, int N, vector<int> &path){

    int allRowMin=0,k=N;
    while(k--){
        // find mimimum for each row
        for(int i=0;i<N;i++){
            int rowMin=INT_MAX;
            for(int j=0;j<N;j++){
                if(matrix[i][j]<rowMin) rowMin=matrix[i][j];
            }
            allRowMin+=rowMin;
            //update matrix
            for(int j=0;j<N;j++){
                if(matrix[i][j]!=INT_MAX) matrix[i][j]-=rowMin;
            }
        }
        PrintMatrix(matrix,N);

        //find minimum for each col
        for(int i=0;i<N;i++){
            int colMin=INT_MAX;
            for(int j=0;j<N;j++){
                if(matrix[j][i]<colMin) colMin=matrix[j][i];
            }
            allRowMin+=colMin;
            for(int j=0;j<N;j++){
                if(matrix[j][i]!=INT_MAX) matrix[j][i]-=colMin;
            }
        }
        PrintMatrix(matrix,N);
        cout << "Penalty: " << allRowMin;

        //find penalty for each zero
        map<pair<int,int>,int> mp;
        int maxPenalty=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j]==0) mp[{i,j}]=0;
            }
        }
        for(auto &i:mp){
            int rowPenalty=INT_MAX, colPenalty=INT_MAX;
            for(int j=0;j<N;j++){
                int data = matrix[i.first.first][j];
                if(j!=i.first.second && data<rowPenalty) rowPenalty=data;
            }
            for(int j=0;j<N;j++){
                int data = matrix[j][i.first.second];
                if(j!=i.first.first && data<colPenalty) colPenalty=data;
            }
            i.second=rowPenalty+colPenalty;
            if(rowPenalty+colPenalty>maxPenalty) maxPenalty=rowPenalty+colPenalty;
        }
        cout << endl;
        for(auto &i:mp){
            cout << i.first.first << "," << i.first.second << " : " << i.second << endl;
        }
        cout << "maxPenalty: " << maxPenalty << endl;
        allRowMin+=maxPenalty;
        //remove row and col elements corresponding to maxPenalty
        pair<int,int> maxPenaltyIndex;
        for(auto &i:mp){
            if(i.second==maxPenalty){ maxPenaltyIndex={i.first.first,i.first.second}; break; }
        }
        for(int i=0;i<N;i++){ 
            matrix[maxPenaltyIndex.first][i]=INT_MAX;
        }
        for(int i=0;i<N;i++) matrix[i][maxPenaltyIndex.second]=INT_MAX;
        path.push_back(maxPenaltyIndex.second);

        cout << "penalty: " << allRowMin << endl;
    }
}

int main(){
    //Weigt matrix
    int N=5;
    vector<vector<int>> matrix(N,vector<int>(N));
    vector<int> path;
    matrix = {
        {INT_MAX,600,1000,1900,1100},
        {600,INT_MAX,1900,1900,1500},
        {1000,1900,INT_MAX,1700,1200},
        {1900,1900,1700,INT_MAX,1900},
        {1100,1500,1200,1900,INT_MAX}
    };
    // cout << "Enter data: ";
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++) cin >> matrix[i][j];
    // }
    branchAndBoundApproach(matrix,N,path);
    cout << "Path: ";
    for(int &i:path) cout << i << " ";
}