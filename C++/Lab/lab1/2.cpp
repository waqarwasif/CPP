#include<iostream>
// #include<vector>
// #include<string>
 

class ComplexNumber{

    int real;
    int img;
    public:
        void print ();
        void setReal(int r){
                real = r;
            }
            
            void setImg(int i){
                img = i;
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

    std :: cout << "start";
    ComplexNumber n1 ;
    n1.setReal(4);
    n1.setImg(-3);
    n1.print();
    

}