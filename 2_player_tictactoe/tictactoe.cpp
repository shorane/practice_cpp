#include "mainFunctions.h"


int main(){
    int statusX = 0, status0 = 0;
    int play_count = 0;
    string namex, name0;

    Game game1;
    cout<<"Grid initialized!!"<<endl;
    game1.printGrid();

    // Get names of the players
    cout<<"What is the name of the first user?"<<endl;
    cin>>namex;
    cout<<namex<<endl;
    cout<<"User "<<namex<<" plays with X"<<endl;

    cout<<"What is the name of the second user?"<<endl;
    cin>>name0;
    cout<<name0<<endl;
    cout<<"User "<<name0<<" plays with 0"<<endl;

    //Store names
    game1.setNameX(namex);
    game1.setName0(name0);

    // take input
    while ((statusX == 0) && (play_count<8) && (status0 == 0)){
        gameplay(game1);         // take input

        statusX = game1.checkWins('X', play_count);
        if(statusX>0){break;}
        status0 = game1.checkWins('0', play_count);
        play_count++;
    }
    game_check(game1, statusX, status0, play_count);


    return 0;
}


