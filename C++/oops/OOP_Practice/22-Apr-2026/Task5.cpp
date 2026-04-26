#include<iostream>
using namespace std;

class Matrix
{
    int arr[2][2];
    public:
    Matrix() = default;
    Matrix(int a, int b, int c, int d){
        arr[0][0] = a;
        arr[0][1] = b;
        arr[1][0] = c;
        arr[1][1] = d;
    }

    friend Matrix operator+(Matrix &m1, Matrix &m2)
    {
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                m1.arr[i][j] = m2.arr[i][j];
            }
        }
    }
    friend bool operator==(Matrix &m1, Matrix &m2){
        return ((m1.arr[0][0] * m1.arr[1][1] - m1.arr[0][1] * m1.arr[1][0]) ==
                (m2.arr[0][0] * m2.arr[1][1] - m2.arr[0][1] * m2.arr[1][0]));
    }
    friend bool operator>(Matrix &m1, Matrix &m2){
        return ((m1.arr[0][0] * m1.arr[1][1] - m1.arr[0][1] * m1.arr[1][0]) >
                (m2.arr[0][0] * m2.arr[1][1] - m2.arr[0][1] * m2.arr[1][0]));
    }
};

int main()
{
    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);

    Matrix m3 = m1 + m2;

    if (m1 == m2)
    {
        cout << "Matrices have equal determinants." << endl;
    }
    else if (m1 > m2)
    {
        cout << "Matrix 1 has a larger determinant." << endl;
    }
    else
    {
        cout << "Matrix 2 has a larger determinant." << endl;
    }

    return 0;
}