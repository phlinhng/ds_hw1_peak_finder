#include <iostream>
#include <fstream>
using namespace std;

int FindPeak(int a[][],int RowNum ,int ColNum){
    int i,j,k;
    k=1;
    int temp[RowNum*ColNum][2];
    for (i=0;i<RowNum;++i){
        for (j=0;j<RowNum;++j){
            if(a[i][j]>=a[i][j+1] && a[i][j]>=a[i][j-1]){
                temp[k][0]=i;
                temp[k][1]=j;
                k++;
            }
        }
    }
    for (i=0;i<k;++i){
        if(a[ temp[k][0] ][ temp [k][1] ])>a[ temp[k][0] +1 ][ temp [k][1]  ] &&
        a[ temp[k][0] ][ temp [k][1] ])>a[ temp[k][0] -1 ][ temp [k][1]  ]){
            temp2[k][0]=temp[k][0];
            te
        }
    }
}

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