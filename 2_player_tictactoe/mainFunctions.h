#include "mainClasses.h"

void gameplay(Game &game);
void game_check(int statusX, int status0, int play_count);

void gameplay(Game &game){
    int xx, yx, x0, y0;

    // X plays
    cout<<game.getX()<<" plays: "<<endl;
    cout<<"Row: ";
    cin>>xx;
    cout<<"Column: ";
    cin>>yx;
    game.setValue(xx,yx,'X');
    game.printGrid();

    // 0P plays
    cout<<game.get0()<<" plays: "<<endl;
    cout<<"Row: ";
    cin>>x0;
    cout<<"Column: ";
    cin>>y0;
    game.setValue(x0,y0,'0');
    game.printGrid();
}
void game_check(Game game, int statusX, int status0, int play_count){
    if ((statusX>0) && (status0 == 0)){
        cout<<game.getX()<<" Wins!!"<<endl;
    }
    if ((statusX == 0) && (status0>0)){
        cout<<game.get0()<<" Wins!!"<<endl;
    }
    if ((statusX == 0) && (status0 == 0) && (play_count>=7)){
        cout<<"Game Tied"<<endl;
    }
}
