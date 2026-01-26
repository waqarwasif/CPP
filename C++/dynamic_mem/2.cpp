#include<iostream>
#include<cstring>

using namespace std;

class String{
    private: 
    char* str;
    public: 
    static int count;
    String(char* s){
        int len = strlen(s);
        str = new char[len+1];
        strcpy(str,s);
    }
    ~String(){
        count++;
        cout<< "Deleting a str for obj " << count;
        delete [] str;
    }
    void display(){
        cout<< str<< endl;
    }

};

int String::count=0;

int main(){
    String s1("heyy hhhhh");
    s1.display();
    String s2("Byeeeeeee");
    s2.display();
}