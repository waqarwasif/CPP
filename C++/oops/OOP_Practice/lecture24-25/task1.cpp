/*
The "Smart Home Device"
•Base Class 1: Speaker (method: playMusic())
•Base Class 2: Clock (method: showTime())
Task:
1. Create a derived class SmartAlarm.
2. Add a method setAlarm() in the derived class.
3.Challenge: If both Speaker and Clock have a volume attribute, how do you
initialize them in the SmartAlarm constructor without causing a conflict?
*/
#include <iostream>
using namespace std;


class Speaker{
    int volume;

    public:
    Speaker(int v):volume(v){}
    void play(){
        cout<<"Playing"<<endl;

    }

};

class Clock{
    int volume;

    public:
    Clock(int v):volume(v){}
    void showTime(){
        cout<<"Showing Time...";
    }

};

class SmartAlarm: public Speaker,public Clock{
    public:
    SmartAlarm(int v1,int v2):Speaker(v1),Clock(v2){}
    void setAlarm(){
        cout<<"Setting Alarm";
    }
};

int main(){
    SmartAlarm sa(2,2);
}