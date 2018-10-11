# include <iostream>
# include <fstream>
using namespace std;

// create testcase.txt

int main(){
    ofstream fout("matrix.data");
    int row,col;
    cout << "Row: ";
    cin >> row;
    fout << row;
    cout << "Col: ";
    cin >> col;
    fout << ' ';
    fout << col;
    fout << "\n";
    int a,b;
    a=4;
    int i,j;
    for(i=0;i<row/2;++i){
        b=a;
        for(j=0;j<col/2;++j){
            fout << b << ' ';
            b++;
        }
        b=b-2;
        for(j=j;j<col;++j){
            fout << b << ' ';
            b--;
        }
        a++;
        fout << "\n";
    }
    a=a-2;
    for(i=i;i<row;++i){
        b=a;
        for(j=0;j<col/2;++j){
            fout << b << ' ';
            b++;
        }
        b=b-2;
        for(j=j;j<col;++j){
            fout << b << ' ';
            b--;
        }
        a--;
        fout << "\n";
    }
    fout.close();
    cout << "matrix.data genarated." << endl;
}
