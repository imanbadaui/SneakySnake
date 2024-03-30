#ifndef SNAKE_H
#define SNAKE_H

#include<list>
#include<utility>
#include "Fruit.h"
#include "Directions.h"
#include"player_info.h"

class Fruit;

class Snake
{

public:
    Snake(int,int);
    void setXY(int,int);
    void getHead(int headX,int headY) const;
    char getHeadChar() const;
    char getTailChar() const;
    char print(int,int) const;
    void snake_dir (const Directions & dir,int rows,int columns);
    bool eat ( Fruit &fruit,Player_Info &playerint);
    bool dead();

private:
    char head, tail;
    int snake_length;
    std::list<std::pair<int,int>> snakeXY;
};

#endif // SNAKE_H
