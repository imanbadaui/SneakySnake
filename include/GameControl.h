#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#include "Directions.h"
#include "Snake.h"
#include "Fruit.h"
#include "Player_Info.h"

const int rows {30};
const int columns{30};

class GameControl
{
public:
    GameControl();
    void key_directions(Directions &dir);
    void main_grid (const Snake &snake,const Fruit &fruit, const Player_Info& player);
    void setCursorPosition(int x, int y);
    void edit_grid(Snake &snake,Fruit &fruit, Player_Info& player,Directions &dir);
    virtual ~GameControl();
    void game_speed(Player_Info& player);


    char grid[rows][columns];
};

#endif // GAMECONTROL_H
