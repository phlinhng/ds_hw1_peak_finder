#include <iostream>
#include <fstream>
using namespace std;

struct answer{
    int peak_num;
    int peak_r[100];
    int peak_c[100];
};

int main(){
    ifstream fin;
    fin.open("matrix.data");
    if(!fin) return 1;
    int row,col;
    fin >> row;
    fin >> col;
    int matrix[row][col];
    int i,j;
    for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            fin >> matrix[i][j];
        }
    }
    fin.close();
    int result[row][col];
     for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            if(matrix[i][j]>matrix[i+1][j] && matrix[i][j]>matrix[i-1][j] 
            && matrix[i][j]>matrix[i][j+1] && matrix[i][j]>matrix[i][j-1]){
                result[i][j]=1;
            }
            else result[i][j]=0;
        }
    }
    /*
    cout << "Result Matrix:"<<endl;
    for(i=0;i<row;++i){
        for(j=0;j<col;++j){
            cout << result[i][j];
            cout << ' ';
        }
        cout << "\n";
    }
    */
    ofstream fout;
    fout.open("final.peak");
    struct answer ans;
    int peak_no=0;
    for(i=0;i<row;++i){
        for(j=0;j<row;++j){
            if(result[i][j]==1){
                ans.peak_r[peak_no]=i+1;
                ans.peak_c[peak_no]=j+1;
                peak_no++;
            }
        }
    }
    ans.peak_num=peak_no;
    fout << ans.peak_num;
    fout << "\n";
    for(i=0;i<peak_no;++i){
        fout << ans.peak_r[i] << ' ' << ans.peak_c[i];
        fout << "\n";
    }
    fout.close();
    return 0;
}