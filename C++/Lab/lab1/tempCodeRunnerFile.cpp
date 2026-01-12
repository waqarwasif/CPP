#include<iostream>
// #include<vector>
// #include<string>

class ComplexNumber{

    int real;
    int img;
    public:
        ComplexNumber() {
            std::cout << "Complex Number Created" << std::endl;
        }
        void print ();
        void setReal(){
                std::cout<<"Enter real part "<<std::endl;
                std::cin >> real;
            }
            
            void setImg(){
                std::cout<<"Enter imaginary part "<<std::endl;
                std::cin >> img;
            }    

    private:
            

    protected:
        

};
void ComplexNumber::print()
    {
            if (img<0)
            {
                
                std::cout<<" The Complex number is : "<< real << img<<"i";
            }
            else{
                std::cout<<" The Complex number is : "<< real <<"+"<< img<<"i";

            }
}


int main(){

    ComplexNumber n1 ;
    n1.setReal();
    n1.setImg();
    n1.print();
    
}