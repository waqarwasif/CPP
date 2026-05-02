// multiple arguments 
#include<iostream>
using namespace std;

template<class atype>
int find(atype *array, atype value, int size){
    for(int i = 0;i<size;i++){
        if(array[i]==value)
        return i;
    }
    return -1;
}

int main(){
    char a1[] = "how are you";
    int arr[] = {1,2,3,4,5,6,7};
    cout<<"\n o in a1 at index:"<<find(a1,'o',12);
    cout<<"\n 3 in a1 at index:"<<find(arr,3,7);
    return 0;
}