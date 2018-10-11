#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution{
    public:
    void InputData();
    void FindPeak();
    void PrintResult();
    private:
    int row,col;
    vector<vector<int>> mat;
    vector<int> ans_row;
    vector<int> ans_col;
    vector<int> peak_row;
    vector<int> peak_col;
};

void Solution::FindPeak(){
    int i,j;
    for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            if (mat[i][j] >= mat[i][j+1] && mat[i][j] >= mat[i][j-1]){
                ans_row.push_back(i);
                ans_col.push_back(j);
            }
        }
    }
    for(i=0;i<ans_row.size();++i){
        if (mat[ans_row[i]][ans_col[i]] >= mat[ans_row[i]+1][ans_col[i]] && 
        mat[ans_row[i]][ans_col[i]] >= mat[ans_row[i]-1][ans_col[i]]){
            peak_row.push_back(ans_row[i]);
            peak_col.push_back(ans_col[i]);
        }
    }
}

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