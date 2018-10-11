#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution{
    public:
    void InputData();
    int FindPeak;
    void PrintResult();
    private:
    int row,col;
    vector<vector<int>> mat;
};

void Solution::InputData(){
    ifstream fin;
    fin.open("matrix.data");
    fin >> row;
    fin >> col;
    mat.resize(row,vector<int>(col,0));
    int i,j;
    for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            fin >> mat[i][j];
        }
    }
    fin.close();
}

void Solution::PrintResult(){
    int i,j;
    for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]){
    Solution sol;
    sol.InputData();
    sol.PrintResult();
    return 0;
}