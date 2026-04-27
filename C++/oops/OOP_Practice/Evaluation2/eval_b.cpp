#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

class Book{
    string title;
    int pages;

    public:
    Book():title("Unknown"),pages(0){}
    Book(string name,int pages):title(name),pages(pages){
        if(pages <= 0){
            throw logic_error("Pages cannot be less than or equal to zero");
        }
        if(title=="Unknown" || title == ""){
            throw logic_error("Book name Unknown or empty name is not allowed");
        }
        
    }
    string getname(){
        return title;
    }
    int getpages(){
        return pages;
    }
    void display(){
        cout<<getname()<<endl<<getpages()<<endl;
    }
};

class Librarian{
    string name;
    public:
    Librarian(string name):name(name){}
    string getname(){
        return name;
    }
    void display(){
        cout<<getname()<<endl;
    }
};

class Library{
    Book book[5];
    Librarian *lib;
    int bookcount;
    public:
    Library(Librarian *l):lib(l),bookcount(0){}
    void addBook(string name,int pages){
        if(bookcount==5){
            throw overflow_error("Max Books have been created already");
        }
        book[bookcount++] = Book(name,pages);

    }
    void display(){
        
        lib->display();
        for(int i=0;i<bookcount;i++){
            cout<<endl;
            book[i].display();
        }
    }

};

int main(){
    Librarian lib("Waqar");
    Library library(&lib);
    try{

        library.addBook("Book1",100);
        library.addBook("Book2",100);
        library.addBook("Book3",100);
        library.addBook("Book4",100);
        //library.addBook("",100); //for checking logical error
        // library.addBook("Book5",100); //for checking overflow error
    
        library.display();
    }
    catch (exception &e){
        cout<<e.what()<<endl;
    }

    return 0;
}