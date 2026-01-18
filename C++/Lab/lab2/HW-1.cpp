#include<iostream>
#include<cmath>
using namespace std;
class ComplexNumber
{
private:
    double real,img;
public:
    ComplexNumber(double r,double i):real(r),img(i){}

    ComplexNumber():real(0),img(0){}
    ComplexNumber(ComplexNumber &c):real(c.real),img(c.img){}
    ~ComplexNumber(){}
    void print();
    void mag();
    void add(ComplexNumber &c){
        real+=c.real;
        img+=c.img;

        if (img < 0)
        {

            cout << " The Complex number is : " << real << img << "i";
        }
        else
        {
            cout << " The Complex number is : " << real << "+" << img << "i";
        }
    }
};
void ComplexNumber::print()
{
    if (img < 0)
    {

        std::cout << " The Complex number is : " << real << img << "i";
    }
    else
    {
        std::cout << " The Complex number is : " << real << "+" << img << "i";
    }
}
void ComplexNumber::mag()
{
   double mag = sqrt(real*real + img*img);
   cout<<"Magnitude is "<< mag<< endl;

}

int main()
{
    double r1,i1,r2,i2;
    cout<<"Enter real and imaginary part of first complex number: ";
    cin>>r1>>i1;
    ComplexNumber c1(r1,i1);
    cout<<"Enter real and imaginary part of second complex number: ";
    cin>>r2>>i2;
    ComplexNumber c2(r2,i2);
    cout<<"First ";
    c1.print();
    cout<<endl;
    c1.mag();
    cout<<"Second ";
    c2.print();
    cout<<endl;
    c2.mag();
    cout<<"After Addition: ";
    c1.add(c2);
    cout<<endl;
    return 0;
}

