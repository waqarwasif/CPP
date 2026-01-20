#include <iostream>
#include <cstring>
using namespace std;
class balance {double cur_bal;
 char name[80];
public:
balance(double n, char *s) {
cur_bal = n;
 strcpy(name, s);
}
~balance() {
cout << "Destructing ";
 cout << name << "\n";
}
void get_bal(double &n, char *s) {
n = cur_bal;
 strcpy(s, name);
}
};
int main()
{
 balance *p;
 char s[80];
 double n;
 p = new balance(12387.87, "Ralph Wilson");
 p->get_bal(n, s);
 cout << s << "'s balance is: " << n;
 cout << "\n";
 delete p;
 return 0;
}