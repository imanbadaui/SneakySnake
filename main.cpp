#include <iostream>
#include "Snake.h"
#include "Fruit.h"
#include "Directions.h"
#include "Player_Info.h"
#include "GameControl.h"

using namespace std;


int main ()
{
    Snake sneakysnake{rows/2, columns/2};
    Directions dir = Directions::STOP;
    Fruit fruit{rows,columns};
    Player_Info player_one{"Emma"};
    GameControl  game;
    game.main_grid(sneakysnake, fruit,player_one);

    while (!sneakysnake.dead())
    {
        if(sneakysnake.eat(fruit,player_one))
            fruit.xyGenerator(rows,columns);

        game.key_directions(dir);
        sneakysnake.snake_dir(dir,rows,columns);

        game.edit_grid(sneakysnake,fruit,player_one,dir);
        game.game_speed(player_one);
    }

    cout<< "game over";

}
