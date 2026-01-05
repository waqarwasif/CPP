#include<iostream>
using namespace std;

#include "header.h"  

int main() {
    // Two methods of calling functions by reference
    int score1 = 50;
    int score2 = 70;
    lifeup(&score1); // Passing address

    cout << "Score1 after lifeup: " << score1 << endl; // Should print 150

    lifeup_ref(score2); // Passing by reference
    cout << "Score2 after lifeup_ref: " << score2 << endl; // Should print 170
    add(score1, score2); // Using template function
    cout << "Sum of score1 and score2: " << add(score1, score2) << endl; // Should print 320

}