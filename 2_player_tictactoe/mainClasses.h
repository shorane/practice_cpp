
#include<iostream>
#include<string>
using namespace std;

class Game
{
        char grid[4][4];
        string userX, user0;
    public:
        Game();
        void setValue(int x, int y, char valIn);
        void setNameX(string namexIn);
        void setName0(string name0In);
        string getX();
        string get0();
        char getValue(int x, int y);
        void printGrid();
        int checkWins(char checker, int play_count);
};

Game::Game()
{
    for (int i = 0 ; i<4 ; i++){
        for (int j = 0 ; j<4 ; j++){
            grid[i][j] = '-';
    }
}
}
void Game::setValue(int x, int y, char valIn)
{
     grid[x][y] = valIn;
}
void Game::setNameX(string namexIn){
    userX = namexIn;
}
void Game::setName0(string name0In){
    user0 = name0In;
}
string Game::getX(){
    return userX;
}
string Game::get0(){
    return user0;
}

void Game::printGrid()
{
    for (int i = 0 ; i<4 ; i++){
        cout<<endl;
        for (int j = 0 ; j<4 ; j++){
            cout<<grid[i][j]<<"  ";
    }
    }
    cout<<endl;
}

char Game::getValue(int x, int y)
{
     return grid[x][y];
}

int Game::checkWins(char checker, int play_count){
    int fleg = 0;
    for (int i = 0; i<4 ; i++){
        if ((grid[i][0] == checker)&&(grid[i][1]==checker)&&(grid[i][2]== checker) && (grid[i][3] == checker)){
            fleg = 1;
        }}
    for (int i = 0; i<4 ; i++){
        if ((grid[0][i] == checker)&&(grid[1][i]==checker)&&(grid[2][i]==checker) && (grid[3][i]==checker)){
            fleg = 2;
        }}
if ((grid[0][0] == checker) &&
    (grid[1][1] == checker) &&
    (grid[2][2] == checker) &&
    (grid[3][3] == checker))
    {fleg = 3;}

if ((grid[0][3] == checker) &&
    (grid[1][2] == checker) &&
    (grid[2][1] == checker) &&
    (grid[3][0] == checker))
    {fleg = 3;}

    if (play_count == 7){
        fleg = 4;
    }
    return fleg;

}
