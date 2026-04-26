#include<iostream>
using namespace std;

class Timer {
    int hours;
    int minutes;
    int seconds;
    int count;
    public:    
    Timer() : hours(0), minutes(0), seconds(0) , count(0) {}
    Timer(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    void tick(){
        count++;
        if(seconds == 59){
            seconds = 0;
            minutes_inc();
            return;
        }
        seconds++;
      }

      void minutes_inc(){
        if(minutes == 59){
            minutes = 0;
            hours_inc();
            return;
        }
        minutes++;
      }

      void hours_inc(){
        if(hours == 23){
            hours = 0;
            cout<< "  "<< count<< endl;
            throw (string) "Timer Overflow";

        }
        hours++;

      }

};

int main(){
    Timer t;
    try
    {
        while (1)
            t.tick();
    }
    catch (const string a)
    {
        cout << a;
    }
}

