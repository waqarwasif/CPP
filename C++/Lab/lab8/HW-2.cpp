#include<iostream>
using namespace std;

class Matrix{
    int mat[2][2];
    public:
    Matrix(int a[4]){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                mat[i][j]=a[i*2+j];
            }
        }
    }
    void display(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    friend Matrix operator+(Matrix &a,Matrix &m){
        int temp[4];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp[i*2+j]=a.mat[i][j]+m.mat[i][j];
            }
        }
        return Matrix(temp);
    }
    friend Matrix operator-(Matrix &a,Matrix &m){
        int temp[4];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp[i*2+j]=a.mat[i][j]-m.mat[i][j];
            }
        }
        return Matrix(temp);
    }
    
};

int main()
{
    int a[4] = {1, 2, 3, 4};
    int b[4] = {5, 6, 7, 8};

    Matrix A(a), B(b);

    cout << "Matrix A:" << endl;
    A.display();
    cout << "Matrix B:" << endl;
    B.display();

    cout << "\nA + B:" << endl;
    (A + B).display();
    cout << "\nA - B:" << endl;
    (A - B).display();

    return 0;
}