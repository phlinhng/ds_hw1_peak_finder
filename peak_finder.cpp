#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

# define INF 100000000

class Solution{
    public:
    void InputData();
    void FindPeak();
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

void Solution::FindPeak(){
/*
looking for a better way
*/
}


void Solution::PrintResult(){
    cout << peak_row.size() << endl;
    for(int i=0;i<peak_row.size();++i){
        cout << peak_row[i] << peak_col[i] << endl;
    }
}

int main(){
    Solution sol;
    sol.InputData();
    sol.FindPeak();
    sol.PrintResult();
    return 0;
}