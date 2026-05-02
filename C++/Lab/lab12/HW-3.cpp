#include <iostream>
using namespace std;

template <class Type>
class Matrix
{
    Type matrix[2][2];

public:
    Matrix() = default;
    Matrix(Type a, Type b, Type c, Type d)
    {
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }

    void Determinant()
    {
        cout << "Determinant is: " << (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]) << endl;
    }
    Type get(int i,int j){
        return matrix[i][j];
    }

    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                    cout << "[" << " " << matrix[i][j];
                if (j == 1)
                    cout << " " << matrix[i][j] << " ]\n";
            }
        }
    }
    Matrix<Type> operator+( const Matrix<Type> &m2)
    {

        Matrix<Type> temp;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp.matrix[i][j] = this->matrix[i][j] + m2.matrix[i][j];
            }
        }
        return temp;
        
    }
    
    Matrix<Type> operator-( const Matrix<Type> &m2)
    {
     
        Matrix<Type> temp;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp.matrix[i][j] = this->matrix[i][j] - m2.matrix[i][j];
            }
        }
        return temp;
        
    }
};


int main()
    {
        cout << "Matrix 1" << endl;
        Matrix<float> m1(5.5, 2.2, 1.1, 4.4);
        m1.display();
        m1.Determinant();
        cout << endl;

        cout << "Matrix 2" << endl;
        Matrix<float> m2(1.2, 0.5, 2.0, 3.1);
        m2.display();
        m2.Determinant();
        cout << endl;

        cout << "Addition" << endl;
        Matrix<float> m3 = m1 + m2;
        m3.display();
        cout << endl;

        cout << "Subtraction" << endl;
        Matrix<float> m4 = m1 - m2;
        m4.display();
        cout << endl;

        return 0;
    }

