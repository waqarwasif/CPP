#include<iostream>
#include<cstring>
using namespace std;

int main(){

    const char* str = "str is a pointer to this string ";
    int len = strlen(str);
    char *ptr;
    ptr = new char [len+1];

    strcpy(ptr,str);
    cout<<ptr;
    delete [] ptr;

    return 0 ;

}