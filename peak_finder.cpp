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
    vector< vector<int> > mat;
    vector<int> temp_row;
    vector<int> temp_col;
    vector<int> peak_row;
    vector<int> peak_col;
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
    int i,j;
    for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            if(j==0){
                if(mat[i][j]>=mat[i][j+1]){
                    temp_row.push_back(i);
                    temp_col.push_back(j);
                }
            }
            else if(j==col-1){
                if(mat[i][j]>=mat[i][j-1]){
                    temp_row.push_back(i);
                    temp_col.push_back(j);
                }
            }
            else if(mat[i][j]>=mat[i][j+1] && mat[i][j]>=mat[i][j-1]){
                temp_row.push_back(i);
                temp_col.push_back(j);
            }
        }
    }
    for(i=0;i<temp_row.size();++i){
        if(temp_row[i]==0){
            if(mat[temp_row[i]][temp_col[i]]>=mat[temp_row[i]+1][temp_col[i]]){
                peak_row.push_back(temp_row[i]);
                peak_col.push_back(temp_col[i]);
            }
        }
        else if(temp_row[i]==row-1){
            if(mat[temp_row[i]][temp_col[i]]>=mat[temp_row[i]-1][temp_col[i]]){
                peak_row.push_back(temp_row[i]);
                peak_col.push_back(temp_col[i]);
            }
        }
        else if(mat[temp_row[i]][temp_col[i]]>=mat[temp_row[i]+1][temp_col[i]] &&
        mat[temp_row[i]][temp_col[i]]>=mat[temp_row[i]-1][temp_col[i]]){
                peak_row.push_back(temp_row[i]);
                peak_col.push_back(temp_col[i]);
        }
    }
}

void Solution::PrintResult(){
    cout << peak_row.size() << endl;
    for(int i=0;i<peak_row.size();++i){
        cout << peak_row[i] +1 << ' ' << peak_col[i] +1 << endl;
    }
}

int main(){
    Solution sol;
    sol.InputData();
    sol.FindPeak();
    sol.PrintResult();
    return 0;
}