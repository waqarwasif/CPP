#include<iostream> 
using namespace std;

class Player {
    string name;
    int rating;
public:
    Player(string n, int r) : name(n), rating(r) {}
    Player() : name(""), rating(0) {}

    string getName() {
        return name;
    }
    int getRating() {
        return rating;
    }


};

class Team {
    string teamName;
    Player *players[10];
    int pcount;
    public:
    Team(string tn) : teamName(tn), pcount(0) {
        for (int i = 0; i < 10; i++) {
            players[i] = nullptr;
        }
    }
    void addPlayer(Player *p){
        if(pcount < 10){
            players[pcount++] = p;
        }
        else{
            cout<<"Team is full, cannot add more players."<<endl;
        }
    }    

    void RemovePlayer(string name){            // [p1,p2,p3,p4,null....,...]
        for(int i=0;i<pcount;i++){             // [ ahad, shahmeer,raza,saad,nullptr,nullptr]
            if (players[i]!= nullptr && players[i]->getName()==name){
                for(int j=i;j<pcount-1;j++){
                    players[j] = players[j+1]; // shift left 
                    
                }
                players[--pcount]= nullptr;
                return;
            }
        }
    }

    void showRoster() const
    {
        cout << "Team: " << teamName << "\n";
        for (int i = 0; i < pcount; i++)
            cout << "  " << players[i]->getName()
                 << " (rating: " << players[i]->getRating() << ")\n";
    }
};

int main()
{
    Player p1("Alice", 90);
    Player p2("Bob", 85);
    Player p3("Carol", 92);

    Team t1("Alpha");
    Team t2("Beta");

    t1.addPlayer(&p1);
    t1.addPlayer(&p2);
    t2.addPlayer(&p2);
    t2.addPlayer(&p3);

    t1.showRoster();
    t2.showRoster();

    t1.RemovePlayer("Bob");
    cout << "\nAfter Bob leaves Alpha:\n";
    t1.showRoster();
}